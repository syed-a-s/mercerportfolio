#ifndef GLOBALS
#define GLOBALS

#include "opengl.h"

int WINDOW_W = 500;
int WINDOW_H = 500;

float INIT_ZOOM = 5.0;
float CHANGE_ZOOM = 0.5;
float zoom = INIT_ZOOM;


float Z_DELTA_SPIN = 0.0; float Z_SPIN = 0.0; 
float Y_DELTA_SPIN = 0.0; float Y_SPIN = 0.0;
float X_DELTA_SPIN = 0.0; float X_SPIN = 0.0;
float CHANGE_SPIN = 0.02;

int TOGGLE_AXIS = 0;
int TOGGLE_WIRE = 0;
int TOGGLE_SIGN = 1;
int CAM_MODE = 1;

GLdouble fovy, aspect, z_near, z_far;
GLdouble left, right, bottom, top, near_val, far_val;

#endif