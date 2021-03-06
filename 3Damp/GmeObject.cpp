#include "GmeObject.h"
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

void GmeObject::Draw() {
	glRotatef(Camera::rX, 1, 0, 0);
	glRotatef(Camera::rY, 0, 1, 0);
	glRotatef(Camera::rZ, 0, 0, 1);

	glScalef(sX, sY, sZ);
	glTranslatef(X + Camera::X, Y + Camera::Y, Z + Camera::Z);

	glRotatef(rX, 1, 0, 0);
	glRotatef(rY, 0, 1, 0);
	glRotatef(rZ, 0, 0, 1);

	glVertexPointer(3, GL_FLOAT, sizeof(float) * 3, Vertexes);
	glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(BYTE) * 4, Colors);
	glDrawArrays(GL_TRIANGLES, 0, Triangles*3);
}

GmeObject::GmeObject(unsigned int Triangles) {
	this->Triangles = Triangles;
	Vertexes = new float[Triangles * 9];
	Colors = new BYTE[Triangles * 12];
}