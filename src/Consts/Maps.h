#pragma once
#include <deque>
#include <string>


enum TextureKey { G0, G1, F0, S0, R0, R1, R2, M0, M1, M2, M3, M4, M5, P0, X0, T0, T1, D0, H1, H2, H3, C1, C2, C3 };

using BGLayerMap = std::deque<std::deque<TextureKey>>;
using FGLayerMap = std::deque<std::deque<TextureKey>>;

namespace Maps {
 namespace LittlerootTown {
  const BGLayerMap bgLayerMap = {
    // G0: grass
    // G1: tall grass
    // F0: flower
    // R0: ridge
    // R1: ridge left
    // R2: ridge right
    // S0: sign
    // M0: matted grass
    // M1: matted grass right
    // M2: matted grass top left
    // M3: matted grass bottom right
    // M4: matted grass bottom left
    // M5: matted grass bottom
    // P0: dirt path
 // 00  01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 00
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, T0, X0, G0, M2, M0, M0, M0, M1, G0, G1, G1, G1, G1, G1, G0, M4, M0, M1, G0, G0, G0, G0, G0, G0, G0, G0}, // 01
   {T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, G0, M4, M0, M0, M0, M3, G0, G1, G1, G1, G1, G1, G1, G0, M4, M5, G0, G0, G0, G0, G0, G0, G0, G0}, // 02
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, T0, X0, G0, G0, M4, M5, M3, G0, G0, G1, G1, G1, G1, G1, G1, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 03
   {T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, G1, G1, G0, G0, G0, G0, R1, R0, R0, R2, G1, G1, G1, G1, G1, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 04
   {G0, G0, G0, G0, G0, G0, G0, G0, G1, G1, G1, G1, G1, G0, G0, G0, G0, G0, G0, G0, G0, G0, G1, G1, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 05
   {T0, X0, T0, X0, T0, X0, T0, X0, G1, G1, G1, G1, G1, G1, G0, G0, G0, G0, G0, G0, T0, X0, G1, G1, G0, G0, T0, X0, G0, G0, G0, G0, G0, G0, G0, G0}, // 06
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G1, G1, G1, G1, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 07
   {T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, G1, G1, G1, G0, G0, G0, G0, G0, G0, G0, T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, G0, G0, G0, G0, G0, G0}, // 08
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 09
   {T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0}, // 10
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 11
   {T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0}, // 12
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 13
   {T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0}, // 14
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 15
   {T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, T0, X0, T0, X0, T0, X0, T0, X0}, // 16
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 17
   {T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, F0, T0, X0, T0, X0, T0, X0, T0, X0}, // 18
   {G0, G0, G0, G0, G0, G0, G0, G0, F0, G0, H1, X0, X0, X0, X0, S0, G0, G0, G0, G0, S0, H2, X0, X0, X0, X0, F0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 19
   {T0, X0, T0, X0, T0, X0, T0, X0, G0, F0, G0, G0, G0, P0, G0, G0, G0, G0, G0, G0, G0, G0, P0, G0, G0, G0, G0, F0, T0, X0, T0, X0, T0, X0, T0, X0}, // 20
   {G0, G0, G0, G0, G0, G0, G0, G0, F0, G0, G0, F0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, F0, G0, F0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 21
   {T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, T0, X0, T0, X0, T0, X0, T0, X0}, // 22
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 23
   {T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, S0, G0, G0, G0, G0, T0, X0, T0, X0, T0, X0, T0, X0}, // 24
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 25
   {T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, T0, X0, T0, X0, T0, X0, T0, X0}, // 26
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, H3, X0, X0, X0, X0, X0, X0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 27
   {T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, G0, F0, F0, F0, S0, P0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0}, // 28
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, F0, F0, F0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 29
   {T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0}, // 30
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 31
   {T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0}, // 32
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 33
   {T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0}, // 34
   {G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0, G0}, // 35
   {T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0, T0, X0}, // 36
  };

  const FGLayerMap fgLayerMap = {
    // X0: nothing
    // T1: tree foreground
    // D0: door
    // C1: house 1 foreground
    // C2: house 2 foreground
    // C3: house 3 foreground
 // 00  01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 00
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 01
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 02
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 03
   {T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, X0, X0, X0, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 04
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 05
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 06
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 07
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 08
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 09
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 10
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 11
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 12
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 13
   {T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 14
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 15
   {T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, C1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, C2, X0, X0, X0, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 16
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 17
   {T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 18
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, D0, X0, X0, X0, X0, X0, X0, X0, X0, D0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 19
   {T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 20
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 21
   {T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 22
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 23
   {T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, C3, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 24
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 25
   {T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 26
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, D0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 27
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 28
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 29
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 30
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 31
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 32
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 33
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 34
   {X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0, X0}, // 35
   {T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0, T1, X0}, // 36
  };
 }
};