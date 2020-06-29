#include "GmeObject.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include "List.h"

using namespace std;


//Stolen http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
template <class Container>
void StringSplit(const std::string& str, Container& cont,
    char delim = ' ')
{
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}

float* FPPtoFP(float** og, unsigned int len) {
    float* FP = new float[len];

    for (unsigned int i = 0; i < len; i++) 
        FP[i] = *og[i];

    return FP;
}

BYTE* BPPtoBP(BYTE** og, unsigned int len) {
    BYTE* FP = new BYTE[len];

    for (unsigned int i = 0; i < len; i++)
        FP[i] = *(unsigned char*)og[i];

    return FP;
}

GmeObject* GmeObject::FromObjFile(const char* File) {
    List Vert;
    List Trig;
    List Col;
    float** aVert = 0x0;

    GmeObject* gme = 0x0;

    string line;
    ifstream data;

    data.open(File);

    if (data.is_open())
    {
        while (getline(data, line))
        {
            if (line.length() > 0 && line[0] != '#') {

                std::vector<std::string> words;
                StringSplit(line, words, ' ');

                switch (line[0]) {

                case 'v':
                    if (line[1] == ' ')
                        Vert.Add(new float[3]{ stof(words[1]), stof(words[2]), stof(words[3]) });
                    break;

                case 'f':
                    if (!aVert) { aVert = (float**)Vert.ToArray(); }

                    float* Ord1 = aVert[Vert.Len - stoi(words[1])];
                    float* Ord2 = aVert[Vert.Len - stoi(words[2])];
                    float* Ord3 = aVert[Vert.Len - stoi(words[3])];

                    if (words.size() == 5) {
                        float* Ord4 = aVert[Vert.Len - stoi(words[4])];

                        Trig.Add(new float(Ord1[0]));
                        Trig.Add(new float(Ord1[1]));
                        Trig.Add(new float(Ord1[2]));
                        Trig.Add(new float(Ord3[0]));
                        Trig.Add(new float(Ord3[1]));
                        Trig.Add(new float(Ord3[2]));
                        Trig.Add(new float(Ord4[0]));
                        Trig.Add(new float(Ord4[1]));
                        Trig.Add(new float(Ord4[2]));
                    }

                    Trig.Add(new float(Ord1[0]));
                    Trig.Add(new float(Ord1[1]));
                    Trig.Add(new float(Ord1[2]));
                    Trig.Add(new float(Ord2[0]));
                    Trig.Add(new float(Ord2[1]));
                    Trig.Add(new float(Ord2[2]));
                    Trig.Add(new float(Ord3[0]));
                    Trig.Add(new float(Ord3[1]));
                    Trig.Add(new float(Ord3[2]));

                    for (unsigned int i = 0; i < words.size()-1; i++) {
                        Col.Add(new BYTE(255));
                        Col.Add(new BYTE(0));
                        Col.Add(new BYTE(0));
                        Col.Add(new BYTE(255));
                        Col.Add(new BYTE(0));
                        Col.Add(new BYTE(255));
                        Col.Add(new BYTE(0));
                        Col.Add(new BYTE(255));
                        Col.Add(new BYTE(0));
                        Col.Add(new BYTE(0));
                        Col.Add(new BYTE(255));
                        Col.Add(new BYTE(255));
                    }

                    break;
                }

            }
        }
        data.close();

        gme = new GmeObject(Trig.Len);
        gme->Vertexes = FPPtoFP((float**)Trig.ToArray(), Trig.Len);
        gme->Colors = BPPtoBP((BYTE**)Col.ToArray(), Col.Len);
    }
    else cout << "Unable to open file";

    return gme;
}

