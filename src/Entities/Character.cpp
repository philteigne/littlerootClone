#include "Character.h"
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "../Direction.h"

Character::Character(
  Vector2 position,
  Texture2D textureUp,
  Texture2D textureRight,
  Texture2D textureDown,
  Texture2D textureLeft
) 
  : position(position),
    textureUp(textureUp),
    textureRight(textureRight),
    textureDown(textureDown),
    textureLeft(textureLeft),
    facing(Direction::Up)
  {}

void Character::Draw(int posX, int posY)
{
  switch (facing) {
    case Direction::Up:
      texture = textureUp;
      break;
    case Direction::Right:
      texture = textureRight;
      break;
    case Direction::Down:
      texture = textureDown;
      break;
    case Direction::Left:
      texture = textureLeft;
      break;
    default:
      texture = textureDown;
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
