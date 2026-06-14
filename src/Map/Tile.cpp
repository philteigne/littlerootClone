#include "Tile.h"
#include <functional>
#include "../Consts/Maps.h"
#include "../Textures.h"

Tile::Tile(
  bool isAccessible,
  std::function<void()> onEnter,
  std::function<void()> onInteract
) :
  isAccessible(isAccessible),
  onEnter(onEnter),
  onInteract(onInteract)
{}

void Tile::Enter() {
  onEnter();
}

void Tile::Interact() {
  onInteract();
}