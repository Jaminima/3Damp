#pragma once
#include "GL/glut.h"
#include "GL/freeglut.h"

class GmeObject {
public:

	unsigned int Triangles = 0;

	float X = 0;
	float Y = 0;
	float Z = 0;

	float* Vertexes;
	char* Colors;

	GmeObject(unsigned int Triangles);

	void Draw();
};