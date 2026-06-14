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
  int cellSize
) : colCount(colCount),
  rowCount(rowCount),
  cellSize(cellSize),
  characterList(characterList)
{}
