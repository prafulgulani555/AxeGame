// #include <>
#include "raylib.h"

int main() {
    int width;
    int height;
    width = 350;
    height = 200;
    InitWindow(350, 200, "game window");

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    } 
}