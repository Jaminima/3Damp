#include "Core.h"
#include <iostream>

extern List* Core::Objects = new List();

void TriggerRedraw(int i) {
    glutPostRedisplay();
}

void Core::Draw() {
    if (Events::OnKeyDepressed) Events::DoKeys();
    if (Events::OnFrame) Events::OnFrame();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    Item* I = Objects->Head;
    GmeObject* P;

    while (I != 0x0) {
        P = (GmeObject*)I->Obj;
        glLoadIdentity();
        P->Draw();
        if (Events::OnObjectUpdate) Events::OnObjectUpdate(P);
        I = I->Next;
    }
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glFlush();
    glutSwapBuffers();

    glutTimerFunc((unsigned int)ceil(dTime * 1000), TriggerRedraw, 0);
}

void Core::Reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

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
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0f);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

    if (HideMouse) glutSetCursor(GLUT_CURSOR_NONE);

    glutMainLoop();
}