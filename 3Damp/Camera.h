#pragma once

namespace Camera {
	extern float X;
	extern float Y;
	extern float Z;

	extern float rX;
	extern float rY;
	extern float rZ;

	void MoveRelative(float fwd, float sde);

	void MoveRelativeAdv(float fwd, float sde, float vrt);
}