#pragma once
#include <raylib.h>
#include <iostream>

class Circle{
    public:
        Circle(float radius,float chainLength);
        void Draw();
        static Color color;
        Vector2 position;
        Vector2 head;
        float radius;
        float chainLength;
    private:
};