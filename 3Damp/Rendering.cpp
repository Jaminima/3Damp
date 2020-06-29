#include "Core.h"
#include <iostream>

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