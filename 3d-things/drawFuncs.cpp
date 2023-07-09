#ifndef DRAW_FUNCS
#define DRAW_FUNCS

#include "opengl.h"
#include "structs.h"
#include "globals.h"
#include "prototypes.h"
#include <string>

void DrawAxes(int length) {   
/* This provides a coordinate axis about the origin. */
    glColor3f(0.2, 0.2, 0.2);
    glPointSize(1.0);

    // axes labels
    std::string z_axis = "Z";
    std::string y_axis = "Y";
    std::string x_axis = "X";

    // set stroke font
    void *font = GLUT_STROKE_ROMAN;

    glBegin(GL_LINES);
        glVertex3i(0,length,0);
        glVertex3i(0,-length,0);
    glEnd();

    glBegin(GL_LINES);
        glVertex3i(length,0,0);
        glVertex3i(-length,0,0);
    glEnd();

    glBegin(GL_LINES);
        glVertex3i(0,0,length);
        glVertex3i(0,0,-length);
    glEnd();

    // add lettering
    glColor3f(1.0, 0.0, 0.0);

    // z-label
    glPushMatrix();
        glTranslatef(-0.2, 0.2, 4);
        glRotatef(90.0, 0.0, 0.0, 1.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glScalef(0.002, 0.002, 0.002);
        DrawText(z_axis, font);
    glPopMatrix();

    // y-label
    glPushMatrix();
        glTranslatef(0.0, 4, -0.4);
        glRotatef(90.0, 0.0, 0.0, 1.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glScalef(0.002, 0.002, 0.002);
        DrawText(y_axis, font);
    glPopMatrix();

    // x-axis
    glPushMatrix();
        glTranslatef(4.0, 0.0, -0.4);
        glRotatef(90.0, 0.0, 0.0, 1.0);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        glScalef(0.002, 0.002, 0.002);
        DrawText(x_axis, font);
    glPopMatrix();
}

// draw face of box
void DrawFaces(std::vector<box> face, GLint mode) {
    for(int j = 0; j < face.size(); j++) {
        glColor3f(face[j].color.red,
                  face[j].color.green,
                  face[j].color.blue);
    
        glBegin(mode);
            for(int i = 0; i < 4; i++) {
                glVertex3f(face[j].point[i].x,
                           face[j].point[i].y,
                           face[j].point[i].z);
                }
        glEnd();
    }
}

// draw specified text with specified font
void DrawText(std::string text, void *font) {
    for(int i = 0; i < text.length(); i++) 
        glutStrokeCharacter(font, text[i]);
}

// draw specified text in 2D
void Draw2DText(GLuint x, GLuint y, void *font, const char* string) {
    const char *c;
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_W, 0.0, WINDOW_H);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(x, y);
    for(c = string; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
}

// draw house with lines or as a polygon with a specified text on the roof
void DrawHouse(std::vector<box> face, std::string text, GLint mode) {
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    // set coordinates of roof
    Vertex a, b, c;
    a = face[7].point[1];
    b = face[7].point[0];
    c = face[7].point[0]; c.y = 0.0;

    // find roof angle and set font
    float roof_angle = FindAngle(a,b,c);
    void *font = GLUT_STROKE_ROMAN;

    // matrix for house
    glPushMatrix();
        glTranslatef(2.0,2.0,0.0);
        glRotated(Z_SPIN, 0.0, 0.0, 1.0); // rotate z-axis
        glRotated(Y_SPIN, 0.0, 1.0, 0.0); // rotate y-axis
        glRotated(X_SPIN, 1.0, 0.0, 0.0); // rotate x-axis

        // draw lines or shapes depending on GLint mode
        DrawFaces(face, mode);

        // matrix for text
        glPushMatrix();
            glColor3f(1.0, 0.0, 0.0);
            glTranslatef(1.38, 0.75, 1.15);
            glScalef(0.004, 0.004, 0.004);
            glRotated(roof_angle, 1.0, 0.0, 0.0); // rotate x-axis to the angle of the roof
            glRotated(180, 0.0, 1.0, 0.0);        // flip text over y-axis
            if(TOGGLE_SIGN)
                DrawText(text, font);             // draw text
        glPopMatrix();
    glPopMatrix();
}

#endif
