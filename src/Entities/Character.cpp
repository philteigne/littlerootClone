#include "Character.h"
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "../Direction.h"
#include "../Consts/Maps.h"

Character::Character(
  Vector2 position,
  Texture2D textureUp,
  Texture2D textureUpWalk1,
  Texture2D textureUpWalk2,
  Texture2D textureRight,
  Texture2D textureRightWalk1,
  Texture2D textureRightWalk2,
  Texture2D textureDown,
  Texture2D textureDownWalk1,
  Texture2D textureDownWalk2,
  Texture2D textureLeft,
  Texture2D textureLeftWalk1,
  Texture2D textureLeftWalk2
) 
  : position(position),
    positionAnchor(position),
    textureUp(textureUp),
    textureUpWalk1(textureUpWalk1),
    textureUpWalk2(textureUpWalk2),
    textureRight(textureRight),
    textureRightWalk1(textureRightWalk1),
    textureRightWalk2(textureRightWalk2),
    textureDown(textureDown),
    textureDownWalk1(textureDownWalk1),
    textureDownWalk2(textureDownWalk2),
    textureLeft(textureLeft),
    textureLeftWalk1(textureLeftWalk1),
    textureLeftWalk2(textureLeftWalk2),
    facing(Direction::Up),
    textureDefault(textureUp),
    textureWalk1(textureUpWalk1),
    textureWalk2(textureUpWalk2),
    texture(textureUp)
  {}

void Character::Draw(int posX, int posY) {
  DrawTexture(texture, posX, posY, WHITE);
}

void Character::Update() {
  if (!isMoving) return;

  Vector2 directionVector = Vector2Subtract(moveTarget, positionAnchor);
  switch (movementAnimationFrame) {
    case 1:
      if (textureVariant == 1) {
        texture = textureWalk1;
        textureVariant = 2;
      } else {
        texture = textureWalk2;
        textureVariant = 1;
      }

      setPartialPosition(
        movementAnimationFrameCount,
        movementAnimationFrame,
        directionVector
      );
      ++movementAnimationFrame;
      break;
    case 18:
      texture = textureDefault;
      
      setPartialPosition(
        movementAnimationFrameCount,
        movementAnimationFrame,
        directionVector
      );
      ++movementAnimationFrame;
      break;
    case 19:
      position = moveTarget;
      positionAnchor = position;
      movementAnimationFrame = 0;
      isMoving = false;
      break;
    default:
      setPartialPosition(
        movementAnimationFrameCount,
        movementAnimationFrame,
        directionVector
      );
      ++movementAnimationFrame;
      break;
  };
}

void Character::Move(Direction direction) {
  if (isMoving) return;
  
  switch (direction) {
    case Direction::Up:
      moveTarget = Vector2Add(position, {0, -1});
      textureDefault = textureUp;
      textureWalk1 = textureUpWalk1;
      textureWalk2 = textureUpWalk2;
      break;
    case Direction::Right:
      moveTarget = Vector2Add(position, {1, 0});
      textureDefault = textureRight;
      textureWalk1 = textureRightWalk1;
      textureWalk2 = textureRightWalk2;
      break;
    case Direction::Down:
      moveTarget = Vector2Add(position, {0, 1});
      textureDefault = textureDown;
      textureWalk1 = textureDownWalk1;
      textureWalk2 = textureDownWalk2;
      break;
    case Direction::Left:
      moveTarget = Vector2Add(position, {-1, 0});
      textureDefault = textureLeft;
      textureWalk1 = textureLeftWalk1;
      textureWalk2 = textureLeftWalk2;
      break;
    default:
      break;
  }

  if (facing == direction) isMoving = true;
  facing = direction;
  texture = textureDefault;

  // if the moveTarget tile is inaccessible overwrite the move target so the player stays
  // in position but still animates
  if (!isAccessibleTile(moveTarget)) moveTarget = position;
}

bool Character::isAccessibleTile(Vector2 targetTile) {
  CollisionMap collisionMap = Maps::LittlerootTown::collisionMap;
  bool isAccessible;

  collisionMap[targetTile.y][targetTile.x] == 00 ?
    isAccessible = true :
    isAccessible = false;

  return isAccessible;
}

void Character::setPartialPosition(int stepsCount, int currentStep, Vector2 directionVector) {
  float movementRatio = (1.0f / stepsCount) * (currentStep + 1);

  position = Vector2Add(
    positionAnchor,
    Vector2Multiply(
      directionVector,
      {movementRatio, movementRatio}
    )
  );
}
