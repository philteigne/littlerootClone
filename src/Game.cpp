#include <vector>
#include <deque>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "Game.h"
#include "./Textures.h"
#include "Textures.h"
#include "Direction.h"

Game::Game(int colCount, int rowCount, int cellSize) 
  : colCount(colCount),
    rowCount(rowCount),
    cellSize(cellSize),
    textures(),
    player(Player(
      {13, 20},
      textures.EPlayerUp,
      textures.EPlayerRight,
      textures.EPlayerDown,
      textures.EPlayerLeft
    ))
  {
    // Top Left coordinate of the visible screen
    displayOrigin = {player.position.x - ((colCount - 1) / 2), player.position.y - ((rowCount - 1) / 2)};
    SetVisibleBounds();

    BGLayerMap bgLayer = Maps::LittlerootTown::bgLayerMap;
    FGLayerMap fgLayer = Maps::LittlerootTown::fgLayerMap;

    // This is assuming that all maps are perfect rectangles and all layers are the same size
    int layerRowCount = bgLayer.size();
    int layerColCount = bgLayer[0].size();
    for (int row = 0; row < layerRowCount; ++row) {
      for (int col = 0; col < layerColCount; ++col) {
        DrawableTexture bgTexture = DrawableTexture(
          col,
          row,
          cellSize,
          bgLayer[row][col],
          textures
        );
        bgTextures.push_back(bgTexture);

        DrawableTexture fgTexture = DrawableTexture(
          col,
          row,
          cellSize,
          fgLayer[row][col],
          textures
        );
        fgTextures.push_back(fgTexture);

      }
    }
  }


void Game::Draw() {
  // Draw Background Textures
  for (DrawableTexture bgTexture : bgTextures) {
    if (bgTexture.shouldDraw(visibleBounds)) {        
      bgTexture.Draw(displayOrigin);
    }
  }

  // Draw Entities
  player.Draw(
    (player.position.x - displayOrigin.x) * cellSize,
    (player.position.y - displayOrigin.y - 1) * cellSize
  );

  // Draw Foreground Textures
  for (DrawableTexture fgTexture : fgTextures) {
    if (fgTexture.shouldDraw(visibleBounds)) {        
      fgTexture.Draw(displayOrigin);
    }
  }
}

void Game::HandleInput() {
  int keyPressed = GetKeyPressed();

  switch(keyPressed) {
    case KEY_UP:
      player.Move(Direction::Up);
      CenterDisplay();
      break;
    
    case KEY_RIGHT:
      player.Move(Direction::Right);
      CenterDisplay();
      break;

    case KEY_DOWN:
      player.Move(Direction::Down);
      CenterDisplay();
      break;

    case KEY_LEFT:
      player.Move(Direction::Left);
      CenterDisplay();
      break;
  };

  SetVisibleBounds();
}

void Game::SetVisibleBounds() {
  float displayWidth = colCount * cellSize;
  float displayHeight = rowCount * cellSize;
  visibleBounds = Rectangle{
    displayOrigin.x * cellSize,
    displayOrigin.y * cellSize,
    displayWidth,
    displayHeight
  };
}

void Game::CenterDisplay() {
  displayOrigin = Vector2{
    player.position.x - ((colCount - 1) / 2),
    player.position.y - ((rowCount - 1) / 2)
  };
}
