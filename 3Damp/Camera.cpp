#include "Camera.h"
#include <iostream>

float Camera::X = 0;
float Camera::Y = 0;
float Camera::Z = 0;

float Camera::rX = 0;
float Camera::rY = 0;
float Camera::rZ = 0;

void Camera::MoveRelative(float fwd, float sde) {
	float rRY = rY * 0.01745329251;
	Camera::Z += (cos(-rRY) * fwd) - (sin(rRY) * sde);
	Camera::X += (sin(-rRY) * fwd) - (cos(rRY) * sde);
}