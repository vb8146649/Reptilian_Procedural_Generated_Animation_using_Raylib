#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "animal.h"

int main(){
    int windowHeinght=700,windowWidth=700;

    InitWindow(windowWidth,windowHeinght,"Procedural Animation");
    Font font =LoadFont("src/monogram.ttf");
    SetTargetFPS(60);
    Animal animal;
    while(!WindowShouldClose()){
        animal.Update();
        BeginDrawing();
        ClearBackground(BLACK);
        animal.Draw();
        // DrawCircle(350,350,5,WHITE);
        EndDrawing();
        animal.Gui();
    }
    CloseWindow();
}