#pragma once
#include "GmeObject.h"
#include "List.h"
#include "GL/glut.h"
#include "GL/freeglut.h"

const unsigned int WIDTH = 640;
const unsigned int HEIGHT = 480;

const float dTime = 0.016f;

const unsigned int MaxTrig = 10;

namespace Core {

	extern List* Objects;

	void Start(int argc, char** argv);

	void Draw();

	void Reshape(GLsizei width, GLsizei height);

	void Idle();

}