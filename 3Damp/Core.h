#pragma once
#include "GmeObject.h"
#include "Events.h"
#include "List.h"
#include "GL/glut.h"
#include "GL/freeglut.h"

extern unsigned int WIDTH;
extern unsigned int HEIGHT;

extern float dTime;

extern float mSensX;
extern float mSensY;

extern unsigned char MSAA;

extern bool LockMouse;
extern bool HideMouse;

namespace Core {

	extern List* Objects;

	void Start(int argc, char** argv);

	void Draw();

	void Reshape(GLsizei width, GLsizei height);

}