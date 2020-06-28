#pragma once
#include "Camera.h"
#include "GL/glut.h"
#include "GL/freeglut.h"

class GmeObject {
public:

	unsigned int Triangles = 0;

	float rX = 0;
	float rY = 0;
	float rZ = 0;


	float X = 0;
	float Y = 0;
	float Z = 0;

	float* Vertexes;
	char* Colors;

	GmeObject(unsigned int Triangles);

	void Draw();
};