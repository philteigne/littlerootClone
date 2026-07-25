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

  // 01: NPC 01
  interactionMap.push_back([this] {
    this->textBox.Show("If you use a PC, you can store items and Pokémon.");
    // TODO: add continue to textbox for next message
    // this->textBox.Show("The power of science is staggering!");
  });

  // 02: NPC 02
  interactionMap.push_back([this] {
    this->textBox.Show("Um, um, um!");
    // this->textBox.Show("If you go outside and go in the grass, wild Pokémon will jump out!");
  });

  // 03: NPC 03
  interactionMap.push_back([this] {
    this->textBox.Show("PROF. BIRCH spends days in his LAB studying, then he'll suddenly go out in");
    // this->textBox.Show("the wild to do more research...");
    // this->textBox.Show("When does PROF. BIRCH spend time at home?");
  });

  // 11: Mom House Sign
  interactionMap.push_back([this] {
    this->textBox.Show(this->player.name + "'s HOUSE");
  });

  // 12: Professor Birch House Sign
  interactionMap.push_back([this] {
    this->textBox.Show("PROF. BIRCH'S HOUSE");
  });
  
  // 13: Professor Birch Pokemon Lab Sign
  interactionMap.push_back([this] {
    this->textBox.Show("PROF. BIRCH'S POKéMON LAB");
  });

  // 14: Littleroot Town Sign
  interactionMap.push_back([this] {
    this->textBox.Show("LITTLEROOT TOWN\n“A town that can't be shaded any hue.”");
  });

}