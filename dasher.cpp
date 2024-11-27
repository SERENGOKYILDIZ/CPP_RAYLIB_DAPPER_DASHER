#include "raylib.h"

int main()
{
    //Window dimensions
    const int windowWidth{512};
    const int windowHeight{380};

    //Init window
    InitWindow(windowWidth, windowHeight, "DAPPER DASHER GAME");

    //For sprite sheet to texture file
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    //For sprite sheet to rectangle
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6; //Because there are 6 images.
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    //For sprite sheet to position
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;
    
    //Speed and gravity
    int velocity{0};            // (pixels/second)
    int gravity{1'000};         // (pixels/second)/second

    //Is rentangle in the air?
    bool isInAir{false};
    // jump velocity
    const int jumpVel{-600};    // (pixels/second)

    //animation frame
    int frame{0};

    //Animation times
    const float updateTime{1.0/12.0};
    float runningTime{0.0};

    //Set 60 FPS
    SetTargetFPS(60);

    //Infinite loop
    while (!WindowShouldClose())
    {
        //Start drawing
        BeginDrawing();

        //Get the Delta Time (time since last frame)
        const float dT{GetFrameTime()};

        // apply gravity
        if(scarfyPos.y >= windowHeight - scarfyRec.height)
        {
            //rentangle is on the ground
            isInAir = false;
            velocity = 0;
        }
        else
        {
            // rentangle is in the air
            isInAir = true;
            velocity += gravity * dT;
        }

        //Moving codes
        if(IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity+=jumpVel;
        }
        
        //Update Y position
        scarfyPos.y += velocity * dT;
        
        //Background color
        ClearBackground(WHITE);

        //Draw rentangle
        //DrawRectangle(windowWidth/2, posY, widht, height, BLUE);

        // update running time
        runningTime += dT;
        if(runningTime >= updateTime)
        {
            // update animation frame
            runningTime=0.0;
            scarfyRec.x = frame * scarfyRec.width;
            frame++; 
            if(frame > 5){frame=0;}
        }

        //Draw a texture rectangle
        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        //End drawing
        EndDrawing();
    }
    //For save the our GPU powerdawd
    UnloadTexture(scarfy);
    //Close the window
    CloseWindow();
}