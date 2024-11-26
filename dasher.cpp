#include "raylib.h"

int main()
{
    //Window dimensions
    const int windowWidht{500};
    const int windowHeight{500};

    //Init window
    InitWindow(windowWidht, windowHeight, "DAPPER DASHER GAME");

    //Set 60 FPS
    SetTargetFPS(60);

    //Infinite loop
    while (!WindowShouldClose())
    {
        //Start drawing
        BeginDrawing();

        //Background color
        ClearBackground(WHITE);

        //End drawing
        EndDrawing();

    }
}