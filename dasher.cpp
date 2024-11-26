#include "raylib.h"

int main()
{
    //Window dimensions
    const int windowWidht{512};
    const int windowHeight{380};

    //Init window
    InitWindow(windowWidht, windowHeight, "DAPPER DASHER GAME");

    // rentangle dimensions
    const int widht{50};
    const int height{80};

    int posY{windowHeight - height};
    int velocity{0};


    //Set 60 FPS
    SetTargetFPS(60);

    //Infinite loop
    while (!WindowShouldClose())
    {
        //Start drawing
        BeginDrawing();

        //Background color
        ClearBackground(WHITE);

        //Draw rentangle
        posY += velocity;
        DrawRectangle(windowWidht/2, posY, widht, height, BLUE);

        //Moving codes
        if(IsKeyPressed(KEY_SPACE))
        {
            velocity-=10;
        }

        //End drawing
        EndDrawing();

    }
}