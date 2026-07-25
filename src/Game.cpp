#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <random>
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
    entityMap(Maps::LittlerootTown::entityMap),
    interactionMap(Maps::LittlerootTown::interactionMap),
    collisionMap(Maps::LittlerootTown::collisionMap),
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
    npc01(Character(
      01,
      {20, 24},
      textures.ENPC01Up,
      textures.ENPC01UpWalk1,
      textures.ENPC01UpWalk2,
      textures.ENPC01Right,
      textures.ENPC01RightWalk1,
      textures.ENPC01RightWalk2,
      textures.ENPC01Down,
      textures.ENPC01DownWalk1,
      textures.ENPC01DownWalk2,
      textures.ENPC01Left,
      textures.ENPC01LeftWalk1,
      textures.ENPC01LeftWalk2,
      Rectangle{18, 23, 5, 3},
      120,
      []() {
        int number = GetRandomValue(0, 3);
        return static_cast<Direction>(number);
      }
    )),
    npc02(Character(
      02,
      {15, 13},
      textures.ENPC02Up,
      textures.ENPC02UpWalk1,
      textures.ENPC02UpWalk2,
      textures.ENPC02Right,
      textures.ENPC02RightWalk1,
      textures.ENPC02RightWalk2,
      textures.ENPC02Down,
      textures.ENPC02DownWalk1,
      textures.ENPC02DownWalk2,
      textures.ENPC02Left,
      textures.ENPC02LeftWalk1,
      textures.ENPC02LeftWalk2,
      Rectangle{15, 13, 1, 1},
      0,
      []() {
        return Direction::Down;
      }
    )),
    npc03(Character(
      03,
      {22, 28},
      textures.ENPC03Up,
      textures.ENPC03UpWalk1,
      textures.ENPC03UpWalk2,
      textures.ENPC03Right,
      textures.ENPC03RightWalk1,
      textures.ENPC03RightWalk2,
      textures.ENPC03Down,
      textures.ENPC03DownWalk1,
      textures.ENPC03DownWalk2,
      textures.ENPC03Left,
      textures.ENPC03LeftWalk1,
      textures.ENPC03LeftWalk2,
      Rectangle{21, 27, 5, 3},
      120,
      []() {
        int number = GetRandomValue(0, 3);
        return static_cast<Direction>(number);
      }
    )),
    interactions(player, textBox)
  { 
    // Top Left coordinate of the visible screen
    displayOrigin = {player.position.x - ((colCount - 1) / 2), player.position.y - (rowCount / 2)};
    SetVisibleBounds();

    BGLayerMap bgLayer = Maps::LittlerootTown::bgLayerMap;
    FGLayerMap fgLayer = Maps::LittlerootTown::fgLayerMap;

    characterList = {
      &player,
      &npc01,
      &npc02,
      &npc03
    };

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
  for (Character* entity : orderedEntities) {
    entity->Draw(
      (entity->position.x - displayOrigin.x) * cellSize,
      (entity->position.y - displayOrigin.y - 1) * cellSize
    );
  }

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
  
  npc01.UpdateNPC(entityMap, interactionMap, collisionMap);
  npc02.UpdateNPC(entityMap, interactionMap, collisionMap);
  npc03.UpdateNPC(entityMap, interactionMap, collisionMap);
  
  int layerRowCount = entityMap.size();
  int layerColCount = entityMap[0].size();

  for (int row = 0; row < layerRowCount; ++row) {
      for (int col = 0; col < layerColCount; ++col) {
        int entityId = entityMap[row][col];
        switch (entityId) {
          case 00:
            break;
          case 99:
            orderedEntities.push_back(&player);
            break;
          default:
            Character& targetNPC = *characterList.at(entityId);
            orderedEntities.push_back(&targetNPC);
        }
    }
  }
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
    interactions.interactionMap[player.Interact(interactionMap)]();
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
    player.Move(Direction::Up, entityMap, interactionMap, collisionMap);
  }
  if (IsKeyDown(KEY_RIGHT) && directionInputBuffer.back() == Direction::Right) {
    player.Move(Direction::Right, entityMap, interactionMap, collisionMap);
  }
  if (IsKeyDown(KEY_DOWN) && directionInputBuffer.back() == Direction::Down) {
    player.Move(Direction::Down, entityMap, interactionMap, collisionMap);
  }
  if (IsKeyDown(KEY_LEFT) && directionInputBuffer.back() == Direction::Left) {
    player.Move(Direction::Left, entityMap, interactionMap, collisionMap);
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
