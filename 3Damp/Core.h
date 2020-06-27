#pragma once
#include "GL/glut.h"
#include "GL/freeglut.h"

const unsigned int WIDTH = 640;
const unsigned int HEIGHT = 480;

const unsigned int MaxObj = 3;

namespace Core {

	namespace Objects {
		extern float vertexes[];
		extern char colors[];
	}

	void Start(int argc, char** argv);

	void Draw();

	void Reshape(GLsizei width, GLsizei height);

}