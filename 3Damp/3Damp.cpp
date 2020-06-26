#include <iostream>
#include "Core.h"

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

    Core::Objects::vertexes[0] = -0.5f;
    Core::Objects::vertexes[1] = 0;
    Core::Objects::vertexes[2] = 0.1f;

    Core::Objects::vertexes[3] = 0;
    Core::Objects::vertexes[4] = 0.5f;
    Core::Objects::vertexes[5] = 0.1f;

    Core::Objects::vertexes[6] = 0.5f;
    Core::Objects::vertexes[7] = 0.5f;
    Core::Objects::vertexes[8] = 0.5;

    Core::Objects::colors[0] = 255;
    Core::Objects::colors[1] = 0;
    Core::Objects::colors[2] = 0;
    Core::Objects::colors[3] = 255;

    Core::Objects::colors[4] = 0;
    Core::Objects::colors[5] = 255;
    Core::Objects::colors[6] = 0;
    Core::Objects::colors[7] = 255;

    Core::Objects::colors[8] = 0;
    Core::Objects::colors[9] = 0;
    Core::Objects::colors[10] = 255;
    Core::Objects::colors[11] = 255;

    Core::Start(argc, argv);
}