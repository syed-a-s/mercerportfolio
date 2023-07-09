#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"
#include "opengl.h"
#include <string>

void DefineHouse(std::vector<box> &face);
float FindAngle(Vertex a, Vertex b, Vertex c);
void DrawAxes(int length);
void DrawFaces(std::vector<box> face, GLint mode);
void DrawText(std::string text, void *font);
void Draw2DText(GLuint x, GLuint y, void *font, const char* string);
void DrawHouse(std::vector<box> face, std::string text, GLint mode);
void init(void);
void reshape(int w, int h);
void display(void);
bool IsCCW(Vertex a, Vertex b, Vertex c);
int CheckMouse(int x, int y, int w, int h);
void SpinDisplay(void);
void mouse(int button, int state, int x, int y);
void specialkeys(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
void ToggleAxis(int msg);
void ToggleWire(int msg);
void ToggleSign(int msg);
void ToggleView(int msg);
void ToggleOther(int msg);
void DoNothing(int msg);
void PerspectiveToOrtho(GLdouble fovy, GLdouble aspect, GLdouble z_near, GLdouble z_far);
void OrthoToPerspective(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val);
void SetPerspective(GLdouble fovy, GLdouble aspect, GLdouble z_near, GLdouble z_far);
void SetOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val);
void SetCamMode();
void Reset();
void HardReset();
void StopAnimation();

#endif