#pragma once
#include <string>
#include <functional>
#include <raylib.h>
#include "../Consts/Maps.h"
#include "../Textures.h"

class Tile {
  public:
    Tile(
      GroundTexture groundLayer,
      ObjectTexture objectLayer,
      Textures textures,
      bool isAccessible = true,
      std::function<void()> onEnter = nullptr,
      std::function<void()> onInteract = nullptr
    );
    Texture2D groundTexture;
    Texture2D entityTexture;
    Texture2D objectTexture;
    bool isAccessible;
    void Enter();
    void Interact();
    GroundTexture groundLayer;
    ObjectTexture objectLayer;
  private:
    std::function<void()> onEnter;
    std::function<void()> onInteract;
    void LoadGroundTexture();
    void LoadObjectTexture();
    Textures textures;
};