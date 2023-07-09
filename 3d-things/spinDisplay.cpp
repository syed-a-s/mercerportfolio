#ifndef SPIN_DISPLAY
#define SPIN_DISPLAY

#include "globals.h"
#include "opengl.h"

void SpinDisplay(void) {
    Z_SPIN = Z_SPIN + Z_DELTA_SPIN;
    if(Z_SPIN > 360.0) Z_SPIN = Z_SPIN - 360.0;

    Y_SPIN = Y_SPIN + Y_DELTA_SPIN;
    if(Y_SPIN > 360.0) Y_SPIN = Y_SPIN - 360.0;

    X_SPIN = X_SPIN + X_DELTA_SPIN;
    if(X_SPIN > 360.0) X_SPIN = X_SPIN - 360.0;

    glutPostRedisplay();
}

#endif