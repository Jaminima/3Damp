#pragma once
#include "GmeObject.h"
#include "Events.h"
#include "List.h"
#include "GL/glut.h"
#include "GL/freeglut.h"

const unsigned int WIDTH = 640;
const unsigned int HEIGHT = 480;

const float dTime = 0.016f;

const unsigned char MSAA = 8;

const unsigned int MaxTrig = 10;

const bool LockMouse = true;
const bool HideMouse = true;

namespace Core {

	extern List* Objects;

	void Start(int argc, char** argv);

	void Draw();

	void Reshape(GLsizei width, GLsizei height);

}