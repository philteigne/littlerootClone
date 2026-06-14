#pragma once
#include <raylib.h>
#include <vector>
#include <deque>
#include "./Map/MapTiles.h"
#include "./Map/DrawableTexture.h"
#include "./Entities/Player.h"
#include "./Entities/Character.h"
#include "Textures.h"

class Game {
  public:
    Game(
      int colCount,
      int rowCount,
      int cellSize
    );
    void Draw();
    void HandleInput();
    std::vector<DrawableTexture> bgTextures;
    std::vector<DrawableTexture> fgTextures;
    Rectangle visibleBounds;
  private:
    Player player;
    std::deque<Character> characterList;
    int colCount;
    int rowCount;
    int cellSize;
    MapTiles map;
    Textures textures;
    Vector2 displayOrigin;
    void SetVisibleBounds();
    void MoveDisplay(Direction);
};