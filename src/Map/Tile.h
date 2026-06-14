#pragma once
#include <string>
#include <functional>
#include <raylib.h>
#include "../Consts/Maps.h"
#include "../Textures.h"

class Tile {
  public:
    Tile(
      bool isAccessible = true,
      std::function<void()> onEnter = nullptr,
      std::function<void()> onInteract = nullptr
    );
    bool isAccessible;
    void Enter();
    void Interact();
  private:
    std::function<void()> onEnter;
    std::function<void()> onInteract;
};