#pragma once
#include <raylib.h>
#include <vector>
#include <functional>

class Player;
class TextBox;

class Interactions {
  public:
    Interactions(Player& player, TextBox& textBox);
    std::vector<std::function<void()>> interactionMap;
  private:
    Player& player;
    TextBox& textBox;
};