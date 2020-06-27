#include <iostream>
#include "Core.h"

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

    Core::Objects::vertexes[0] = 0;
    Core::Objects::vertexes[1] = 1;
    Core::Objects::vertexes[2] = 0;

    Core::Objects::vertexes[3] = -1;
    Core::Objects::vertexes[4] = -1;
    Core::Objects::vertexes[5] = 1;

    Core::Objects::vertexes[6] = 1;
    Core::Objects::vertexes[7] = -1;
    Core::Objects::vertexes[8] = 1;

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