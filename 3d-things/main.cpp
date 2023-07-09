#include "opengl.h"
#include "globals.h"
#include "prototypes.h"

int main(int argc, char** argv) {
    // menu types
    int menu, axis, wire, sign, view, other;

    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize (WINDOW_W, WINDOW_H); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("The House");
    init();
    glutReshapeFunc(reshape); 
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialkeys);

    // axes menu item
    axis = glutCreateMenu(ToggleAxis);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);

    // wire menu item
    wire = glutCreateMenu(ToggleWire);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);

    // sign menu item
    sign = glutCreateMenu(ToggleSign);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);

    // view menu item
    view = glutCreateMenu(ToggleView);
    glutAddMenuEntry("Perspective", 1);
    glutAddMenuEntry("Orthographic", 2);
    glutAddMenuEntry("Custom", 3);
    
    // reset menu item
    other = glutCreateMenu(ToggleOther);
    glutAddMenuEntry("Reset", 1);
    glutAddMenuEntry("Quit", 2);

    // And now create the menu 
    menu = glutCreateMenu(DoNothing);
    glutAddSubMenu("Axes", axis);
    glutAddSubMenu("Wire", wire);
    glutAddSubMenu("Sign", sign);
    glutAddSubMenu("View", view);
    glutAddSubMenu("Other", other);

    glutAttachMenu(GLUT_MIDDLE_BUTTON);

    glutMainLoop();
    return 0;
}
