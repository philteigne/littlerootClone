#pragma once
#include <vector>
#include "../Map/GroundLayer.h"

class ViewPort {
  public:
    ViewPort(LayerCells tiles,  int cellSize);
    void Draw(LayerCells tiles);
  private:
    int cellSize;
};