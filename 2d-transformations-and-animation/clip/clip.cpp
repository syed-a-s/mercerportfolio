#include <iostream>
#include <vector>
using namespace std;

#define VIEWPORT_MAX 900
#define VIEWPORT_MIN 100

struct Vertex {
    float x, y, w, z;
};

// Print Vertex Struct
void PrintVertex(Vertex p) {
    printf("x: %f y: %f\n\n", p.x, p.y);
}

// Print Vector of Vertex Struct
void PrintVertices(vector<Vertex> vp) {
    for(int i = 0; i < vp.size(); i++)
        printf("x: %f y: %f z: %f w: %f\n", vp[i].x, vp[i].y, vp[i].z, vp[i].w);
    printf("\n");
}

// check if a  point is on the LEFT side of an edge
bool inside(Vertex p, Vertex p1, Vertex p2) {
    return (p2.y - p1.y) * p.x + (p1.x - p2.x) * p.y + (p2.x * p1.y - p1.x * p2.y) < 0;
}

// linear interpolation
float Lerp(float a, float b, float t) {
    return a + (b - a) * t;
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
            return {Lerp(a.x, b.x, t), Lerp(a.y, b.y, t)};
        }
    }

    return {0.0, 0.0};
}

void SuthHodgClip(vector<Vertex> &subjectPolygon, vector<Vertex> &clipPolygon, vector<Vertex> &newPolygon) {
    Vertex cp1, cp2, s, e;
    vector<Vertex> inputPolygon;
    
    // copy subject polygon to new polygon
    newPolygon = subjectPolygon;

    for(int j = 0; j < clipPolygon.size(); j++) {
        inputPolygon = newPolygon;
        int counter = 0;

        cout << "j :       " << j << endl;
        cout << "fancy j : " << (j + 1) % 4 << endl;

        cp1 = clipPolygon[j];
        cp2 = clipPolygon[(j + 1) % clipPolygon.size()];

        cout << "cp1 : "; PrintVertex(cp1);
        cout << "cp2 : "; PrintVertex(cp2);
        
        for(int i = 0; i < newPolygon.size(); i++) {
            s = inputPolygon[i];
            e = inputPolygon[(i + 1) % newPolygon.size()];
            
            // // case 1 : both vertices are inside
            // if(inside(s, cp1, cp2) && inside(e, cp1, cp2)) {
            //     newPolygon.push_back(Vertex());
            //     newPolygon[counter++] = e;
            // // case 2 : first vertex is outside while the second vertex is inside
            // } else if(!inside(s, cp1, cp2) && inside(e, cp1, cp2)) {
            //     newPolygon.push_back(Vertex());
            //     newPolygon.push_back(Vertex());
            //     newPolygon[counter++] = GetIntersection(cp1, cp2, s, e);
            //     newPolygon[counter++] = e;
            // // case 3 : first vertex is inside while the second one is outside
            // } else if(inside(s, cp1, cp2) && !inside(e, cp1, cp2)) {
            //     newPolygon.push_back(Vertex());
            //     newPolygon[counter++] = GetIntersection(cp1, cp2, s, e);
            // // case 4 : both verticies are outside
            // } else if(!inside(s, cp1, cp2) && !inside(e, cp1, cp2)) {
            //     // no vertices are added to the list
            // }
        }
    }

}

void DefineArrow(vector<Vertex> &apts) {
    apts[0].x = 250.0; apts[0].y = 300.0; apts[0].z = 0.0; apts[0].w = 1.0;
    apts[1].x = 450.0; apts[1].y = 300.0; apts[1].z = 0.0; apts[1].w = 1.0;
    apts[2].x = 550.0; apts[2].y = 350.0; apts[2].z = 0.0; apts[2].w = 1.0;
    apts[3].x = 450.0; apts[3].y = 400.0; apts[3].z = 0.0; apts[3].w = 1.0;
    apts[4].x = 250.0; apts[4].y = 400.0; apts[4].z = 0.0; apts[4].w = 1.0;
}

int main(int argc, char** argv) {
    float temp[5];
    float *tm = &temp[0];

    // the polygon to clip
    vector<Vertex> arrow(5);
    DefineArrow(arrow);

    // the clipping polygon
    vector<Vertex> clipPolygon(4);
    clipPolygon[0].x = VIEWPORT_MIN; clipPolygon[0].y = VIEWPORT_MIN;
    clipPolygon[1].x = VIEWPORT_MAX; clipPolygon[1].y = VIEWPORT_MIN;
    clipPolygon[2].x = VIEWPORT_MAX; clipPolygon[2].y = VIEWPORT_MAX;
    clipPolygon[3].x = VIEWPORT_MIN; clipPolygon[3].y = VIEWPORT_MAX;

    Vertex cp1, cp2;
    Vertex clip[] = {   {VIEWPORT_MIN, VIEWPORT_MIN}, 
                        {VIEWPORT_MAX, VIEWPORT_MIN},
                        {VIEWPORT_MAX, VIEWPORT_MAX},
                        {VIEWPORT_MIN, VIEWPORT_MAX}                      
                    };

    // for(int j = 0; j < 4; j++) {
    //     cout << "j :       " << j << endl;
    //     cout << "fancy j : " << (j + 1) % 4 << endl;
    // }

    // new clipped polygon
    vector<Vertex> newArrow;

    // apply clipping 
    SuthHodgClip(arrow, clipPolygon, newArrow);

    // print clipped polygon points
    cout << "Clipped polygon points" << endl;
    PrintVertices(newArrow);

    return 0;
}