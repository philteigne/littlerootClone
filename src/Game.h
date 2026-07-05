#pragma once
#include <raylib.h>
#include <vector>
#include <deque>
#include "./Map/DrawableTexture.h"
#include "./Entities/Player.h"
#include "./Entities/Character.h"
#include "Textures.h"
#include "Fonts.h"
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
    void Update();
    void HandleInput();
    std::vector<DrawableTexture> bgTextures;
    std::vector<DrawableTexture> fgTextures;
    Rectangle visibleBounds;
  private:
    std::vector<Direction> directionInputBuffer;
    std::deque<Character> characterList;
    int colCount;
    int rowCount;
    int cellSize;
    Textures textures;
    Fonts fonts;
    TextBox textBox;
    double lastUpdateTime = 0;
    Vector2 displayOrigin;
    Player player;
    Interactions interactions;
    void SetVisibleBounds();
    void CenterDisplay();
    void RemoveDirectionInput(Direction direction);
};