#include "GmeObject.h"

void GmeObject::Draw() {
	glTranslatef(X, Y, Z);
	glVertexPointer(3, GL_FLOAT, sizeof(float) * 3, Vertexes);
	glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(char) * 4, Colors);
	glDrawArrays(GL_TRIANGLES, 0, Triangles*3);
}

GmeObject::GmeObject(unsigned int Triangles) {
	this->Triangles = Triangles;
	Vertexes = new float[Triangles * 9];
	Colors = new char[Triangles * 12];
}