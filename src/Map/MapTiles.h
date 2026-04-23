#pragma once
#include <deque>
#include <string>
#include "Tile.h"

class MapTiles {
  public:
    MapTiles(
      int colCount,
      int rowCount,
      int cellSize
    );
    void Draw(
      Vector2 center
    );
    std::deque<std::deque<Tile>> tiles;
  private:
    int colCount;
    int rowCount;
    int cellSize;
    std::string currentMap;
    Color GetTileColor(std::string tile, std::string layer);
};