#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

struct sadetin
{
    float x;
    float y;
};

class entitySado
{
public:
    float x;
    float y;

    entitySado(float x, float y) : x(x), y(y)
    {
    }
};

using namespace std;

int main()
{
    sadetin *const a = new sadetin{12, 89}; // value cannot be changed

    const sadetin *b; // pointed address cannot be changed

    const sadetin o = {12, 89}; // OR const sadetin o{12, 89};

    long long saadettindoChar[8];

    const entitySado *k;
    entitySado *const alibaba = new entitySado(x = 12, y = 90);

    cout << "Address of saadettindoChar: " << static_cast<void *>(saadettindoChar) << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << "Address of saadettindoChar[" << i << "]: " << static_cast<void *>(&saadettindoChar[i]) << endl;
    }

    return 0;
}
