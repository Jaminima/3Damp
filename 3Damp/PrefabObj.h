#pragma once
#include "GmeObject.h"

class PrefabObject {
public:
	char* ObjFile;

	float rX = 0;
	float rY = 0;
	float rZ = 0;

	float X = 0;
	float Y = 0;
	float Z = 0;

	void Save(const char* File);

	PrefabObject* FromPrefFile(const char* File);

	GmeObject* CreateGameObj() {
		GmeObject* obj = GmeObject::FromObjFile(ObjFile);

		return obj;
	}
};