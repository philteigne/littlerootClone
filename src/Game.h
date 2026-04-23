#pragma once
#include <raylib.h>
#include <vector>
#include "./Map/MapTiles.h"

class Game {
  public:
    Game(
      int colCount,
      int rowCount,
      int cellSize
    );
    void Draw();
    void HandleInput();
  private:
    Vector2 playerPosition;
    int colCount;
    int rowCount;
    int cellSize;
    MapTiles map;
};