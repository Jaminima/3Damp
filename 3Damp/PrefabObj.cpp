#include "PrefabObj.h"
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

void PrefabObject::Save(const char* File) {
    ofstream data;
    data.open(File);

    data << ObjFile << '\n';

    data << rX << '\n';
    data << rY << '\n';
    data << rZ << '\n';

    data << X << '\n';
    data << Y << '\n';
    data << Z << '\n';

    data << sX << '\n';
    data << sY << '\n';
    data << sZ << '\n';

    data.close();
}

PrefabObject* PrefabObject::FromPrefFile(const char* File) {
    PrefabObject* gme = new PrefabObject();

    string line;
    ifstream data;

    data.open(File);

    unsigned int i = 0;

    if (data.is_open())
    {
        while (getline(data, line))
        {
            if (line.length() > 0) {

                switch (i)
                {
                case 0:
                    gme->ObjFile = new char[line.size()];
                    std::strcpy(gme->ObjFile, line.c_str());
                    break;

                case 1: gme->rX = stof(line); break;
                case 2: gme->rY = stof(line); break;
                case 3: gme->rZ = stof(line); break;

                case 4: gme->X = stof(line); break;
                case 5: gme->Y = stof(line); break;
                case 6: gme->Z = stof(line); break;

                case 7: gme->sX = stof(line); break;
                case 8: gme->sY = stof(line); break;
                case 9: gme->sZ = stof(line); break;
                }

                i++;
            }
        }
        data.close();
    }
    else cout << "Unable to open file";

    return gme;
}