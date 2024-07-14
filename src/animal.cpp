#include "animal.h"

Animal::Animal() : circle(radius, chainLength)
{
    radius = 20.0f;
    chainLength = 20.0f;
    rotationAngle=0.1;
    color=WHITE;
    circle=Circle(radius,chainLength);
    circles.push_back(circle);
    speed=1;
}

void Animal::Draw()
{
    Vector2 templ=circles[0].head,tempr=circles[0].head;
    for(long long int i=0;i<circles.size();i++){
        if(i<circles.size()){
            circles[i].Draw();
        }
        float theta=atan((circles[i].head.y-circles[i].position.y)/(circles[i].head.x-circles[i].position.x));
        if((circles[i].head.x-circles[i].position.x)<0){
            theta=((-theta)/abs(theta))*(PI-abs(theta));
        }
        DrawLineEx(templ,{circles[i].position.x+circles[i].radius*cos(theta+PI/2),circles[i].position.y+circles[i].radius*sin(theta+PI/2)},3,RED);
        DrawLineEx(tempr,{circles[i].position.x+circles[i].radius*cos(theta-PI/2),circles[i].position.y+circles[i].radius*sin(theta-PI/2)},3,RED);
        templ={circles[i].position.x+circles[i].radius*cos(theta+PI/2),circles[i].position.y+circles[i].radius*sin(theta+PI/2)};
        tempr={circles[i].position.x+circles[i].radius*cos(theta-PI/2),circles[i].position.y+circles[i].radius*sin(theta-PI/2)};
        if(i==circles.size()-1){
            DrawLineEx(templ,{circles[i].position.x+circles[i].radius*cos(theta+PI),circles[i].position.y+circles[i].radius*sin(theta+PI)},3,RED);
            DrawLineEx(tempr,{circles[i].position.x+circles[i].radius*cos(theta-PI),circles[i].position.y+circles[i].radius*sin(theta-PI)},3,RED);
        }
        // DrawCircle(circles[i].position.x+circles[i].radius*cos(theta+PI/2),circles[i].position.y+circles[i].radius*sin(theta+PI/2),5,RED);
        // DrawCircle(circles[i].position.x+circles[i].radius*cos(theta-PI/2),circles[i].position.y+circles[i].radius*sin(theta-PI/2),5,RED);
    }
}

void Animal::Update()
{
    Circle::color=color;
    HandleControls();
    Chained();
}

void Animal::HandleControls()
{
    float theta=atan((circles[0].head.y-circles[0].position.y)/(circles[0].head.x-circles[0].position.x));
    if((circles[0].head.x-circles[0].position.x)<0){
        theta=((-theta)/abs(theta))*(PI-abs(theta));
    }
    if (IsKeyDown(KEY_LEFT))
    {
        theta+=rotationAngle;
        circles[0].head={circles[0].position.x+circles[0].radius*cos(theta),circles[0].position.y+circles[0].radius*sin(theta)};
        circles[0].position=Vector2Add(circles[0].position,Vector2Scale(Vector2Normalize({circles[0].radius*cos(theta),circles[0].radius*sin(theta)}),speed));
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        theta-=rotationAngle;
        circles[0].head={circles[0].position.x+circles[0].radius*cos(theta),circles[0].position.y+circles[0].radius*sin(theta)};
        circles[0].position=Vector2Add(circles[0].position,Vector2Scale(Vector2Normalize({circles[0].radius*cos(theta),circles[0].radius*sin(theta)}),speed));
    }
    else if (IsKeyDown(KEY_UP))
    {
        circles[0].head={circles[0].position.x+circles[0].radius*cos(theta),circles[0].position.y+circles[0].radius*sin(theta)};
        circles[0].position=Vector2Add(circles[0].position,Vector2Scale(Vector2Normalize({circles[0].radius*cos(theta),circles[0].radius*sin(theta)}),speed));
    }
}

void Animal::Gui()
{
    GuiLabel((Rectangle){100,40,100,20},"Controls :");
    GuiSliderBar((Rectangle){100,70,100,20},"rotation angle",NULL,&rotationAngle,0.01,1);
    GuiSliderBar((Rectangle){100,100,100,20},"max angle",NULL,&maxAngle,0.01,1);
    GuiSliderBar((Rectangle){100,130,100,20},"radius",NULL,&radius,10,100);
    GuiSliderBar((Rectangle){100,160,100,20},"chain length",NULL,&chainLength,20,100);
    GuiSliderBar((Rectangle){100,190,100,20},"max angle joint",NULL,&maxAngle,0,1);
    GuiSliderBar((Rectangle){100,220,100,20},"speed",NULL,&speed,1,10);
    GuiColorPicker((Rectangle){100,250,100,50},"Color",&color);
    if(GuiButton((Rectangle){100,320,40,20},"Add")){
        Add();
    }
    if(GuiButton((Rectangle){100,350,40,20},"Pop")){
        Pop();
    }
}

void Animal::Chained()
{
    for(auto it=circles.begin()+1;it!=circles.end();it++){
        it->position=Vector2Add(Vector2Scale(Vector2Normalize(Vector2Subtract(it->position,(it-1)->position)),(it-1)->chainLength),(it-1)->position);
        it->head=Vector2Add(it->position,Vector2Scale(Vector2Normalize(Vector2Subtract((it-1)->position,it->position)),it->radius));
    }
}

void Animal::Animate()
{

}

void Animal::Add()
{
    circle =Circle(radius,chainLength);
    circles.push_back(circle);
}

void Animal::Pop()
{
    circles.pop_back();
}
