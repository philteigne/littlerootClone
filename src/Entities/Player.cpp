#include <raylib.h>
#include "Player.h"

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
  {}