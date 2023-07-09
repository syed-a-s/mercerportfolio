#ifndef RESET
#define RESET

#include "opengl.h"
#include "globals.h"
#include "prototypes.h"

// reset zoom, xyz rotation, and stop animation
void Reset() {
    zoom = INIT_ZOOM;
    Z_SPIN = 0.0; Y_SPIN = 0.0; X_SPIN = 0.0;
    StopAnimation();
    glutIdleFunc(display);
}

// reset everything and reset camera
void HardReset() {
    Reset();
    CAM_MODE = 1;
    TOGGLE_WIRE = 0;
    TOGGLE_SIGN = 1;
    TOGGLE_AXIS = 0;
    glutIdleFunc(display);
}

// stop change in rotation
void StopAnimation() {
    Z_DELTA_SPIN = 0.0; Y_DELTA_SPIN = 0.0; X_DELTA_SPIN = 0.0;
    glutIdleFunc(display);
}

#endif