#include "Tile.h"
#include <functional>

Tile::Tile(
  std::string groundLayer,
  std::string objectLayer,
  bool isAccessible,
  std::function<void()> onEnter(),
  std::function<void()> onInteract()
) {
  this -> groundLayer = groundLayer;
  this -> objectLayer = objectLayer;
  this -> isAccessible = isAccessible;
  this -> onEnter() = onEnter;
  this -> onInteract() = onInteract;
}

std::function<void()> Tile::onEnter()
{
  return std::function<void()>();
}

std::function<void()> Tile::onInteract()
{
  return std::function<void()>();
}
