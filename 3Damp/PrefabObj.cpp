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
                case 0: gme->ObjFile;

                case 1: gme->rX;
                case 2: gme->rY;
                case 3: gme->rZ;

                case 4: gme->X;
                case 5: gme->Y;
                case 6: gme->Z;
                }

                i++;
            }
        }
        data.close();
    }
    else cout << "Unable to open file";

    return gme;
}