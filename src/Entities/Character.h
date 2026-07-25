#pragma once
#include <raylib.h>
#include <string>
#include <functional>
#include "../Direction.h"
#include "../Consts/Maps.h"

class Character {
  public:
    Character(
      int id,
      Vector2 position,
      Texture2D TextureUp,
      Texture2D TextureUpWalk1,
      Texture2D TextureUpWalk2,
      Texture2D TextureRight,
      Texture2D TextureRightWalk1,
      Texture2D TextureRightWalk2,
      Texture2D TextureDown,
      Texture2D TextureDownWalk1,
      Texture2D TextureDownWalk2,
      Texture2D TextureLeft,
      Texture2D TextureLeftWalk1,
      Texture2D TextureLeftWalk2,
      Rectangle moveBounds,
      int moveCooldown,
      std::function<Direction()> determineMoveTarget
    );
    int id;
    Vector2 position;
    Vector2 positionAnchor;
    std::string name;
    Direction facing; // up right down left
    bool isMoving = false;
    void Draw(int posX, int posY);
    void Update();
    void Move(
      Direction direction,
      EntityMap& entityMap,
      InteractionMap& interactionMap,
      CollisionMap& collisionMap
    );
    void UpdateNPC(
      EntityMap& entityMap,
      InteractionMap& interactionMap,
      CollisionMap& collisionMap
    );
  private:
    Texture2D texture;
    Texture2D textureDefault;
    Texture2D textureWalk1;
    Texture2D textureWalk2;
    Texture2D textureUp;
    Texture2D textureUpWalk1;
    Texture2D textureUpWalk2;
    Texture2D textureRight;
    Texture2D textureRightWalk1;
    Texture2D textureRightWalk2;
    Texture2D textureDown;
    Texture2D textureDownWalk1;
    Texture2D textureDownWalk2;
    Texture2D textureLeft;
    Texture2D textureLeftWalk1;
    Texture2D textureLeftWalk2;
    Vector2 moveTarget;
    Rectangle moveBounds;
    int moveCooldown;
    std::function<Direction()> determineMoveTarget;
    int moveTimer = 0;
    int movementAnimationFrame = 0;
    int movementAnimationFrameCount = 20;
    int textureVariant = 1; // 1, 2
    bool isAccessibleTile(
      Vector2 targetTile,
      EntityMap& entityMap,
      CollisionMap& collisionMap
    );
    void setPartialPosition(int stepsCount, int currentStep, Vector2 direction);
    Vector2 getTargetTile(Direction direction);
};