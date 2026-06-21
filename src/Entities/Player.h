#pragma once
#include <raylib.h>
#include "../Interactions.h"
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
    void SetName();
    void Interact();
  private:
    Vector2 getInteractTargetTile();
    Interactions interactions;
};