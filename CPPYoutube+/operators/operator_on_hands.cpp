#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

struct Vector2
{
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {}

    Vector2 Add(const Vector2 &other) const { return Vector2(x + other.x, y + other.y); }
    Vector2 Multiply(const Vector2 &other) const { return Vector2(x * other.x, y * other.y); }

    Vector2 operator+(const Vector2 &other) const { return other.Add(other); }
    Vector2 operator*(const Vector2 &other) const { return other.Multiply(other); }
    bool operator==(const Vector2 &other) const
    {
        return x == other.x && y == other.y;
    }
};

int main(int argc, char const *argv[])
{

    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    Vector2 result = position.Add(speed.Multiply(powerup));

    cout << "x: " << result.x << "y: " << result.y << endl;

    result = result + result;

    cout << "x: " << result.x << " y: " << result.y << endl;

    result = result * result;

    cout << "x: " << result.x << " y: " << result.y << endl;

    if (result == position)
        cout << " they are equal " << endl;
    else
        cout << " they are not equal " << endl;

    return 0;
}