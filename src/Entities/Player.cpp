#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "../Interactions.h"
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
    ),
    interactions(*this)
  {
    SetName();
  }

  void Player::SetName() {
    this->name = "Phil";
  }

  void Player::Interact() {
    // Find target tile from the player position and the facing direction
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

    if (interactionId == 00) return;

    interactions.interactionMap[interactionId]();
  }

  Vector2 Player::getInteractTargetTile() {

    return Vector2();
  }
