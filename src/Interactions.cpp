#include <iostream>
#include "Interactions.h"
#include "./Entities/Player.h"
#include "./Overlays/TextBox.h"

Interactions::Interactions(Player& player, TextBox& textBox)
  : player(player),
  textBox(textBox)
{
  // Default function at index 0
  interactionMap.push_back([](){});

  // 01: Mom House Sign
  interactionMap.push_back([this] {
    this->textBox.Show(this->player.name + "'s HOUSE");
  });

  // 02: Professor Birch House Sign
  interactionMap.push_back([this] {
    this->textBox.Show("PROF. BIRCH'S HOUSE");
  });
  
  // 03: Professor Birch Pokemon Lab Sign
  interactionMap.push_back([this] {
    this->textBox.Show("PROF. BIRCH'S POKéMON LAB");
  });

  // 04: Littleroot Town Sign
  interactionMap.push_back([this] {
    this->textBox.Show("LITTLEROOT TOWN\n\"A town that can't be shaded any hue.\"");
  });

}