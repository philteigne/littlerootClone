#pragma once
#include <raylib.h>
#include <vector>
#include "./Display/Viewport.h"
#include "./Map/GroundLayer.h"

class Game {
  public:
    Game(
      int colCount,
      int rowCount,
      int cellSize
    );
    void Draw();
    void HandleInput();
    GroundLayer LoadMap();
    LayerCells LoadTiles(Vector2 playerPosition);
  private:
    Vector2 playerPosition;
    int colCount;
    int rowCount;
    int cellSize;
    GroundLayer currentMap;
    LayerCells mapTiles;
    ViewPort viewPort;
};