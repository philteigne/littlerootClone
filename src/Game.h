#pragma once
#include <raylib.h>
#include <vector>
#include <deque>
#include "./Map/MapTiles.h"
#include "./Entities/Player.h"
#include "./Entities/Character.h"
#include "Textures.h"

class Game {
  public:
    Game(
      int colCount,
      int rowCount,
      int cellSize,
      Textures textures
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
    Textures textures;
};