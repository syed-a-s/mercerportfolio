// Draw Circle Using Midpoint Algorithm

#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
using namespace std;

#define WINDOW_MAX 700
#define WINDOW_MIN 0
#define VIEWPORT_MAX 600
#define VIEWPORT_MIN 100
#define MAX 100

struct Vertex {
    float x;
    float y;
};

int radius = 200;
int totalPoints = 0;
vector<Vertex> circle;

void PrintVector(vector<Vertex> vertices) {
    cout << "\t" << "All Vertices" << endl;
    for(int i = 0; i < vertices.size(); i++) {
        cout << "\t\t" << i << " : " << vertices[i].x << " " << vertices[i].y << endl;
    }
}

// build circle using midpoint algorithm
void MidpointCircle(int radius) {
    int x, y;
    float d;

    x = 0;
    y = radius;
    d = 5.0 / 4.0 - radius;
    
    while (y > x) {
        if (d <= 0) {
            d += x * 2.0 + 3;
            x++;
        } else {
            d += (x - y) * 2.0 + 5;
            x++;
            y--;
        }

        circle.push_back(Vertex());
        circle[totalPoints].x = x  + (WINDOW_MAX / 2);
        circle[totalPoints].y = y  + (WINDOW_MAX / 2);
        totalPoints++;
    }
}

void MakeCircle() {
    // first octant of circle
    MidpointCircle(radius);

    int octant = circle.size();

    // second octant of circle
    for(int i = 1; i < 2; i++) {
        circle.push_back(Vertex());
        circle[totalPoints].x = circle[i].y;
        circle[totalPoints].y = circle[i].x;
        totalPoints++;
    }
}

void DrawLine(Vertex p1, Vertex p2) {
    glColor3f (1.0, 0.0, 0.0);      // Set line segment color to red

    glBegin(GL_LINES);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
    glEnd();

    glFlush() ;     // Process all OpenGL routines as quickly as possible.   
}

void DrawPoints() {
    for(int i = 0; i < circle.size() - 1; i++) {
        DrawLine(circle[i], circle[i + 1]);
    }
}

void myinit( void ) {
/* attributes */
      glClearColor(0.0, 0.0, 0.0, 1.0); /* black background */
      glPointSize(1.0);

/* set up viewing */
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, (float) WINDOW_MAX, 
                 0.0, (float) WINDOW_MAX);
      glMatrixMode(GL_MODELVIEW);

    MakeCircle();
    PrintVector(circle);
}

void display(void) {
    // initialize circle
    
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    /* Define Viewport */
    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN,VIEWPORT_MIN,VIEWPORT_MAX,VIEWPORT_MAX);

    DrawPoints();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(WINDOW_MAX,WINDOW_MAX); 
    glutInitWindowPosition(0,0); 
    glutCreateWindow("The Circle"); 
    myinit(); 
    glutDisplayFunc(display); 
    glutMainLoop();
}