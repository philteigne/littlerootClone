#pragma once
#include <raylib.h>
#include <string>
#include "../Direction.h"

class Character {
  public:
    Character(
      Vector2 position,
      Texture2D EPlayerUp,
      Texture2D EPlayerUpWalk1,
      Texture2D EPlayerUpWalk2,
      Texture2D EPlayerRight,
      Texture2D EPlayerRightWalk1,
      Texture2D EPlayerRightWalk2,
      Texture2D EPlayerDown,
      Texture2D EPlayerDownWalk1,
      Texture2D EPlayerDownWalk2,
      Texture2D EPlayerLeft,
      Texture2D EPlayerLeftWalk1,
      Texture2D EPlayerLeftWalk2
    );
    Vector2 position;
    Vector2 positionAnchor;
    Direction facing; // up right down left
    std::string name;
    bool isMoving = false;
    void Draw(int posX, int posY);
    void Update();
    void Move(Direction direction);
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
    int movementAnimationFrame = 0;
    int movementAnimationFrameCount = 20;
    int textureVariant = 1; // 1, 2
    bool isAccessibleTile(Vector2 targetTile);
    void setPartialPosition(int stepsCount, int currentStep, Vector2 directionVecto);
};