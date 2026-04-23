#include <vector>
#include <deque>
#include <iostream>
#include "Game.h"
#include "./Map/MapTiles.h"

Game::Game(int colCount, int rowCount, int cellSize) 
  : playerPosition({13, 20}),
    colCount(colCount),
    rowCount(rowCount),
    cellSize(cellSize),
    map(
      colCount,
      rowCount,
      cellSize
    )
  {
    Draw();
  }


void Game::Draw() {
  map.Draw(playerPosition);
}

void Game::HandleInput() {
  int keyPressed = GetKeyPressed();

  switch(keyPressed) {
    case KEY_UP:
      playerPosition.y -= 1;
      map.Draw(playerPosition);
      break;
    
    case KEY_RIGHT:
      playerPosition.x += 1;
      map.Draw(playerPosition);
      break;

    case KEY_DOWN:
      playerPosition.y += 1;
      map.Draw(playerPosition);
      break;

    case KEY_LEFT:
      playerPosition.x -= 1;
      map.Draw(playerPosition);
      break;
  };
}