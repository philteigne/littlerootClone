#include <iostream>
#include "Interactions.h"
#include "./Entities/Player.h"

Interactions::Interactions(Player& player)
  : player(player) {
  // Default function at index 0
  interactionMap.push_back([](){});

  // 01: Mom House Sign
  interactionMap.push_back([this] {
    std::cout << this->player.name << "'s HOUSE";
  });

  // 02: Professor Birch House Sign
  interactionMap.push_back([this] {
    std::cout << "PROF. BIRCH'S HOUSE";
  });
  
  // 03: Professor Birch Pokemon Lab Sign
  interactionMap.push_back([this] {
    std::cout << "PROF. BIRCH'S POKeMON LAB";
  });

  // 04: Littleroot Town Sign
  interactionMap.push_back([this] {
    std::cout << "LITTLEROOT TOWN\n" << "\"A town that can\'t be shaded any hue.\"";
  });

}