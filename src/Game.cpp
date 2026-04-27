#include <vector>
#include <deque>
#include <iostream>
#include "Game.h"
#include "./Map/MapTiles.h"
#include "Textures.h"

Game::Game(int colCount, int rowCount, int cellSize, Textures textures) 
  : player(Player({13, 20})),
    colCount(colCount),
    rowCount(rowCount),
    cellSize(cellSize),
    map(
      colCount,
      rowCount,
      cellSize,
      player,
      characterList,
      textures
    ),
    textures(textures)
  {
    Draw();
  }


void Game::Draw() {
  map.Draw(player.position);
}

void Game::HandleInput() {
  int keyPressed = GetKeyPressed();

  switch(keyPressed) {
    case KEY_UP:
      player.Move(Up);
      map.Draw(player.position);
      break;
    
    case KEY_RIGHT:
      player.Move(Right);
      map.Draw(player.position);
      break;

    case KEY_DOWN:
      player.Move(Down);
      map.Draw(player.position);
      break;

    case KEY_LEFT:
      player.Move(Left);
      map.Draw(player.position);
      break;
  };
}