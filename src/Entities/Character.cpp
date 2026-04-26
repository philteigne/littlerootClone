#include "Character.h"
#include <raylib.h>
#include <raymath.h>
#include <iostream>

Character::Character(
  Vector2 position,
  char* texturePathUp,
  char* texturePathRight,
  char* texturePathDown,
  char* texturePathLeft
) 
  : position(position),
    texturePathUp(texturePathUp),
    texturePathRight(texturePathRight),
    texturePathDown(texturePathDown),
    texturePathLeft(texturePathLeft),
    facing(Up)
  {}

void Character::Draw(int posX, int posY)
{
  switch (facing) {
    case Up:
      texture = LoadTexture(texturePathUp);
      break;
    case Right:
      texture = LoadTexture(texturePathRight);
      break;
    case Down:
      texture = LoadTexture(texturePathDown);
      break;
    case Left:
      texture = LoadTexture(texturePathLeft);
      break;
    default:
      texture = LoadTexture("../assets/textures/default.png");
  }

  DrawTexture(texture, posX, posY, WHITE);
}

void Character::Move(Direction direction) {
  switch (direction) {
    case Up:
      position = Vector2Add(position, {0, -1});
      facing = Up;
      break;

    case Right:
      position = Vector2Add(position, {1, 0});
      facing = Right;
      break;

    case Down:
      position = Vector2Add(position, {0, 1});
      facing = Down;
      break;

    case Left:
      position = Vector2Add(position, {-1, 0});
      facing = Left;
      break;

    default:
      break;
  }


}
