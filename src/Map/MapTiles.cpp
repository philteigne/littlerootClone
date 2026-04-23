#include <iostream>
#include "MapTiles.h"
#include "../Consts/Maps.h"
#include "../Consts/Colors.h"
#include "Tile.h"

MapTiles::MapTiles(
  int colCount,
  int rowCount,
  int cellSize
) {
  this -> colCount = colCount;
  this -> rowCount = rowCount;
  this -> cellSize = cellSize;
}

void MapTiles::Draw(Vector2 center) {
  std::cout << "Called map.Draw()" << std::endl;
  // std::cout << center << std::endl;


  // For now we assume the groundLayer and objectLayer sizes are the same since they overlay
  Map groundLayer = Maps::LittlerootTown::groundLayerMap;
  Map objectLayer = Maps::LittlerootTown::objectLayerMap;
  int rowOffset = (rowCount - 1) / 2;
  int colOffset = (colCount - 1) / 2;
  std::deque<std::deque<Tile>> mapTiles = {};

  for (int row = 0; row < rowCount; ++row) {
    std::deque<Tile> mapTilesRow = {};
    for (int col = 0; col < colCount; ++col) {
      std::string groundLayerTile = groundLayer[center.y - rowOffset + row][center.x - colOffset + col];
      std::string objectLayerTile = objectLayer[center.y - rowOffset + row][center.x - colOffset + col];
      Tile tile = Tile(
        groundLayerTile,
        objectLayerTile,
        true,
        nullptr,
        nullptr
      );

      mapTilesRow.push_back(tile);

      // groundLayer
      DrawRectangle(
        col * cellSize, // x-position
        row * cellSize, // y-position
        cellSize, // width
        cellSize, // height
        GetTileColor(groundLayerTile, "groundLayer") // colour
      );
      // objectLayer
      DrawRectangle(
        col * cellSize,
        row * cellSize,
        cellSize - 5,
        cellSize - 5,
        GetTileColor(objectLayerTile, "objectLayer")
      );
    }

    mapTiles.push_back(mapTilesRow);
  }

  tiles = mapTiles;
}

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
