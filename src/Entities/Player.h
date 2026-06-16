#pragma once
#include <raylib.h>
#include "Character.h"

class Player : public Character {
  public:
    Player(
      Vector2 position,
      Texture2D EPlayerUp,
      Texture2D EPlayerRight,
      Texture2D EPlayerDown,
      Texture2D EPlayerLeft
    );
};