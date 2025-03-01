#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Player
{
public:
    int x, y;
    int speed;

    void move(int xa, int ya)
    {
        x += xa + speed;
        y += ya + speed;
    }

    void printPlayer()
    {
        cout << "a: " << x << endl;
        cout << "b: " << y << endl;
        cout << "speed: " << speed << endl;
    }
};

int main(int argc, char const *argv[])
{
    Player player1;
    player1.printPlayer();

    player1.x = 12;
    player1.y = 23;
    (&player1)->speed = 56;

    player1.printPlayer();

    player1.move(23, 45);

    player1.printPlayer();

    return 0;
}