#pragma once
#include <deque>
#include <string>
#include "Tile.h"
#include "../Entities/Player.h"
#include "../Entities/Character.h"

class MapTiles {
  public:
    MapTiles(
      int colCount,
      int rowCount,
      int cellSize,
      Player& player,
      std::deque<Character>& characterList
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
    Player& player;
    std::deque<Character>& characterList;
};