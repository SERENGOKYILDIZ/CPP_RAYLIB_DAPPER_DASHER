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
    int gravity{1}; // (pixels/frame)/frame
    //Is rentangle in the air?
    bool isInAir{false};
    // jump velocity
    const int jumpVel{-22};

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
        DrawRectangle(windowWidht/2, posY, widht, height, BLUE);

        //Update Y position
        posY += velocity;

        // apply gravity
        if(posY >= windowHeight - height)
        {
            //rentangle is on the ground
            isInAir = false;
            velocity = 0;
        }
        else
        {
            // rentangle is in the air
            isInAir = true;
            velocity += gravity;
        }

        //Moving codes
        if(IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity+=jumpVel;
        }

        //End drawing
        EndDrawing();

    }
}