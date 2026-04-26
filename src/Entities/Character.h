#pragma once
#include <raylib.h>
#include <string>

enum Direction { Up, Right, Down, Left};

class Character {
  public:
    Character(
      Vector2 position,
      char* texturePathUp,
      char* texturePathRight,
      char* texturePathDown,
      char* texturePathLeft
    );
    Vector2 position;
    Direction facing; // up right down left
    void Draw(int posX, int posY);
    void Move(Direction direction);
  private:
    Texture2D texture;
    const char* texturePathUp;
    const char* texturePathRight;
    const char* texturePathDown;
    const char* texturePathLeft;
};