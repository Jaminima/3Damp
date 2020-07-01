#pragma once
#include "GmeObject.h"
#include <string>

class PrefabObject {
public:
	char* ObjFile;

	float sX = 1;
	float sY = 1;
	float sZ = 1;

	float rX = 0;
	float rY = 0;
	float rZ = 0;

	float X = 0;
	float Y = 0;
	float Z = 0;

	void Save(const char* File);

	static PrefabObject* FromPrefFile(const char* File);

	GmeObject* CreateGameObj() {
		GmeObject* obj = GmeObject::FromObjFile(ObjFile);

		obj->sX = sX;
		obj->sY = sY;
		obj->sZ = sZ;

		obj->rX = rX;
		obj->rY = rY;
		obj->rZ = rZ;

		obj->X = X;
		obj->Y = Y;
		obj->Z = Z;

		return obj;
	}
};