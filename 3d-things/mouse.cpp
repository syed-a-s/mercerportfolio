#ifndef MOUSE
#define MOUSE

#include "opengl.h"
#include "globals.h"
#include "prototypes.h"
#include <math.h>

int CheckMouse(int x, int y, int w, int h) {
    Vertex a, b, c, mouse_p;

    a.x = 0;     a.y = 0;           // bottom left point of screen
    b.x = w / 2; b.y = h / 2;       // center point of screen
    c.x = w;     c.y = 0;           // bottom right point of screen

    mouse_p.x = x; mouse_p.y = y;   // mouse point in screen

    if(!IsCCW(a, b, mouse_p) && IsCCW(c, b, mouse_p)) // z-axis, bottom of screen
        return 0;
    else if(!IsCCW(c, b, mouse_p) && x > w / 2)       // x-axis, right side of screen
        return 1;
    else                                              // y-axis, left side of screen
        return 2;
}

void mouse(int button, int state, int x, int y) { 
    int screen_side = CheckMouse(x, fabs(y - WINDOW_H), WINDOW_W, WINDOW_H);

    switch(screen_side) {
        case 0:
            if(button == GLUT_LEFT_BUTTON) {         // increase ccw spin on z-axis
                if(state == GLUT_DOWN) {
                    Z_DELTA_SPIN  -= CHANGE_SPIN;
                    glutIdleFunc(SpinDisplay);
                }
            }

            if(button == GLUT_RIGHT_BUTTON) {        // inc cw spin on z-axis
                if(state == GLUT_DOWN) {
                    Z_DELTA_SPIN += CHANGE_SPIN;
                    glutIdleFunc(SpinDisplay);
                }
            }
            break;
        case 1:
            if(button == GLUT_LEFT_BUTTON) {         // increase ccw spin on x-axis
                if(state == GLUT_DOWN) {
                    X_DELTA_SPIN  -= CHANGE_SPIN;
                    glutIdleFunc(SpinDisplay);
                }
            }

            if(button == GLUT_RIGHT_BUTTON) {        // inc cw spin on x-axis
                if(state == GLUT_DOWN) {
                    X_DELTA_SPIN += CHANGE_SPIN;
                    glutIdleFunc(SpinDisplay);
                }
            }
            break;
        case 2:
            if(button == GLUT_LEFT_BUTTON) {         // increase ccw spin on y-axis
                if(state == GLUT_DOWN) {
                    Y_DELTA_SPIN  -= CHANGE_SPIN;
                    glutIdleFunc(SpinDisplay);
                }
            }

            if(button == GLUT_RIGHT_BUTTON) {        // inc cw spin on y-axis
                if(state == GLUT_DOWN) {
                    Y_DELTA_SPIN += CHANGE_SPIN;
                    glutIdleFunc(SpinDisplay);
                }
            }
            break;
    }
}

#endif