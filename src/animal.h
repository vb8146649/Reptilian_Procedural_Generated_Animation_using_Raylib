#pragma once
#include "circle.h"
#include <vector>
#include "raymath.h"
#include <cmath>
#include <iostream>
#include "src/common.h"


class Animal{
    public:
        Animal();
        int circleNumber;
        float maxAngle;
        void Draw();
        void Update();
        void Gui();
    private:
        void HandleControls();
        void Chained();
        void Animate();
        float rotationAngle;
        std::vector<Circle> circles;
        std::vector<Vector2> positions;
        Circle circle;
        float chainLength;
        float radius;
        Color color;
        float speed;
        void Add();
        void Pop();
};