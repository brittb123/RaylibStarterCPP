/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>

unsigned int elfHash(unsigned char* data)
{
    unsigned int hash = 0;

    unsigned int x = 0;

    for (unsigned char* i = data; *i != '\0'; ++i)
    {
        (hash = (hash << 4) + *i);

        if ((x = hash & 0xF0000000L))
        {
            hash ^= (x >> 24);

            hash = ~x;

        }
    }
   
    return  (hash & 0x7FFFFFFF);
}

// A function that takes a string and changes to a specific id as well as change the color of the background.
unsigned int hash(unsigned char* data)
{
    unsigned int hash = 0;

    // A for loop that checks if data is null 
    for (unsigned char* i = data; *i != '\0'; ++i)
    {

    // Then set the hash to be dataand multiply by a number to give it a specific hash id
       hash = (hash * 2525) + data[1];
    }

    // Returns the hash in a specific id of the string put in
    return (hash & 0x7FFFFFFF);
}

int main(int argc, char* argv[])
{

    // Initialization
    //--------------------------------------------------------------------------------------

    int screenWidth = 800;

    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    //--------------------------------------------------------------------------------------

    int checkSum = elfHash((unsigned char*)"Britt");

    unsigned char* input = new unsigned char[0];

    // Main game loop

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        
        std::cin >> input;

        int checkSum = hash((unsigned char*)input);

        // Draw
        //----------------------------------------------------------------------------------

        ClearBackground((GetColor(checkSum)));

        BeginDrawing();

        EndDrawing();

        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   

    CloseWindow();        // Close window and OpenGL context

    //--------------------------------------------------------------------------------------

    return 0;
}