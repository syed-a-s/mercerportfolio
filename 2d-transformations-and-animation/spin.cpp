// Author : Syed Saadat

#include <vector>
#include <iostream>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
using namespace std;

#define WINDOW_MAX 1000
#define WINDOW_MIN 0
#define VIEWPORT_MAX 900
#define VIEWPORT_MIN 100
#define MAX 100

#define inf 1000000

struct Vertex {
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    float w = 0.0;
};

struct Triangle {
    Vertex a;
    Vertex b;
    Vertex c;
};

float scale = 1.0; float minScale = 0.45; float maxScale = 1000; float scale_speed = 0.05;
float DELTA_SPIN = 0.0; float SPIN  = 0.0; float CHANGE_SPIN = 1.0;
bool reflected = false;

bool show_triangles = false;
bool fill_triangles = false;

// clear screen
void clr() {
    printf("\033[2J\033[1;1H");
}

// print a menu
void PrintMenu() {
    clr();
    printf("The Translating, Rotating, Scaling, Tessellating Tree\n");
    printf("\tMouse Left in View Port       : Rotate CCW\n");
    printf("\tMouse Right in View Port      : Rotate CW\n");
    printf("\tMouse Left Outside View Port  : Scale Up\n");
    printf("\tMouse Right Outside View Port : Scale Down\n");
    printf("\tf                             : Draw Polygon Filled\n");
    printf("\tt                             : View Triangles for Tessellation\n");
    printf("\tl                             : Draw Polygon Filled with Tessellation\n");
    printf("\tr                             : Reflect Polygon\n");
    printf("\ti                             : Reset program\n");
    printf("\tq                             : Quit Program\n");
    printf("\t-----------------------------------------------\n");
}

// Print Vertex Struct
void PrintVertex(Vertex p) {
    printf("x: %f y: %f\n\n", p.x, p.y);
}

// Print Vector of Vertex Struct
void PrintVertices(vector<Vertex> vp) {
    for(int i = 0; i < vp.size(); i++)
        printf("%d - x: %f y: %f z: %f w: %f\n", i, vp[i].x, vp[i].y, vp[i].z, vp[i].w);
    printf("\n");
}

// Prints out a vector of triangles
void PrintTriangles(vector<Triangle> triangles) {
    cout << "\t" << "All triangles" << endl;
    for(int i = 0; i < triangles.size(); i++) {
        cout << "\t\t" << i << " " << triangles[i].a.x << " " << triangles[i].a.y << endl;
        cout << "\t\t" << i << " " << triangles[i].b.x << " " << triangles[i].b.y << endl;
        cout << "\t\t" << i << " " << triangles[i].c.x << " " << triangles[i].c.y << endl;
        cout << endl;
    }
}

// adds Vertex struct to a vector of Vertex structs
void AddVertex(Vertex newVertex, vector<Vertex> &vertices) {
    vertices.push_back(Vertex());
    vertices[vertices.size() - 1] = newVertex;
}

// add vertex x,y into vector of vertex structs
void AddVertex(float x, float y, vector<Vertex> &vertices) {
    vertices.push_back(Vertex());
    vertices[vertices.size() - 1].x = x;
    vertices[vertices.size() - 1].y = y;
    vertices[vertices.size() - 1].z = 0.0;
    vertices[vertices.size() - 1].w = 1.0;
}

// invert vector element position
void Invert(vector<Vertex> &vertices) {
    vector<Vertex> temp;

    for(int i = vertices.size() - 1; i >= 0; i--) {
        AddVertex(vertices[i], temp);
    }

    vertices.clear();
    vertices = temp;
}

// matrix vector multiplication
// pA is the transformation matrix
// pB is the x,y,z,w vector
void vmatm(int size, vector<float> &pA, vector<float> &pB) {
    int i, j;
    float temp[4];

    for(i = 0; i < 4; i++)
        temp[i] = 0.0;

    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            temp[i] += (pA.at(i * size + j) * pB.at(j));

    for(i = 0; i < size; i++)
        pB.at(i) = temp[i];  
}

// constructs translation matrix to translate along x, y, and z axes
// tm is our transformation matrix 
void buildTranslate(float x, float y, float z, vector<float> &tm) {
    tm.at( 0) = 1.0; tm.at( 1) = 0.0; tm.at( 2) = 0.0; tm.at( 3) =   x;
    tm.at( 4) = 0.0; tm.at( 5) = 1.0; tm.at( 6) = 0.0; tm.at( 7) =   y;
    tm.at( 8) = 0.0; tm.at( 9) = 0.0; tm.at(10) = 1.0; tm.at(11) =   z;
    tm.at(12) = 0.0; tm.at(13) = 0.0; tm.at(14) = 0.0; tm.at(15) = 1.0;
}

// constructs translation matrix to reflect polygon
void buildReflection(vector<float> &tm) {
    tm.at( 0) = -1.0; tm.at( 1) = 0.0; tm.at( 2) = 0.0; tm.at( 3) = 0.0;
    tm.at( 4) =  0.0; tm.at( 5) = 1.0; tm.at( 6) = 0.0; tm.at( 7) = 0.0;
    tm.at( 8) =  0.0; tm.at( 9) = 0.0; tm.at(10) = 1.0; tm.at(11) = 0.0;
    tm.at(12) =  0.0; tm.at(13) = 0.0; tm.at(14) = 0.0; tm.at(15) = 1.0;
}

// constructs translation matrix to rotate origin
// theta is the speed of the rotation 
// tm is our transformational matrix
void buildRotateZ(float theta, vector<float> &tm) {
    float phi;
    phi = theta * M_PI / 180.0;

    tm.at( 0) =  cos(phi); tm.at( 1) = sin(phi); tm.at( 2) = 0.0; tm.at( 3) = 0.0;
    tm.at( 4) = -sin(phi); tm.at( 5) = cos(phi); tm.at( 6) = 0.0; tm.at( 7) = 0.0;
    tm.at( 8) = 0.0;       tm.at( 9) = 0.0;      tm.at(10) = 1.0; tm.at(11) = 0.0;
    tm.at(12) = 0.0;       tm.at(13) = 0.0;      tm.at(14) = 0.0; tm.at(15) = 1.0;
}

// constructs translation matrix to change size of the polygon
// scale is the % size wanted for the polygon
// tm is the transformational matrix to update
void buildScale(float scale, vector<float> &tm) {
    tm.at( 0) = scale; tm.at( 1) = 0.0;     tm.at( 2) = 0.0;    tm.at( 3) = 0.0;
    tm.at( 4) = 0.0;   tm.at( 5) = scale;   tm.at( 6) = 0.0;    tm.at( 7) = 0.0;
    tm.at( 8) = 0.0;   tm.at( 9) = 0.0;     tm.at(10) = scale;  tm.at(11) = 0.0;
    tm.at(12) = 0.0;   tm.at(13) = 0.0;     tm.at(14) = 0.0;    tm.at(15) = 1.0;
}

// TM is the Transformation Matrix
// vp is a vector of struct vertex containing points of the arrow/tree
void applyTransformation(vector<Vertex> &vp, vector<float> &TM) {
    vector<float> temp(4);

    for(int i = 0; i < vp.size(); i++) {
        temp.at(0) = vp[i].x;
        temp.at(1) = vp[i].y;
        temp.at(2) = vp[i].z;
        temp.at(3) = vp[i].w;
        vmatm(4, TM, temp);
        vp[i].x = temp.at(0); 
        vp[i].y = temp.at(1); 
        vp[i].z = temp.at(2); 
        vp[i].w = temp.at(3); 
    }
}

void PipeLine(vector<Vertex> &vp) {
    vector<float> TransformationMatrix(16);
    float offset = 100.0;

    // Translate to Origin
    buildTranslate(offset, 0, 0.0, TransformationMatrix);
    applyTransformation(vp, TransformationMatrix);

    // Reflect Polygon
    if(reflected) {
        buildReflection(TransformationMatrix);
        applyTransformation(vp, TransformationMatrix);
    }

    // Scale the polygon
    buildScale(scale, TransformationMatrix);
    applyTransformation(vp, TransformationMatrix);

    // Perform the rotation operation
    buildRotateZ(SPIN, TransformationMatrix);
    applyTransformation(vp, TransformationMatrix);

    // Translate back to point
    buildTranslate(WINDOW_MAX / 2, WINDOW_MAX / 2, 0.0, TransformationMatrix);
    applyTransformation(vp, TransformationMatrix);
}

// generate points for the second octant of a circle
void MidpointCircle(vector<Vertex> &circle, int radius) {
    int x, y;
    float d;
    
    x = 0;
    y = radius;
    d = 5.0 / 4.0 - radius;

    AddVertex(x, y, circle);

    while(y > x) {
        if(d <= 0) {
            d += x * 2.0 + 3;
            x++;
        } else {
            d += (x - y) * 2.0 + 5;
            x++;
            y--;
        }
        AddVertex(x, y, circle);
    }
}

// generate circle octants for tree
void MakeTree(vector<Vertex> &tree, int radius) {
    MidpointCircle(tree, radius);
    vector<Vertex> new_tree;
    vector<Vertex> inv_circle = tree;
    Invert(inv_circle);

    // tree branch first half
    AddVertex(-inv_circle[0].x - 200, -inv_circle[0].y - 4, new_tree);
    AddVertex(-10.0, -30.0, new_tree);

    // sixth octant
    for(int i = 0; i < inv_circle.size(); i++) {
        AddVertex(-inv_circle[i].x, -inv_circle[i].y, new_tree);
    }

    // seventh octant
    for(int i = 0; i < tree.size(); i++) {
        AddVertex(tree[i].x, -tree[i].y, new_tree);
    }

    // eight octant
    for(int i = 0; i < inv_circle.size(); i++) {
        AddVertex(inv_circle[i].y, -inv_circle[i].x, new_tree);
    }

    // first octant
    for(int i = 0; i < tree.size(); i++) {
        AddVertex(tree[i].y, tree[i].x, new_tree);
    }

    // second octant
    for(int i = 0; i < inv_circle.size(); i++) {
        AddVertex(inv_circle[i].x, inv_circle[i].y, new_tree);
    }

    // third octant
    for(int i = 0; i < tree.size(); i++) {
        AddVertex(-tree[i].x, tree[i].y, new_tree);
    }

    // tree branch second half
    AddVertex(-10.0, 30.0, new_tree);
    AddVertex(-inv_circle[0].x - 200, inv_circle[0].y + 4, new_tree);

    tree = new_tree;
}

// checks if two points are equal with a tolerance
bool PointIsEqual(Vertex p1, Vertex p2) {
    double tolerance = 0.000001;

    if((fabs(p1.x - p2.x) <= tolerance)  && (fabs(p1.y - p2.y) <= tolerance))  {
        return true;
    }

    return false;
}

// finds the cross product of point a, b, and c
// is used in tessellation
// if negative then ccw, if positive then cw, if 0 then collinear or parallel 
float IsCCW(Vertex a, Vertex b, Vertex c) {
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
}

// linear interpolation
float Lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

// check if line ab and line cd intersect
bool DoesIntersect(Vertex a, Vertex b, Vertex c, Vertex d) {
    const float tTop = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);       // to check if x and y are within first line
    const float uTop = (c.y - a.y) * (a.x - b.x) - (c.x - a.x) * (a.y - b.y);       // to check if x and y are within second line
    const float bottom = (d.y - c.y) * (b.x - a.x) - (d.x - c.x) * (b.y - a.y);     // denominator of the equation

    // bottom cannot be between [-5000, 5000]
    if(bottom > 5000 || bottom < -5000) {
        const float t = tTop / bottom;
        const float u = uTop / bottom;

        // if t and u both are between 0 and 1 then the lines intersects
        if(t >= 0 && t <= 1 && u >= 0 && u <= 1) {
            return true;
        }
    }

    // otherwise the lines do not intersect
    return false;
}

// update intersectPt with where line ab and line cd intersect
Vertex GetIntersection(Vertex a, Vertex b, Vertex c, Vertex d) {
    const float tTop = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);       // to check if x and y are within first line
    const float uTop = (c.y - a.y) * (a.x - b.x) - (c.x - a.x) * (a.y - b.y);       // to check if x and y are within second line
    const float bottom = (d.y - c.y) * (b.x - a.x) - (d.x - c.x) * (b.y - a.y);     // denominator of the equation
   
    // bottom cannot be between [-5000, 5000]
    if(bottom > 5000 || bottom < -5000) {
        const float t = tTop / bottom;
        const float u = uTop / bottom;

        // if t and u both are between 0 and 1 then update intersectPt
        if(t >= 0 && t <= 1 && u >= 0 && u <= 1) {
            return {(Lerp(a.x, b.x, t)), Lerp(a.y, b.y, t)};
        }
    }

    return {(INFINITY, INFINITY)};
}

// if the line created by p1 and p2 cross any other lines created by the points in my list 
// of vertices, return true, otherwise retur false
// order of points matter, p1 is prevPoint and p2 is nextPoint
bool SegmentIntersection(Vertex p1, Vertex p2, vector<Vertex> vp) {
    bool equalPoints;
    // bool sameLine;

    // check every line created by myVertices
    for(int i = 0; i < vp.size() - 1; i++) {
        // finds if p1 and p2 are equal to any other points in myVertices
        equalPoints = PointIsEqual(p1, vp[i]) || PointIsEqual(p2, vp[i+1]) || PointIsEqual(p1, vp[i+1]) || PointIsEqual(p2, vp[i]);

        // if they are equal, ignore them
        if((equalPoints) && vp.size() > 1) {
            continue;
        }
        
        // otherwise check if the p1 and p2 intersect any other lines in vp
        // if it does intersect, return true
        if(DoesIntersect(vp[i], vp[i+1], p1, p2)) {
            // printf("x: %f   y: %f ----> rejected: collides with line %d\n", p1.x, p2.y, i+1);
            return true;
        } 
    }

    // otherwise return false
    return false;
}

// updates myTriangle data structure with a list of triangles created by the Ear Clipping Algorithm
int Tessellate(vector<Vertex> vp, vector<Triangle> &triangles) {
    float tolerance = -1.0;
    int totalTriangles = 0;
    int a = 0; int b = 1; int c = 2;        // pointers to myVertices

    // Ear Clipping Algorithm

    // loop will break when there are only 3 points left in myVertices
    while(true) {
        // if the current three points are counterclockwise
        if(IsCCW(vp[a], vp[b], vp[c]) < tolerance) {
            // then check if the line intersects any other previous lines
            if(SegmentIntersection(vp[a], vp[c], vp)) {
                // if so, update pointer to next set of three points
                a++; b++; c++;
            } else {
                    // inserting triangle into data structure
                    triangles.push_back(Triangle());
                    triangles[totalTriangles].a = vp[a];
                    triangles[totalTriangles].b = vp[b];
                    triangles[totalTriangles].c = vp[c];
                    totalTriangles++; 

                    // remove center vertex
                    vp.erase(vp.begin() + b);
                    a = 0; b = 1; c = 2;

                    // if there are only 3 points left, then break
                    if(vp.size() == 2)
                        break;
                }
        // if the current three points are clockwise
        } else if (IsCCW(vp[a], vp[b], vp[c]) > 0) {
            a++; b++; c++;
        // otherwise if it is collinear
        } else {
            //remove center vertex
            vp.erase(vp.begin() + b);
            a = 0; b = 1; c = 2;
        }
    }

    return totalTriangles;
}

void DrawPolygon(vector<Vertex> vertices) {
    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < vertices.size(); i++)
            glVertex2f(vertices[i].x ,vertices[i].y);
    glEnd();
    glFlush();
}

// color the polygon after tessellation using the triangle data structure
void ColorTriangles(vector<Triangle> triangles) {
    for(int i = 0; i < triangles.size(); i++) {
        glBegin(GL_POLYGON);
            glVertex2f(triangles[i].a.x, triangles[i].a.y);
            glVertex2f(triangles[i].b.x, triangles[i].b.y);
            glVertex2f(triangles[i].c.x, triangles[i].c.y);
        glEnd();     
    }
    glFlush();
}

// draw triangle line form list of points from tessellating
void DrawTriangles(vector<Triangle> triangles) {
    for(int i = 0; i < triangles.size(); i++) {
        glBegin(GL_LINES);
            glVertex2f(triangles[i].a.x, triangles[i].a.y);
            glVertex2f(triangles[i].b.x, triangles[i].b.y);
            glVertex2f(triangles[i].c.x, triangles[i].c.y);
        glEnd();
    }
    glFlush();
}

// check if vertex is inside the clipping boundary
bool Inside(Vertex testVertex, vector<Vertex> clipBoundary) {
	if (clipBoundary[1].x > clipBoundary[0].x)	/*bottom*/
		if (testVertex.y >= clipBoundary[0].y)
			return true;
	if (clipBoundary[1].x < clipBoundary[0].x)	/*top*/
		if (testVertex.y <= clipBoundary[0].y)
			return true;
	if (clipBoundary[1].y > clipBoundary[0].y)	/*right*/
		if (testVertex.x <= clipBoundary[1].x)
			return true;
	if (clipBoundary[1].y < clipBoundary[0].y)	/*left*/
		if (testVertex.x >= clipBoundary[1].x)
			return true;
	return false;
}

void SuthHodgClip(vector<Vertex> &inVertices, vector<Vertex> &outVertices, vector<Vertex> &clipBoundary) {
    Vertex s, p, i; // starting vertex, next vertex, intersection vertex
    s.z = 0.0; s.w = 1.0;
    p.z = 0.0; p.w = 1.0;
    i.z = 0.0; i.w = 1.0;

    s = inVertices[inVertices.size() - 1];
    for(int j = 0; j < inVertices.size(); j++) {
        p = inVertices[j];
        if(Inside(p, clipBoundary)) {           // case 1 and 4
            if(Inside(s, clipBoundary)) {       // case 1 : add next vertex
                AddVertex(p, outVertices);
            } else {                            // case 4 : add intersection vertex and then next vertex
                i = GetIntersection(s, p, clipBoundary[0], clipBoundary[1]);
                AddVertex(i, outVertices);
                AddVertex(p, outVertices);
            }
        } else if(Inside(s, clipBoundary)) {                                // case 2 and 3
            i = GetIntersection(s, p,  clipBoundary[0], clipBoundary[1]);   // case 2 : add intersection vertex
            AddVertex(i, outVertices);
        }                                                                   // case 3 : do nothing
        s = p;
    }
}

void ClipPipeline(vector<Vertex> &og_poly) {
    vector<Vertex> clip_boundary(2);
    vector<Vertex> temp = og_poly;

    glColor3f(1.0, 0.0, 0.0);

    // clip left
    og_poly.clear();
    clip_boundary[0].x = VIEWPORT_MIN; clip_boundary[0].y = inf;
    clip_boundary[1].x = VIEWPORT_MIN; clip_boundary[1].y = -inf;
    SuthHodgClip(temp, og_poly, clip_boundary);
    
    // clip right
    temp = og_poly;
    og_poly.clear();
    clip_boundary[0].x = VIEWPORT_MAX; clip_boundary[0].y = -inf;
    clip_boundary[1].x = VIEWPORT_MAX; clip_boundary[1].y = inf;
    SuthHodgClip(temp, og_poly, clip_boundary);
    
    // clip bottom
    temp = og_poly;
    og_poly.clear();       
    clip_boundary[0].x = -inf; clip_boundary[0].y = VIEWPORT_MIN;
    clip_boundary[1].x = inf; clip_boundary[1].y = VIEWPORT_MIN;
    SuthHodgClip(temp, og_poly, clip_boundary);
    
    // clip top
    temp = og_poly;
    og_poly.clear();
    clip_boundary[0].x = inf; clip_boundary[0].y = VIEWPORT_MAX;
    clip_boundary[1].x = -inf; clip_boundary[1].y = VIEWPORT_MAX;
    SuthHodgClip(temp, og_poly, clip_boundary);
}

void myinit(void) {
    // attributes
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glPointSize(1.0);

    //set up viewing
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (float) WINDOW_MAX,
               0.0, (float) WINDOW_MAX);
    glMatrixMode(GL_MODELVIEW);
}

void display(void) {
    vector<Vertex> tree;
    int radius = 100;

    // clear screen
    glClear(GL_COLOR_BUFFER_BIT);

    // define viewport
    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);

    // define the polygon points
    // MidpointCircle(tree, radius);
    MakeTree(tree, radius);

    // now start the process of rotating
    PipeLine(tree);

    // now start clipping
    ClipPipeline(tree);

    // now find triangles for tessellation
    vector<Triangle> triangles; 
    if(reflected) 
        Invert(tree);
    if(show_triangles || fill_triangles)
        Tessellate(tree, triangles);

    // draw rotated, scaled, clipped and tessellated tree
    glColor3f(0.0, 0.7, 0.4);

    DrawPolygon(tree);

    if(show_triangles)
        DrawTriangles(triangles);   
    if(fill_triangles)
        ColorTriangles(triangles);

    glutSwapBuffers();
}

void SpinDisplay(void) {
    SPIN = SPIN + DELTA_SPIN;
    if(SPIN > 360.0) 
        SPIN = SPIN - 360.0;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    bool outsideViewport = x > VIEWPORT_MAX || x < VIEWPORT_MIN || (WINDOW_MAX - y) > VIEWPORT_MAX || (WINDOW_MAX - y) < VIEWPORT_MIN;

    // increase ccw spin
    if(button == GLUT_LEFT_BUTTON && !outsideViewport) {
        if(state == GLUT_DOWN) {
            DELTA_SPIN  -= CHANGE_SPIN;
            glutIdleFunc(SpinDisplay);
        }
    }

    // inc cw spin
    if(button == GLUT_RIGHT_BUTTON && !outsideViewport) {
        if(state == GLUT_DOWN) {
            DELTA_SPIN += CHANGE_SPIN;
            glutIdleFunc(SpinDisplay);
        }
    }

    // if outside viewport and left button, increase scale
    if((button == GLUT_LEFT_BUTTON) && outsideViewport) {
        if(state == GLUT_DOWN) {
            scale += scale_speed;

            // clamp upper scale
            if(scale > maxScale) {
                scale = maxScale;
            }
        }
    }

    // if outside viewport and right button, decrease scale
    if((button == GLUT_RIGHT_BUTTON) && outsideViewport) {
        if(state == GLUT_DOWN) {
            scale -= scale_speed;
        }

        // clamp lower scale
        if(scale < minScale) {
            scale = minScale;
        }
    }
}

void keyboard( unsigned char key, int x, int y ) { 
    // exit program
    if ( key == 'q' || key == 'Q') 
        exit(0);

    // toggle reflection
    if (key == 'r' || key == 'R') {
        if(!reflected)
            reflected = true;
        else
            reflected = false;
    }

    // set fill_triangle to true
    if (key == 'f' || key == 'F') {
        if(!fill_triangles) {
            show_triangles = false;
            fill_triangles = true;
        } 
    }

    // set show_triangles to true
    if (key == 't' || key == 'T') {
        if(!show_triangles) {
            show_triangles = true;
            fill_triangles = false;
        }
    }

    // reset tessellation booleans
    if (key == 'l' || key == 'L') {
        show_triangles = false;
        fill_triangles = false;
    }
    
    // stop animation
    if (key == 's' || key == 'S') {
        DELTA_SPIN = 0.0;
        glutIdleFunc(display);
    }

    // stop animation and return to initial position
    if ( key == 'i' || key == 'I') {
        scale = 1.0;
        SPIN = 0.0;
        DELTA_SPIN = 0.0;
        glutIdleFunc(display);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(WINDOW_MAX,WINDOW_MAX); 
    glutInitWindowPosition(0,0); 
    glutCreateWindow("The Tree"); 
    myinit(); 
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display); 
    PrintMenu();
    glutMainLoop();
}