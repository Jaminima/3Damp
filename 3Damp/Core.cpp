#include "Core.h"

float Core::Objects::vertexes[MaxObj*3];
char Core::Objects::colors[MaxObj*4];

void Core::Draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(float)*2, &Core::Objects::vertexes[0]);
    glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(char)*4, &Core::Objects::colors[0]);
    glDrawArrays(GL_TRIANGLES, 0, MaxObj);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glFlush();
    glutSwapBuffers();
}

void Core::Start(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glutInitWindowSize(WIDTH, HEIGHT);

    glutCreateWindow("GLUT Test");

    glutDisplayFunc(&Draw);
    //glutIdleFunc(&Idle);

    glutMainLoop();
}