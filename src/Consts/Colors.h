#pragma once
#include <deque>
#include <string>
#include <raylib.h>

using Map = std::deque<std::deque<std::string>>;

namespace Colors {
  namespace Text {
    inline const Color TEXT_PRIMARY = Color{99, 97, 99, 255};
    inline const Color TEXT_SECONDARY = Color{214, 211, 206, 255};
  }
};