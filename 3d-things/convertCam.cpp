#ifndef CONVERT_CAM
#define CONVERT_CAM

#include "opengl.h"
#include "prototypes.h"
#include <math.h>

// convert numbers for perspective view to numbers for ortho view
void PerspectiveToOrtho(GLdouble fovy, GLdouble aspect, GLdouble z_near, GLdouble z_far) {
    GLdouble fW, fH;

    fH = tan(fovy * -(360 / M_PI)) * z_near;
    fW = fH * aspect;

    SetOrtho(-fW, fW, -fH, fH, z_near, z_far);
}

// convert numbers for ortho view to numbers for perspective view
void OrthoToPerspective(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val) {
    GLdouble fovy, aspect;
    
    aspect = fabs(right - left) / fabs(top - bottom);
    fovy = atan((fabs(top - bottom) / 2.0) / near_val) * 2.0;
    fovy = fovy * 180.0 / acos(-1.0);

    SetPerspective(fovy, aspect, near_val, far_val);  
}

// call gluPerspective and set values to parameters
void SetPerspective(GLdouble fovy, GLdouble aspect, GLdouble z_near, GLdouble z_far) {
    gluPerspective(fovy, aspect, z_near, z_far);
}

// call glOrtho and set values to parameters
void SetOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val) {
    glOrtho(left, right, bottom, top, near_val, far_val);
}

#endif