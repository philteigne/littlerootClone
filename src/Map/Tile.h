#pragma once
#include <string>
#include <functional>
#include <raylib.h>

class Tile {
  public:
    Tile(
      std::string groundLayer,
      std::string objectLayer,
      bool isAccessible = true,
      std::function<void()> onEnter() = nullptr,
      std::function<void()> onInteract() = nullptr
    );
    Image groundTexture;
    Image entityTexture;
    Image objectTexture;
    bool isAccessible;
    std::function<void()> onEnter();
    std::function<void()> onInteract();
  private:
    std::string groundLayer;
    std::string objectLayer;
};