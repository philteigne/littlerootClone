#include "Player.h"

Player::Player(Vector2 position)
  : Character(
      position,
      "src/assets/textures/player-up.png",
      "src/assets/textures/player-right.png",
      "src/assets/textures/player-down.png",
      "src/assets/textures/player-left.png"
    )
  {}