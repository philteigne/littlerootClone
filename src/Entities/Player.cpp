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
  Texture2D EPlayerRight,
  Texture2D EPlayerDown,
  Texture2D EPlayerLeft
) : Character(
      position,
      EPlayerUp,
      EPlayerRight,
      EPlayerDown,
      EPlayerLeft
    )
  {
    SetName();
  }

  void Player::SetName() {
    this->name = "Phil";
  }

  int Player::Interact() {
    // Find target tile interactionId from the player position and the facing direction
    Vector2 targetTile;
    int interactionId = 00;

    switch(this->facing) {
      case Direction::Up:
        targetTile = Vector2Add(this->position, {0, -1});
        interactionId = Maps::LittlerootTown::interactionMap[targetTile.y][targetTile.x];
        break;
      case Direction::Right:
        targetTile = Vector2Add(this->position, {1, 0});
        interactionId = Maps::LittlerootTown::interactionMap[targetTile.y][targetTile.x];
        break;
      case Direction::Down:
        targetTile = Vector2Add(this->position, {0, 1});
        interactionId = Maps::LittlerootTown::interactionMap[targetTile.y][targetTile.x];
        break;
      case Direction::Left:
        targetTile = Vector2Add(this->position, {-1, 0});
        interactionId = Maps::LittlerootTown::interactionMap[targetTile.y][targetTile.x];
        break;
      default:
        break;
    }

    return interactionId;
  }

  Vector2 Player::getInteractTargetTile() {

    return Vector2();
  }
