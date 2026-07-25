#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "../Direction.h"
#include "../Consts/Maps.h"

Player::Player(
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
) : Character(
      99,
      position,
      EPlayerUp,
      EPlayerUpWalk1,
      EPlayerUpWalk2,
      EPlayerRight,
      EPlayerRightWalk1,
      EPlayerRightWalk2,
      EPlayerDown,
      EPlayerDownWalk1,
      EPlayerDownWalk2,
      EPlayerLeft,
      EPlayerLeftWalk1,
      EPlayerLeftWalk2,
      Rectangle{0,0,0,0},
      0,
      []() {
        return Direction::Down;
      }
    )
  {
    SetName();
  }

  void Player::SetName()
  {
    this->name = "Phil";
  }

  int Player::Interact(InteractionMap& interactionMap) {
    // Find target tile interactionId from the player position and the facing direction
    Vector2 targetTile;
    int interactionId = 00;
    if (isMoving) return interactionId;

    switch(this->facing) {
      case Direction::Up:
        targetTile = Vector2Add(this->position, {0, -1});
        interactionId = interactionMap[targetTile.y][targetTile.x];
        break;
      case Direction::Right:
        targetTile = Vector2Add(this->position, {1, 0});
        interactionId = interactionMap[targetTile.y][targetTile.x];
        break;
      case Direction::Down:
        targetTile = Vector2Add(this->position, {0, 1});
        interactionId = interactionMap[targetTile.y][targetTile.x];
        break;
      case Direction::Left:
        targetTile = Vector2Add(this->position, {-1, 0});
        interactionId = interactionMap[targetTile.y][targetTile.x];
        break;
      default:
        break;
    }

    return interactionId;
  }