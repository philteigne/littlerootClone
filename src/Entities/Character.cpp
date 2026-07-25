#include "Character.h"
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "../Direction.h"
#include "../Consts/Maps.h"

Character::Character(
  int id,
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
  Texture2D textureLeftWalk2,
  Rectangle moveBounds,
  int moveCooldown,
  std::function<Direction()> determineMoveTarget
) 
  : id(id),
    position(position),
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
    facing(Direction::Down),
    textureDefault(textureDown),
    textureWalk1(textureUpWalk1),
    textureWalk2(textureUpWalk2),
    texture(textureDown),
    moveBounds(moveBounds),
    moveCooldown(moveCooldown),
    determineMoveTarget(determineMoveTarget)
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

void Character::Move(
  Direction direction,
  EntityMap& entityMap,
  InteractionMap& interactionMap,
  CollisionMap& collisionMap
) {
  if (isMoving) return;
  if (moveTimer < moveCooldown) {
    moveTimer++;
    return;
  }
  
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

  if (facing == direction) {
    isMoving = true;
    moveTimer = 0;
  }
  facing = direction;
  texture = textureDefault;

  // if the moveTarget tile is inaccessible overwrite the move target so the player stays
  // in position but still animates
  if (!isAccessibleTile(moveTarget, entityMap, collisionMap)) moveTarget = position;
  if (!isMoving) moveTarget = position;

  entityMap[position.y][position.x] = 00;
  interactionMap[position.y][position.x] = 00;
  entityMap[moveTarget.y][moveTarget.x] = id;
  interactionMap[moveTarget.y][moveTarget.x] = id;
}

void Character::UpdateNPC(
    EntityMap& entityMap,
    InteractionMap& interactionMap,
    CollisionMap& collisionMap
) {
    if (isMoving) {
        Update();
        return;
    }

    Direction direction = determineMoveTarget();
    Vector2 preMoveTarget = getTargetTile(direction);
    if (
      preMoveTarget.x < moveBounds.x ||
      preMoveTarget.x >= moveBounds.x + moveBounds.width ||
      preMoveTarget.y < moveBounds.y ||
      preMoveTarget.y >= moveBounds.y + moveBounds.height
    ) return;

    Move(direction, entityMap, interactionMap, collisionMap);
}

bool Character::isAccessibleTile(
  Vector2 targetTile,
  EntityMap& entityMap,
  CollisionMap& collisionMap
) {
  bool isAccessible = false;

  if (
    collisionMap[targetTile.y][targetTile.x] == 00 &&
    entityMap[targetTile.y][targetTile.x] == 00
  ) {
    isAccessible = true;
  }

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

Vector2 Character::getTargetTile(Direction direction) {
  switch (direction) {
    case Direction::Up:
      return Vector2Add(position, {0, -1});
    case Direction::Right:
      return Vector2Add(position, {1, 0});
    case Direction::Down:
      return Vector2Add(position, {0, 1});
    case Direction::Left:
      return Vector2Add(position, {-1, 0});

  }
  return position;
}
