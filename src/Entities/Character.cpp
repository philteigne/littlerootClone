#include "Character.h"
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "../Direction.h"
#include "../Consts/Maps.h"

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
      moveTarget = Vector2Add(position, {0, -1});
      if (isAccessibleTile(moveTarget)) {
        position = moveTarget;
      }
      facing = Direction::Up;
      break;

    case Direction::Right:
      moveTarget = Vector2Add(position, {1, 0});
      if (isAccessibleTile(moveTarget)) {
        position = moveTarget;
      }
      facing = Direction::Right;
      break;

    case Direction::Down:
      moveTarget = Vector2Add(position, {0, 1});
      if (isAccessibleTile(moveTarget)) {
        position = moveTarget;
      }
      facing = Direction::Down;
      break;

    case Direction::Left:
      moveTarget = Vector2Add(position, {-1, 0});
      if (isAccessibleTile(moveTarget)) {
        position = moveTarget;
      }
      facing = Direction::Left;
      break;

    default:
      break;
  }
}

bool Character::isAccessibleTile(Vector2 targetTile) {
  CollisionMap collisionMap = Maps::LittlerootTown::collisionMap;
  bool isAccessible;

  collisionMap[targetTile.y][targetTile.x] == 00 ?
    isAccessible = true :
    isAccessible = false;

  return isAccessible;
}
