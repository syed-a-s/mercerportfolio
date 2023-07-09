#ifndef KEYBOARD
#define KEYBOARD

#include "opengl.h"
#include "globals.h"
#include "prototypes.h"

// initializes actions for special keys
void specialkeys(int key, int x, int y) {
    if(key == GLUT_KEY_PAGE_UP) 
        zoom -= CHANGE_ZOOM; glutPostRedisplay();

    if(key == GLUT_KEY_PAGE_DOWN)
        zoom += CHANGE_ZOOM; glutPostRedisplay();
}

// initializes actions for keys
void keyboard(unsigned char key, int x, int y) {
    // quit program
    if(key == 'q' || key == 'Q')
        exit(0);

    // reset everything
    if(key == 'R') {
        HardReset();
    }   

    // reset rotation and location
    if(key == 'r') {
        Reset();
    }

    // stop rotation
    if(key == 's' || key == 'S') {
        StopAnimation();
    }
}

#endif