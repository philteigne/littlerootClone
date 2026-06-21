#pragma once
#include <raylib.h>
#include <vector>
#include <deque>
#include "./Map/DrawableTexture.h"
#include "./Entities/Player.h"
#include "./Entities/Character.h"
#include "Textures.h"
#include "./Overlays/TextBox.h"
#include "Interactions.h"

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
  std::deque<Character> characterList;
    int colCount;
    int rowCount;
    int cellSize;
    Textures textures;
    TextBox textBox;
    Vector2 displayOrigin;
    Player player;
    Interactions interactions;
    void SetVisibleBounds();
    void CenterDisplay();
};