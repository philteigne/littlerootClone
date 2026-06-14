#include "Player.h"

Player::Player(Vector2 position)
  : Character(
      position,
      "src/assets/textures/e.player-up.png",
      "src/assets/textures/e.player-right.png",
      "src/assets/textures/e.player-down.png",
      "src/assets/textures/e.player-left.png"
    )
  {}