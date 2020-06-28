#include <iostream>
#include "Core.h"

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

    GmeObject* O = new GmeObject(1);

    O->X = -1.5f;
    O->Z = -6.0f;

    O->Vertexes[0] = 0;
    O->Vertexes[1] = 1;
    O->Vertexes[2] = 0;

    O->Vertexes[3] = -1;
    O->Vertexes[4] = -1;
    O->Vertexes[5] = 1;

    O->Vertexes[6] = 1;
    O->Vertexes[7] = -1;
    O->Vertexes[8] = 1;

   O->Colors[0] = 255;
   O->Colors[1] = 0;
   O->Colors[2] = 0;
   O->Colors[3] = 255;

   O->Colors[4] = 0;
   O->Colors[5] = 255;
   O->Colors[6] = 0;
   O->Colors[7] = 255;

   O->Colors[8] = 0;
   O->Colors[9] = 0;
   O->Colors[10] = 255;
   O->Colors[11] = 255;

    Core::Objects->Add(O);

    Core::Start(argc, argv);
}