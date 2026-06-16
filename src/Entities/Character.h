#pragma once
#include <raylib.h>
#include <string>
#include "../Direction.h"

class Character {
  public:
    Character(
      Vector2 position,
      Texture2D textureUp,
      Texture2D textureRight,
      Texture2D textureDown,
      Texture2D textureLeft
    );
    Vector2 position;
    Direction facing; // up right down left
    void Draw(int posX, int posY);
    void Move(Direction direction);
  private:
    Texture2D texture;
    Texture2D textureUp;
    Texture2D textureRight;
    Texture2D textureDown;
    Texture2D textureLeft;
};