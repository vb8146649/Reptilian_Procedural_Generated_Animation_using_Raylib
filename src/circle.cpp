#include "circle.h"

Color Circle::color=RED;

Circle::Circle(float radius, float chainLength)
{
    this->chainLength=chainLength;
    this->radius=radius;
    position={350,350};
    head={0,-1*this->radius};
    std::cout<<"circle made"<<std::endl;
}

void Circle::Draw()
{
    DrawCircle(position.x,position.y,radius,color);
}

