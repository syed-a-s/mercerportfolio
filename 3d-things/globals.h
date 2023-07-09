#ifndef GLOBALS_H
#define GLOBALS_H

#include "opengl.h"

extern int WINDOW_W;
extern int WINDOW_H;

const extern float INIT_ZOOM;
const extern float CHANGE_ZOOM;
extern float zoom;

extern float Z_DELTA_SPIN; extern float Z_SPIN; 
extern float Y_DELTA_SPIN; extern float Y_SPIN;
extern float X_DELTA_SPIN; extern float X_SPIN;
const extern float CHANGE_SPIN;

extern int TOGGLE_AXIS;
extern int TOGGLE_WIRE;
extern int TOGGLE_SIGN;
extern int CAM_MODE;

extern GLdouble fovy, aspect, z_near, z_far;
extern GLdouble left, right, bottom, top, near_val, far_val;

#endif