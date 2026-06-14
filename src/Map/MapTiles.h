#pragma once
#include <deque>
#include <string>
#include "Tile.h"
#include "../Entities/Player.h"
#include "../Entities/Character.h"
#include "../Textures.h"

class MapTiles {
  public:
    MapTiles(
      int colCount,
      int rowCount,
      int cellSize
    );
    std::deque<std::deque<Tile>> tiles;
    Rectangle visibleBounds;
  private:
    int colCount;
    int rowCount;
    int cellSize;
    std::string currentMap;
    std::deque<Character>& characterList;
    Textures textures;
};