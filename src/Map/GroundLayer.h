#pragma once
#include <vector>
#include <deque>
#include <string>

using LayerCells = std::deque<std::deque<std::string>>;

class GroundLayer {
  public:
    GroundLayer();
    LayerCells cells;
  private:
};