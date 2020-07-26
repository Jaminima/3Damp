#include <iostream>
#include "../3Damp/Core.h"

void OnKeyDepressed(unsigned char C) {
    switch (C)
    {
    case 'q':
        Camera::MoveRelativeAdv(0, 0, 0.1f);
        break;
    case 'e':
        Camera::MoveRelativeAdv(0, 0, -0.1f);
        break;
    case 'w':
        Camera::MoveRelativeAdv(0.2f, 0, 0);
        break;
    case 'a':
        Camera::MoveRelative(0, -0.2f);
        break;
    case 's':
        Camera::MoveRelativeAdv(-0.2f, 0, 0);
        break;
    case 'd':
        Camera::MoveRelative(0, 0.2f);
        break;
    }
}

void OnMMove(int x, int y) {
    Camera::rY += x * mSensX;
    Camera::rX += y * mSensY;
}

int main(int argc, char** argv)
{
    GmeObject* P = GmeObject::FromObjFile("G:/OneDrive - University of Plymouth/Programming/C++/3Damp/ExampleGame/Debug/Assets/Cube.obj");

    Core::Objects->Add(P);

    Events::OnKeyDepressed = &OnKeyDepressed;
    Events::OnMouseMove = &OnMMove;
    Core::Start(argc, argv);
}
