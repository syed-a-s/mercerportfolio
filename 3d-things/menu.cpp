#ifndef MENU
#define MENU

#include "opengl.h"
#include "globals.h"
#include "prototypes.h"

// toggle TOGGLE_AXIS
void ToggleAxis(int msg) {
    switch (msg) {
        case 1:
            TOGGLE_AXIS = 1; 
            break;
        case 2:
            TOGGLE_AXIS = 0; 
            break;
    }
    glutPostRedisplay();
}

// toggle TOGGLE_WIRE
void ToggleWire(int msg) {
    switch (msg) {
        case 1:
            TOGGLE_WIRE = 1; 
            break;
        case 2:
            TOGGLE_WIRE = 0; 
            break;
    }
    glutPostRedisplay();
}

// toggle TOGGLE_SIGN
void ToggleSign(int msg) {
    switch (msg) {
        case 1:
            TOGGLE_SIGN = 1; 
            break;
        case 2:
            TOGGLE_SIGN = 0; 
            break;
    }
    glutPostRedisplay();
}

// toggle CAM_MODE
void ToggleView(int msg) {
    CAM_MODE = msg;    
}

// toggle between more options
void ToggleOther(int msg) {
    switch (msg) {
        case 1 :
            HardReset();
            break;
        case 2 :
            exit(0);
            break;
    }
}

// do nothing
void DoNothing(int msg) {}

#endif