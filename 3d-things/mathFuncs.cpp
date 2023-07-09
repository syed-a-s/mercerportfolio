#ifndef MATH
#define MATH

#include "structs.h"
#include <math.h>

// checks if line abc is ccw
bool IsCCW(Vertex a, Vertex b, Vertex c) {
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y) < 0 ? true : false;
}

// find angle of line abc
float FindAngle(Vertex a, Vertex b, Vertex c) {
    Vertex vAB, vBC;

    // find vector AB and vector BC
    vAB.x = b.x - a.x; vAB.y = b.y - a.y; vAB.z = b.z - a.z; vAB.w = 1;
    vBC.x = c.x - b.x; vBC.y = c.y - b.y; vBC.z = c.z - b.z; vBC.w = 1;

    float dot_prod = (vAB.x * vBC.x) + (vAB.y * vBC.y) + (vAB.z * vBC.z);
    float magAB = sqrt(pow(vAB.x, 2) + pow(vAB.y, 2) + pow(vAB.z, 2));
    float magBC = sqrt(pow(vBC.x, 2) + pow(vBC.y, 2) + pow(vBC.z, 2));

    return acos(dot_prod / (magAB * magBC)) * (180 / M_PI);
}

#endif