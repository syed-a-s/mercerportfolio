#ifndef RESHAPE
#define RESHAPE

#include "globals.h"
#include "opengl.h"
#include "prototypes.h"

// reshapes images according to window size
void reshape (int w, int h) {
    WINDOW_W = w;
    WINDOW_H = h;
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

#endif