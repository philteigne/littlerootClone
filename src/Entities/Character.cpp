#include "Character.h"
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "../Direction.h"

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
    facing(Direction::Up)
  {}

void Character::Draw(int posX, int posY)
{
  switch (facing) {
    case Direction::Up:
      texture = LoadTexture(texturePathUp);
      break;
    case Direction::Right:
      texture = LoadTexture(texturePathRight);
      break;
    case Direction::Down:
      texture = LoadTexture(texturePathDown);
      break;
    case Direction::Left:
      texture = LoadTexture(texturePathLeft);
      break;
    default:
      texture = LoadTexture("../assets/textures/default.png");
  }

  DrawTexture(texture, posX, posY, WHITE);
}

void Character::Move(Direction direction) {
  switch (direction) {
    case Direction::Up:
      position = Vector2Add(position, {0, -1});
      facing = Direction::Up;
      break;

    case Direction::Right:
      position = Vector2Add(position, {1, 0});
      facing = Direction::Right;
      break;

    case Direction::Down:
      position = Vector2Add(position, {0, 1});
      facing = Direction::Down;
      break;

    case Direction::Left:
      position = Vector2Add(position, {-1, 0});
      facing = Direction::Left;
      break;

    default:
      break;
  }


}
