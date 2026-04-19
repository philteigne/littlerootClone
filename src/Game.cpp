#include <vector>
#include <deque>
#include <iostream>
#include "Game.h"
#include "./Map/GroundLayer.h"
#include "./Display/ViewPort.h"

Game::Game(int colCount, int rowCount, int cellSize) 
  : playerPosition({13, 20}),
    colCount(colCount),
    rowCount(rowCount),
    cellSize(cellSize),
    currentMap(LoadMap()),
    mapTiles(LoadTiles(playerPosition)),
    viewPort(ViewPort(mapTiles, cellSize))
  {
    Draw();
  }


void Game::Draw() {
  mapTiles = LoadTiles(playerPosition);
  viewPort.Draw(mapTiles);

}

void Game::HandleInput() {
  int keyPressed = GetKeyPressed();

  switch(keyPressed) {
    case KEY_UP:
      playerPosition.y -= 1;
      break;
    
    case KEY_RIGHT:
      playerPosition.x += 1;
      break;

    case KEY_DOWN:
      playerPosition.y += 1;
      break;

    case KEY_LEFT:
      playerPosition.x -= 1;
      break;
  }
}

GroundLayer Game::LoadMap() {
  GroundLayer groundLayer = GroundLayer();
  
  return groundLayer;
}

LayerCells Game::LoadTiles(Vector2 playerPosition) {
  int xOffset = (colCount - 1) / 2; // x-offset: half of the total columns excluding middle
  int yOffset = (rowCount - 1) / 2; // y-offset: half of the total rows excluding middle

  Vector2 visiblePos = {
    playerPosition.x - xOffset, // x-position, where viewport starts
    playerPosition.y - yOffset // y-position, where viewport starts
  };

  LayerCells visibleTiles = {};

  for (int row = visiblePos.y; row < visiblePos.y + rowCount; ++row) {
    std::deque<std::string> loadedRow = {};
    for (int col = visiblePos.x; col < visiblePos.x + colCount; ++col) {
      loadedRow.push_back(currentMap.cells[row][col]);
    }

    visibleTiles.push_back(loadedRow);
  };

  return visibleTiles;
}