#pragma once
#include <raylib.h>
#include <vector>
#include <functional>

class Player;

class Interactions {
  public:
    Interactions(Player& player);
    std::vector<std::function<void()>> interactionMap;
  private:
    Player& player;
};