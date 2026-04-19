#include <raylib.h>
#include <iostream>
#include "Game.h"

int main() {
    const int SCREEN_WIDTH = 240;
    const int SCREEN_HEIGHT = 160;
    const int GRID_WIDTH = 15;
    const int GRID_HEIGHT = 11;
    const int CELL_SIZE = (SCREEN_WIDTH / GRID_WIDTH);
    const int TARGET_FPS = 60;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pokemon Emerald");
    SetTargetFPS(TARGET_FPS);

    Game game = Game(
        GRID_WIDTH,
        GRID_HEIGHT,
        CELL_SIZE
    );

    while (WindowShouldClose() == false) {
        BeginDrawing();
        // 1. Handle Input
        game.HandleInput();


        // 2. Update

        // 3. Drawing
        ClearBackground(WHITE);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}