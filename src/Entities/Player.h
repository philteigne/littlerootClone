#pragma once
#include <raylib.h>
#include "../Interactions.h"
#include "Character.h"

class Player : public Character {
  public:
    Player(
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
    );
    void SetName();
    int Interact(InteractionMap& interactionMap);
  private:
};