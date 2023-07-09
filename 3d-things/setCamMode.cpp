#ifndef SET_CAM_MODE
#define SET_CAM_MODE

#include "prototypes.h"
#include "globals.h"
#include <iostream>

void SetCamMode() {
    glColor3f(1.0, 0.0, 0.0);

    // for user input
    char mode;

    // default camera values
    GLdouble default_fovy = 100.0; 
    GLdouble default_aspect = (GLdouble) WINDOW_W / (GLdouble) WINDOW_H;
    GLdouble default_z_near = 1.0;
    GLdouble default_z_far = 100.0;

    // xy position of text
    GLuint x = WINDOW_W - 80;
    GLuint y = WINDOW_H - 20;

    // for 2d text 
    char *charString = (char*)malloc(40 * sizeof(char));
    void *font = GLUT_BITMAP_HELVETICA_12;

    switch (CAM_MODE) {
        case 1 :
            // perspective camera mode
            sprintf(charString, "Perspective");
            SetPerspective(default_fovy, default_aspect, default_z_near, default_z_far);
            break;
        case 2 :
            // orthographic camera mode
            sprintf(charString, "Orthographic");
            PerspectiveToOrtho(default_fovy, default_aspect, default_z_near, default_z_far);
            break;
        case 3 :
            // get user input
            std::cout << "Select Camera Mode : p for Perspective, o for Orthographic >> "; std::cin >> mode; 

            if(mode == 'p') {
                // process custom perspective camera
                std::cout << "Enter fovy : "; std::cin >> fovy;            
                std::cout << "Enter aspect : "; std::cin >> aspect;
                std::cout << "Enter z_near : "; std::cin >> z_near;
                std::cout << "Enter z_far : "; std::cin >> z_far;
                CAM_MODE = 4;
            } else if (mode == 'o') {
                //process custom orthographic camera
                std::cout << "Enter left value : "; std::cin >> left;
                std::cout << "Enter right value : "; std::cin >> right;
                std::cout << "Enter bottom value : "; std::cin >> bottom;
                std::cout << "Enter top value : "; std::cin >> top;
                std::cout << "Enter near_val value : "; std::cin >> near_val;
                std::cout << "Enter far_val value : "; std::cin >> far_val;
                CAM_MODE = 5;
            } else {
                std::cout << "Not a mode. Try again" << std::endl;
            }
            break;
        case 4 :
            // custom perspective camera
            sprintf(charString, "Custom");
            SetPerspective(fovy, aspect, z_near, z_far);
            break;
        case 5 : 
            // custom orthographic camera
            sprintf(charString, "Custom");
            SetOrtho(left, right, bottom, top, near_val, far_val);
            break;
    }

    // draw text on to viewport
    Draw2DText(x, y, font, charString);
    free(charString);
}

#endif