#pragma once
#include <deque>
#include <string>
#include <raylib.h>

using Map = std::deque<std::deque<std::string>>;

namespace Colors {
  namespace GroundLayer {
    inline const Color GRASS_GREEN = Color{125, 199, 172, 255};
    inline const Color DIRT_PATH_BROWN = Color{227, 231, 166, 255};
    inline const Color STOMPED_GRASS_GREEN = Color{161, 208, 193, 255};
  };
  namespace ObjectLayer {
    inline const Color TALL_GRASS_GREEN = Color{13, 101, 43, 255};
    inline const Color FLOWER_YELLOW = Color{255, 247, 83, 255};
    inline const Color SIGN_GREY = Color{204, 235, 240, 255};
    inline const Color TREE_GREEN = Color{95, 172, 68, 255};
    inline const Color RIDGE_BROWN = Color{127, 86, 86, 255};
    inline const Color DOOR_BROWN = Color{91, 58, 76, 255};
  }
};