#include <iostream>
# include <windows.h>
#include "Core.h"

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
        Camera::MoveRelativeAdv(-0.2f, 0,0);
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

void ObjUpdate(GmeObject* obj) {
    /*obj->rX += rand() / 10000;
    obj->rY += rand() / 10000;
    obj->rZ += rand() / 10000;*/

    obj->rX += 1;
    obj->rY += 2;
    obj->rZ += 3;
    
}

void Frame() {
    //Camera::Z += 0.2f;
    //Camera::rX += 2;
    //Camera::rY += 1;
    //Camera::rZ += 1;
}

int main(int argc, char** argv)
{
    PrefabObject* P = new PrefabObject();

    P->ObjFile = (char *)"G:/OneDrive - University of Plymouth/Programming/C++/3Damp/Debug/teapot.obj";
    P->Save("G:/OneDrive - University of Plymouth/Programming/C++/3Damp/Debug/teapot.prf");

    GmeObject* T;
    //T = GmeObject::FromObjFile("G:/OneDrive - University of Plymouth/Programming/C++/3Damp/Debug/teapot.obj");
    T = P->CreateGameObj();

    T->Z = -200;

    Core::Objects->Add(T);

    GmeObject* O;
    
    /*O->Vertexes = new float[36]{
                0, 1, 0,
                -1,-1,1,
                1,-1,1,
                0,1,0,
                1,-1,1,
                1,-1,-1,
                0,1,0,
                1,-1,-1,
                -1,-1,-1,
                0,1,0,
                -1,-1,-1,
                -1,-1,1
        };
        O->Colors = new BYTE[48]{
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255,0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255
        };*/

        /*for (int x = 0, z = 0; z < 20;) {

        O = new GmeObject(12);

        O->Z = -(10 + z);
        O->X = (-10 + x);

        O->Y = -5;
        O->rX = 90;

        O->Vertexes = new float[108]{
                1,1,-1,
                -1,1,-1,
                -1,1,1,

                1,1,-1,
                1,1,1,
                -1,1,1,

                -1,-1,1,
                1,-1,1,
                1,-1,-1,

                -1,-1,1,
                -1,-1,-1,
                1,-1,-1,

                1,1,1,
                1,1,-1,
                1,-1,-1,

                1,1,1,
                1,-1,-1,
                1,-1,1,

                -1,-1,-1,
                -1,-1,1,
                -1,1,1,

                -1,-1,-1,
                -1,1,1,
                -1,1,-1,

                -1,1,1,
                1,1,1,
                1,-1,1,

                -1,-1,1,
                -1,1,1,
                1,-1,1,

                1,-1,-1,
                -1,-1,-1,
                -1,1,-1,

                1,1,-1,
                1,-1,-1,
                -1,1,-1
        };
        O->Colors = new BYTE[144]{
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255,0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255,0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255,0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255,0, 255,
                0, 0, 255, 255,
                255, 0, 0, 255,
                0, 255, 0, 255,
                0, 0, 255, 255
        };

        Core::Objects->Add(O);

        x+=2;
        if (x == 20) { x = 0; z+=2; }
    }*/

    Events::OnFrame = &Frame;
    Events::OnObjectUpdate = &ObjUpdate;
    Events::OnKeyDepressed = &OnKeyDepressed;
    Events::OnMouseMove = &OnMMove;
    Core::Start(argc, argv);
}