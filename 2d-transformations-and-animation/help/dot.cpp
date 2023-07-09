// Author : Syed Saadat



// An OpenGL Tessellation Program
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <ostream>
#include <iostream>
#include <vector>
using namespace std;

// simple Vertex struct
//      has an x to represent x coordinate
//      has a y to represent y coordinate
struct Vertex {
    float x;
    float y;
};

// The triangle struct uses the Vertex struct to create
// triangle that is built with 3 points
struct Triangle {
    Vertex a;
    Vertex b;
    Vertex c;
};

int totalVertices = 0;              // keeps track of number of vertices
int totalTriangles = 0;             // keeps track of number of triangles
bool LAST_POINT = false;            // lets program know if user is done drawing polygon
Vertex nextPoint;                   // nextPoint and prevPoint will be used together to determine if mouse input intersects with previous lines
Vertex prevPoint;                   // 
vector<Vertex> myVertices;          // a vector of structs
vector<Triangle> myTriangles;       //
vector<Vertex> trianglePoints;      //

// Specity the values to place and size the window on the screen
const int WINDOW_POSITION_X = 100;
const int WINDOW_POSITION_Y = 100;
const int WINDOW_MAX_X = 800;
const int WINDOW_MAX_Y = 800;

// Specify the coordinate ranges for the world coordinates in the 2D Frame
const float WORLD_COORDINATE_MIN_X = 0.0;
const float WORLD_COORDINATE_MAX_X = 800.0;
const float WORLD_COORDINATE_MIN_Y = 0.0;
const float WORLD_COORDINATE_MAX_Y = 800.0;

// Declaring All functions
void PrintMenu();
void PrintVector(vector<Vertex> vertices);
void PrintTriangles(vector<Triangle> triangles);
void PrintVertex(Vertex point);
void display(void);
void myglutInit(int argc, char** argv);
void myInit(void);
void drawBox(float x, float y);
void InsertPoint(float x, float y);
void DrawLine(Vertex p1, Vertex p2);
void DrawLastLine();
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
bool DoesIntersect(Vertex a, Vertex b, Vertex c, Vertex d);     
bool SegmentIntersection(Vertex p1, Vertex p2);
bool PointIsEqual(Vertex p1, Vertex p2);
float IsCCW(Vertex a, Vertex b, Vertex c);
float FindAngle(Vertex a, Vertex b, Vertex c);
float TriangleArea(Vertex a, Vertex b, Vertex c);
void Tessellate();
void DrawTriangles();
void DrawVertices();
void ColorPolygon();
void ColorTriangles();
void PrintTriangleAreas();

int main(int argc, char** argv) {
    PrintMenu();
    myglutInit(argc,argv); /* Set up Window */
    myInit(); /* set attributes */
    // Now start the standard OpenGL glut callbacks //
    glutMouseFunc(mouse);  /* Define Mouse Handler */
    glutKeyboardFunc(keyboard); /* Define Keyboard Handler */
    glutDisplayFunc(display);
    glutMainLoop(); /* enter event loop */
}

void PrintMenu() {
    printf("\033[2J\033[1;1H");
    printf("Polygon Things\n");
    printf("\tMouse Right : Insert Point\n");
    printf("\tMouse Left  : Draw Last Line\n");
    printf("\tf           : Draw Polygon Filled with No Tessellation\n");
    printf("\tt           : View Triangles for Tessellation\n");
    printf("\tp           : Draw Polygon Filled with Tessellation\n");
    printf("\ti           : Draw Initial Polygon\n");
    printf("\tc           : Clear Screen and Reset\n");
    printf("\tq           : Quit Program\n");
    printf("\t--------------------------\n");
}

// to help debug

// Specifically prints a vector of structs
void PrintVector(vector<Vertex> vertices) {
    cout << "\t" << "All Vertices" << endl;
    for(int i = 0; i < vertices.size(); i++) {
        cout << "\t\t" << i << " : " << vertices[i].x << " " << vertices[i].y << endl;
    }
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

// Prints out my Vertex struct
void PrintVertex(Vertex point) {
    printf("x: %f   y: %f\n", point.x, point.y);
}

////////////////

////////////// display initializers for glut to work /////////////////////
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void myglutInit(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); /* default, not needed */
    glutInitWindowSize(WINDOW_MAX_X,WINDOW_MAX_Y); /* set pixel window */
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y); /* place window top left on display */
    glutCreateWindow("Polygon Things"); /* window title */
}

void myInit(void) {
    /* standard OpenGL attributes */
    glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
    glColor3f(1.0, 0.0, 0.0); /* draw in red */
    glPointSize(10.0);

    /* set up viewing window with origin lower left */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(WORLD_COORDINATE_MIN_X, WORLD_COORDINATE_MAX_X,
        WORLD_COORDINATE_MIN_Y, WORLD_COORDINATE_MAX_Y);
    glMatrixMode(GL_MODELVIEW);
}
//////////////////////////////////////////////////////////////////////////

// works in conjuction with the mouse listener function
// parameters : x ---> mouse input x
//              y ---> mouse input y
void drawBox(float x, float y) {
    // nextPoint struct is initialized to the mouse input 
    nextPoint.x = x;
    nextPoint.y = WINDOW_MAX_Y - y;

    // prevPoint is the previous point in myVertices
    // only update if there are at least two points, otherwise there will be out of bound errors
    if(totalVertices > 1) {
        prevPoint.x = myVertices[totalVertices - 1].x;
        prevPoint.y = myVertices[totalVertices - 1].y;
    } 
    
    // nextPoint and prevPoint create a line, SegmentIntersection method checks 
    // if this line intersects with any other lines in myVertices
    if(!SegmentIntersection(nextPoint, prevPoint)) {
        // add the nextPoint vertex into myVertices
        printf("x: %f   y: %f ----> accepted\n", nextPoint.x, nextPoint.y);
        myVertices.push_back(Vertex());
        myVertices[totalVertices].x = nextPoint.x;
        myVertices[totalVertices].y = nextPoint.y;

        // draw line from previous index in myVertices to the 
        // current index of myVertices
        if(totalVertices > 0 && !LAST_POINT) {
            DrawLine(myVertices[totalVertices - 1], myVertices[totalVertices]);
        }

        // at this point, update the total num of vertices
        totalVertices++;
    } 

    glFlush();
}

// draws line from point 1 to point 2
void DrawLine(Vertex p1, Vertex p2) {
    glColor3f (1.0, 0.0, 0.0);      // Set line segment color to red

    glBegin(GL_LINES);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
    glEnd();

    glFlush() ;     // Process all OpenGL routines as quickly as possible.   
}

// Draws a line from the last point in list of vertices to the first point in the list of vertices
void DrawLastLine() {
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINES);
        glVertex2f(myVertices[totalVertices - 1].x, myVertices[totalVertices - 1].y);
        glVertex2f(myVertices[0].x, myVertices[0].y);
    glEnd();

    glFlush();
}

// mouse handler function - used to detect mouse left and mouse right input
void mouse( int button, int state, int x, int y ) {
    // if right click, send mouse x and mouse y to drawBox 
    if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && LAST_POINT != 1) {
        drawBox(x, y);
    }

    // if left click, attempt to draw the last line
    if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) {
        if(totalVertices > 2) {
            if(!LAST_POINT) {
                nextPoint.x = myVertices[0].x;                  // update nextPoint to the first point in myVertices
                nextPoint.y = myVertices[0].y;
                prevPoint.x = myVertices[totalVertices - 1].x;  // update prevPoint to the last point in myVertices
                prevPoint.y = myVertices[totalVertices - 1].y;

                // if there is no line segment intersection, then draw the last line
                if(!SegmentIntersection(nextPoint, prevPoint)){
                    LAST_POINT = true;
                    printf("x: %f   y: %f ----> accepted\n", nextPoint.x, nextPoint.y);
                    DrawLastLine();                                 
                    myVertices.push_back(Vertex());                 // add last vertex of polygon as the first vertex
                    myVertices[totalVertices].x = myVertices[0].x;
                    myVertices[totalVertices].y = myVertices[0].y;
                    totalVertices++;
                // otherwise, let user know there is an intersection
                } else {
                    printf("\tError: Cannot draw last line from current point\n");
                }
            }
        } else {
            printf("\tError: Cannot draw last line, you need at least three points!\n");
        }
    } 
}

// keyboard handler function 
// i = show initial polygon
// f = attempt to color polygon with no tessellation
// t = tessellate the polygon
// p = color polygon after tessellation
// c = reset the program
// q = exit the program
// with every event, the screen is cleared and the polygon is drawn each time
void keyboard( unsigned char key, int x, int y ) {
    if(key == 'i' || key == 'I') {
        // if the user is done drawing a polygon, then draw initial polygon
        if(LAST_POINT) {
            glClear(GL_COLOR_BUFFER_BIT);
            DrawVertices();
        // otherwise let user know there is no polygon to display
        } else {
            printf("No Polygon to Display\n");
        }
    }

    if(key == 'f' || key == 'F') {
        // only color polygon if user is finished drawing first polygon
        if(LAST_POINT) {
            glClear(GL_COLOR_BUFFER_BIT);      // clear screen
            DrawVertices();                    // draw polygon
            ColorPolygon();                    // color polygon
        // otherwise let user know of error
        } else {
            printf("Cannot Color Polygon : Last point not drawn yet!\n");
        }
    }

    if(key == 't' || key == 't') {
        // if the user is finished drawing a polygon, then draw triangles used in tessellation
        if(LAST_POINT) {
            glClear(GL_COLOR_BUFFER_BIT);       // clear screen
            DrawVertices();                     // draw polygon

            // if the triangle has not been tessellated yet, then tessellate and print triangle areas
            if(myTriangles.empty()) {
                Tessellate();
                PrintTriangleAreas();
            }
                
            // always attempt to draw the triangles
            DrawTriangles();

        // otherwise let user know of error
        } else {
            printf("Cannot Tessellate : Last point not drawn yet!\n");
        }
    }

    if(key == 'p' || key == 'P') {
        // if the user is finished drawing a polygon, then draw triangles used in tessellation
        if(LAST_POINT) {
            glClear(GL_COLOR_BUFFER_BIT);
            DrawVertices();

            // if the triangle has not been tessellated yet, then tessellate and print triangles
            if(myTriangles.empty()) {
                Tessellate();
                PrintTriangleAreas();
            }
            // always attempt to color the triangle
            ColorTriangles();

        // otherwise let user know of error
        } else {
            printf("Cannot Color Polygon : Last point not drawn yet!\n");
        }
    }

    // reset the program
    if(key == 'c' || key == 'C') {
        LAST_POINT = false;         // program is unlocked again
        myVertices.clear();         // clear all my data structures
        myTriangles.clear();        //
        trianglePoints.clear();     //
        totalVertices = 0;          //
        totalTriangles = 0;         //
        PrintMenu();
        glClear(GL_COLOR_BUFFER_BIT);   
    }

    // exit program
    if ( key == 'q' || key == 'Q') { 
        exit(0);
    }

    glFlush();
}

// Sees if two line segments, created by fours points, intersect
// if intersects, return true, if not, return false
// a and b are paired together to make a line
// c and d are paired together to make a line
// This function helps SegmentIntersection find line segment intersections in the whole list of vertices
bool DoesIntersect(Vertex a, Vertex b, Vertex c, Vertex d) {
    const float tTop = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);       // to check if x and y are within first line
    const float uTop = (c.y - a.y) * (a.x - b.x) - (c.x - a.x) * (a.y - b.y);       // to check if x and y are within second line
    const float bottom = (d.y - c.y) * (b.x - a.x) - (d.x - c.x) * (b.y - a.y);     // denominator of the equation

    // the denominator cannot be 0
    // here, there is a tolerance of 5000
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

// if the line created by p1 and p2 cross any other lines created by the points in my list 
// of vertices, return true, otherwise retur false
// order of points matter, p1 is prevPoint and p2 is nextPoint
bool SegmentIntersection(Vertex p1, Vertex p2) {
    bool equalPoints;

    // check every line created by myVertices
    for(int i = 0; i < totalVertices - 1; i++) {
        // finds if p1 and p2 are equal to any other points in myVertices
        equalPoints = PointIsEqual(p1, myVertices[i]) || PointIsEqual(p2, myVertices[i+1]) || PointIsEqual(p1, myVertices[i+1]) || PointIsEqual(p2, myVertices[i]);

        // if they are equal, ignore them
        if(equalPoints && totalVertices > 1) {
            continue;
        }
        
        // otherwise check if the p1 and p2 intersect any other lines in myVertices
        // if it does intersect, return true
        if(DoesIntersect(myVertices[i], myVertices[i+1], p1, p2)) {
            printf("x: %f   y: %f ----> rejected: collides with line %d\n", p1.x, p2.y, i+1);
            return true;
        } 
    }

    // otherwise return false
    return false;
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

// finds the area of a triangle from three given points
float TriangleArea(Vertex a, Vertex b, Vertex c) {
    return 0.5 * (a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
}

// updates myTriangle data structure with a list of triangles created by the Ear Clipping Algorithm
void Tessellate() {
    float tolerance = -1.0;
    int i = 0;
    int a = 0; int b = 1; int c = 2;        // pointers to myVertices
    vector<Vertex> temp = myVertices;       // copy of myVertices

    // Ear Clipping Algorithm

    // run until loop breaks
    // loop will break when there are only 3 points left in myVertices
    while(true) {
        // if the current three points are counterclockwise
        if(IsCCW(temp[a], temp[b], temp[c]) < tolerance) {
            // then check if the line intersects any other previous lines
            if(SegmentIntersection(temp[a], temp[c])) {
                // if so, update pointer to next set of three points
                a++; b++; c++;
            } else {
                    //inserting triangle lines into data structure
                    trianglePoints.push_back(Vertex());
                    trianglePoints.push_back(Vertex());
                    trianglePoints[i] = temp[a];
                    trianglePoints[i + 1] = temp[c];
                    i += 2;

                    // inserting triangle into data structure
                    myTriangles.push_back(Triangle());
                    myTriangles[totalTriangles].a = temp[a];
                    myTriangles[totalTriangles].b = temp[b];
                    myTriangles[totalTriangles].c = temp[c];
                    totalTriangles++; 

                    // remove center vertex
                    temp.erase(temp.begin() + b);
                    a = 0; b = 1; c = 2;

                    // if there are only 3 points left, then break
                    if(temp.size() == 3)
                        break;
                }
        // if the current three points are clockwise
        } else if (IsCCW(temp[a], temp[b], temp[c]) > 0) {
            a++; b++; c++;
        // otherwise if it is collinear
        } else {
            //remove center vertex
            temp.erase(temp.begin() + b);
            a = 0; b = 1; c = 2;
        }
    }
}

// draw triangle line form list of points from tessellating
void DrawTriangles() {
    for(int i = 0; i < trianglePoints.size() - 1; i++) {
        DrawLine(trianglePoints[i], trianglePoints[i+1]);
    }
}

// draw the user created polygon
void DrawVertices() {
    for(int i = 0; i < myVertices.size() - 1; i++) {
        DrawLine(myVertices[i], myVertices[i+1]);
    }
    DrawLastLine();
}

// color the polygon without tessellation
void ColorPolygon() {
    glBegin(GL_POLYGON);
        for(int i = 0; i < myVertices.size(); i++) {
            glVertex2f(myVertices[i].x, myVertices[i].y);
        }
    glEnd();
    glFlush();
}

// color the polygon after tessellation using the triangle data structure
void ColorTriangles() {
    for(int i = 0; i < myTriangles.size(); i++) {
        glBegin(GL_POLYGON);
            glVertex2f(myTriangles[i].a.x, myTriangles[i].a.y);
            glVertex2f(myTriangles[i].b.x, myTriangles[i].b.y);
            glVertex2f(myTriangles[i].c.x, myTriangles[i].c.y);
        glEnd();     
    }
    glFlush();
}

// print area of all triangles in myTriangles
void PrintTriangleAreas() {
    printf("\n");
    for(int i = 0; i < myTriangles.size(); i++) {
        printf("\t%d: Triangle Area - %f\n", i, TriangleArea(myTriangles[i].a, myTriangles[i].b, myTriangles[i].c));
    }
    printf("\tTotal Triangles : %d\n", totalTriangles);
}
