#include <iostream>
#include <deque>
#include "MapTiles.h"
#include "../Consts/Maps.h"
#include "../Consts/Colors.h"
#include "Tile.h"
#include "../Entities/Character.h"
#include "../Textures.h"

MapTiles::MapTiles(
  int colCount,
  int rowCount,
  int cellSize,
  Player& player,
  std::deque<Character>& characterList,
  Textures textures
) : colCount(colCount),
  rowCount(rowCount),
  cellSize(cellSize),
  player(player),
  characterList(characterList),
  textures(textures)
{}
// 6, 15
void MapTiles::Draw(Vector2 center) {
  // For now we assume the groundLayer and objectLayer sizes are the same since they overlay
  GroundMap groundLayer = Maps::LittlerootTown::groundLayerMap;
  ObjectMap objectLayer = Maps::LittlerootTown::objectLayerMap;
  Vector2 displayOrigin = {center.x - ((colCount - 1) / 2), center.y - ((rowCount - 1) / 2)};
  std::deque<std::deque<Tile>> mapTiles = {};

  for (int row = 0; row < rowCount; ++row) {
    std::deque<Tile> mapTilesRow = {};
    for (int col = 0; col < colCount; ++col) {
      GroundTexture groundLayerTile = groundLayer[displayOrigin.y + row][displayOrigin.x + col];
      ObjectTexture objectLayerTile = objectLayer[displayOrigin.y + row][displayOrigin.x + col];
      Tile tile = Tile(
        groundLayerTile,
        objectLayerTile,
        textures,
        true,
        nullptr,
        nullptr
      );

      mapTilesRow.push_back(tile);

      // groundLayer
      DrawTexture(
        tile.groundTexture,
        col * cellSize,
        row * cellSize,
        WHITE
      );
      // DrawRectangle(
      //   col * cellSize, // x-position
      //   row * cellSize, // y-position
      //   cellSize, // width
      //   cellSize, // height
      //   GetTileColor(groundLayerTile, "groundLayer") // colour
      // );
      // objectLayer
      DrawTexture(
        tile.objectTexture,
        col * cellSize,
        row * cellSize,
        WHITE
      );
      // DrawRectangle(
      //   col * cellSize,
      //   row * cellSize,
      //   cellSize - 5,
      //   cellSize - 5,
      //   GetTileColor(objectLayerTile, "objectLayer")
      // );
    }

    mapTiles.push_back(mapTilesRow);
  }
  
  player.Draw(
    (player.position.x - displayOrigin.x) * cellSize,
    (player.position.y - displayOrigin.y) * cellSize
  );

  for (Character character : characterList) {
    character.Draw(
      character.position.x * cellSize,
      character.position.y * cellSize
    );
  }

  tiles = mapTiles;
}

// We need a way to get the visible coordinate given the center of the rendered map and the real map coordinate

Color MapTiles::GetTileColor(std::string tile, std::string layer)
{
  if (layer == "groundLayer") {
    if (tile == "G0") return Colors::GroundLayer::GRASS_GREEN;
    if (tile == "M0") return Colors::GroundLayer::STOMPED_GRASS_GREEN;
    if (tile == "M1") return Colors::GroundLayer::STOMPED_GRASS_GREEN;
    if (tile == "M2") return Colors::GroundLayer::STOMPED_GRASS_GREEN;
    if (tile == "M3") return Colors::GroundLayer::STOMPED_GRASS_GREEN;
    if (tile == "M4") return Colors::GroundLayer::STOMPED_GRASS_GREEN;
    if (tile == "P0") return Colors::GroundLayer::DIRT_PATH_BROWN;
  }
  if (layer == "objectLayer") {
    if (tile == "T0") return Colors::ObjectLayer::TREE_GREEN;
    if (tile == "T1") return Colors::ObjectLayer::TREE_GREEN;
    if (tile == "T2") return Colors::ObjectLayer::TREE_GREEN;
    if (tile == "T3") return Colors::ObjectLayer::TREE_GREEN;
    if (tile == "G0") return Colors::ObjectLayer::TALL_GRASS_GREEN;
    if (tile == "F0") return Colors::ObjectLayer::FLOWER_YELLOW;
    if (tile == "S0") return Colors::ObjectLayer::SIGN_GREY;
    if (tile == "D0") return Colors::ObjectLayer::DOOR_BROWN;
    if (tile == "R0") return Colors::ObjectLayer::RIDGE_BROWN;
    if (tile == "R1") return Colors::ObjectLayer::RIDGE_BROWN;
    if (tile == "R2") return Colors::ObjectLayer::RIDGE_BROWN;
  }

  return Color{0, 0, 0, 0};
}
