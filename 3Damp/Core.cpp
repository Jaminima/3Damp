#include "Core.h"

extern List* Core::Objects = new List();

void TriggerRedraw(int i) {
    glutPostRedisplay();
}

void Core::Draw() {
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
        /*P->rZ += 1;
        P->rY += 2;
        P->rX += 3;*/
        I = I->Next;
    }

    Camera::Z += 0.1f;
    Camera::rY += 0.1f;
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glFlush();
    glutSwapBuffers();

    glutTimerFunc(dTime * 1000, TriggerRedraw, 0);
}

void Core::Reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 1000.0f);
}

void Core::Start(int argc, char** argv) {
    glutInit(&argc, argv);

    if (MSAA != 0) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);

        glEnable(GLUT_MULTISAMPLE);
        glutSetOption(GLUT_MULTISAMPLE, MSAA);
    }

    else glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("GLUT Test");

    glutDisplayFunc(&Draw);
    glutReshapeFunc(&Reshape);

    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0f);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 


    glutMainLoop();
}