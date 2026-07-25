#pragma once
#include <raylib.h>
#include <vector>
#include "./Map/DrawableTexture.h"
#include "./Entities/Player.h"
#include "./Entities/Character.h"
#include "Textures.h"
#include "Fonts.h"
#include "./Overlays/TextBox.h"
#include "Interactions.h"
#include "./Consts/Maps.h"

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
    std::vector<Character*> orderedEntities;
    Rectangle visibleBounds;
    EntityMap entityMap;
    InteractionMap interactionMap;
    CollisionMap collisionMap;
  private:
    std::vector<Direction> directionInputBuffer;
    std::vector<Character*> characterList;
    int colCount;
    int rowCount;
    int cellSize;
    Textures textures;
    Fonts fonts;
    TextBox textBox;
    double lastUpdateTime = 0;
    Vector2 displayOrigin;
    Player player;
    Character npc01;
    Character npc02;
    Character npc03;
    Interactions interactions;
    void SetVisibleBounds();
    void CenterDisplay();
    void RemoveDirectionInput(Direction direction);
};