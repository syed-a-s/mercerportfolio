#ifndef DISPLAY
#define DISPLAY

#include "opengl.h"
#include "globals.h"
#include "prototypes.h"

void display(void) {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position

    // Set camera mode
    SetCamMode();

    // We are going to set our position to be down the Y-Axis looking at the
    // center of the coordinate frame.  The positive Z-Axis will be up.

    gluLookAt(  zoom,   zoom, 2.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up -- set which axis is up

    glEnable(GL_DEPTH_TEST);

    std::vector<box> my_house(8);
    std::string my_text = "Hello World";

    DefineHouse(my_house);

    // draw xyz axis depending on DRAW_AXIS
    if(TOGGLE_AXIS)
        DrawAxes(5);

    // draw lines or shapes of box depending on the state of TOGGLE_WIRE 
    DrawHouse(my_house, my_text, TOGGLE_WIRE == 1 ? GL_LINE_LOOP : GL_POLYGON);

    glutPostRedisplay();
    glutSwapBuffers();
}

#endif