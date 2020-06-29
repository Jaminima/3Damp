#include <iostream>
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
    /*obj->rX += 2;
    obj->rY += 3;
    obj->rZ += 1;*/
}

void Frame() {
    //Camera::Z += 0.2f;
    //Camera::rX += 2;
    //Camera::rY += 1;
    //Camera::rZ += 1;
}

int main(int argc, char** argv)
{
    GmeObject* O;

    /*O = new GmeObject(4);

    O->X = -1.5f;
    O->Z = -6.0f;

    O->Vertexes = new float[36] {
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
    O->Colors = new char[48] {
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
    };

    Core::Objects->Add(O);*/

    for (int x = 0, z = 0; z < 200;) {

        O = new GmeObject(12);

        O->Z = -(10 + z);
        O->X = (-100 + x);

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
                255, 0, 0, 127,
                0, 255, 0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255,0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255, 0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255, 0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255,0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255, 0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255, 0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255,0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255, 0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255, 0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255,0, 127,
                0, 0, 255, 127,
                255, 0, 0, 127,
                0, 255, 0, 127,
                0, 0, 255, 127
        };

        Core::Objects->Add(O);

        x+=2;
        if (x == 200) { x = 0; z+=2; }
    }

    Events::OnFrame = &Frame;
    Events::OnObjectUpdate = &ObjUpdate;
    Events::OnKeyDepressed = &OnKeyDepressed;
    Events::OnMouseMove = &OnMMove;
    Core::Start(argc, argv);
}