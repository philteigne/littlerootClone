#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "Game.h"
#include "Textures.h"
#include "Direction.h"
#include "Interactions.h"

Game::Game(int colCount, int rowCount, int cellSize) 
  : colCount(colCount),
    rowCount(rowCount),
    cellSize(cellSize),
    textures(),
    fonts(),
    textBox(
      rowCount,
      colCount,
      cellSize,
      textures.OLTextBox,
      fonts.fontDialog
    ),
    player(Player(
      {13, 20},
      textures.EPlayerUp,
      textures.EPlayerUpWalk1,
      textures.EPlayerUpWalk2,
      textures.EPlayerRight,
      textures.EPlayerRightWalk1,
      textures.EPlayerRightWalk2,
      textures.EPlayerDown,
      textures.EPlayerDownWalk1,
      textures.EPlayerDownWalk2,
      textures.EPlayerLeft,
      textures.EPlayerLeftWalk1,
      textures.EPlayerLeftWalk2
    )),
    interactions(player, textBox)
  { 
    // Top Left coordinate of the visible screen
    displayOrigin = {player.position.x - ((colCount - 1) / 2), player.position.y - (rowCount / 2)};
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

  // Draw Overlay Textures
  textBox.Draw();
}

void Game::Update() {
  player.Update();
}

void Game::HandleInput() {
  // Decide which input type to listen to
  if (textBox.isVisible) {
    // textBox is visible, only textBox interactions should be listened to
    if (IsKeyPressed(KEY_Z)) textBox.Hide();
    else if (IsKeyPressed(KEY_X)) textBox.Hide();

    return;
  }

  // Movement enabled
  if (IsKeyPressed(KEY_Z)) {
    interactions.interactionMap[player.Interact()]();
  }

  // If multiple keys are held down, use the valid (latest pushed) key
  if (IsKeyPressed(KEY_UP)) directionInputBuffer.push_back(Direction::Up);
  if (IsKeyReleased(KEY_UP)) RemoveDirectionInput(Direction::Up);
  if (IsKeyPressed(KEY_RIGHT)) directionInputBuffer.push_back(Direction::Right);
  if (IsKeyReleased(KEY_RIGHT)) RemoveDirectionInput(Direction::Right);
  if (IsKeyPressed(KEY_DOWN)) directionInputBuffer.push_back(Direction::Down);
  if (IsKeyReleased(KEY_DOWN)) RemoveDirectionInput(Direction::Down);
  if (IsKeyPressed(KEY_LEFT)) directionInputBuffer.push_back(Direction::Left);
  if (IsKeyReleased(KEY_LEFT)) RemoveDirectionInput(Direction::Left);

  if (IsKeyDown(KEY_UP) && directionInputBuffer.back() == Direction::Up) {
    player.Move(Direction::Up);
  }
  if (IsKeyDown(KEY_RIGHT) && directionInputBuffer.back() == Direction::Right) {
    player.Move(Direction::Right);
  }
  if (IsKeyDown(KEY_DOWN) && directionInputBuffer.back() == Direction::Down) {
    player.Move(Direction::Down);
  }
  if (IsKeyDown(KEY_LEFT) && directionInputBuffer.back() == Direction::Left) {
    player.Move(Direction::Left);
  }

  CenterDisplay();

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
    player.position.y - (rowCount / 2)
  };
}

void Game::RemoveDirectionInput(Direction direction) {
  directionInputBuffer.erase(
    std::remove(
      directionInputBuffer.begin(),
      directionInputBuffer.end(),
      direction
    ),
    directionInputBuffer.end()
  );
}
