#include "Core.h"

extern unsigned int WIDTH = 640;
extern unsigned int HEIGHT = 480;

extern float dTime = 0.016f;

extern float mSensX = 0.1f;
extern float mSensY = 0.1f;

extern unsigned char MSAA = 8;

extern bool LockMouse = true;
extern bool HideMouse = true;

extern List* Core::Objects = new List();

void Core::Start(int argc, char** argv) {
    glutInit(&argc, argv);

    //Configure MSAA
    if (MSAA != 0) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);

        glEnable(GLUT_MULTISAMPLE);
        glutSetOption(GLUT_MULTISAMPLE, MSAA);
    }
    else glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    //Configure Window
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("3Damp");

    //Set Events
    glutDisplayFunc(&Draw);
    glutReshapeFunc(&Reshape);
    glutKeyboardFunc(Events::KeyPressedDown);
    glutKeyboardUpFunc(Events::KeyReleased);
    glutPassiveMotionFunc(Events::MouseMovedInWindow);

    //Set OpenGL Config
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0f);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

    if (HideMouse) glutSetCursor(GLUT_CURSOR_NONE);

    glutMainLoop();
}