#include <raylib.h>
#include <vector>
#include <string>
#include <iostream>
#include "ViewPort.h"
#include "../Map/GroundLayer.h"

ViewPort::ViewPort(LayerCells tiles,  int cellSize)
  : cellSize(cellSize)
  {
    Draw(tiles);
  }

void ViewPort::Draw(LayerCells tiles) {
  for (int row = 0; row < tiles.size(); ++row) {
    for (int col = 0; col < tiles[row].size(); ++col) {
      std::string tile = tiles[row][col];
      DrawRectangle(
        col * cellSize, // x-position
        row * cellSize, // y-position
        cellSize - 1, // width
        cellSize - 1, // height
        tile == "G0" ? GREEN : RED // colour
      );
    }
  }
};