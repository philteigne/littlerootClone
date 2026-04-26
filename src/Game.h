#pragma once
#include <raylib.h>
#include <vector>
#include <deque>
#include "./Map/MapTiles.h"
#include "./Entities/Player.h"
#include "./Entities/Character.h"

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
    Player player;
    std::deque<Character> characterList;
    int colCount;
    int rowCount;
    int cellSize;
    MapTiles map;
};