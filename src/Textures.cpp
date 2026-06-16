#include "Textures.h"

Textures::Textures() {
  Default = LoadTexture("src/assets/textures/default.png");
  Empty = LoadTexture("src/assets/textures/empty.png");
  BGGrass = LoadTexture("src/assets/textures/bg.grass.png");
  BGMattedBL = LoadTexture("src/assets/textures/bg.matted_bottom-left.png");
  BGMattedBR = LoadTexture("src/assets/textures/bg.matted_bottom-right.png");
  BGMattedB = LoadTexture("src/assets/textures/bg.matted_bottom.png");
  BGMattedR = LoadTexture("src/assets/textures/bg.matted_right.png");
  BGMattedTL = LoadTexture("src/assets/textures/bg.matted_top-left.png");
  BGMattedTR = LoadTexture("src/assets/textures/bg.matted_top-right.png");
  BGMatted = LoadTexture("src/assets/textures/bg.matted.png");
  BGPath = LoadTexture("src/assets/textures/bg.path.png");
  BGFlower = LoadTexture("src/assets/textures/bg.flower.png");
  BGRidgeL = LoadTexture("src/assets/textures/bg.ridge_left.png");
  BGRidgeR = LoadTexture("src/assets/textures/bg.ridge_right.png");
  BGRidge = LoadTexture("src/assets/textures/bg.ridge.png");
  BGSign = LoadTexture("src/assets/textures/bg.sign.png");
  BGTallGrass = LoadTexture("src/assets/textures/bg.tall_grass.png");
  BGTree = LoadTexture("src/assets/textures/bg.tree.png");
  FGTree = LoadTexture("src/assets/textures/fg.tree.png");
  BGHouse1 = LoadTexture("src/assets/textures/bg.house_1.png");
  BGHouse2 = LoadTexture("src/assets/textures/bg.house_2.png");
  BGHouse3 = LoadTexture("src/assets/textures/bg.house_3.png");
  FGHouse1 = LoadTexture("src/assets/textures/fg.house_1.png");
  FGHouse2 = LoadTexture("src/assets/textures/fg.house_2.png");
  FGHouse3 = LoadTexture("src/assets/textures/fg.house_3.png");
  EPlayerUp = LoadTexture("src/assets/textures/e.player-up.png");
  EPlayerRight = LoadTexture("src/assets/textures/e.player-right.png");
  EPlayerDown = LoadTexture("src/assets/textures/e.player-down.png");
  EPlayerLeft = LoadTexture("src/assets/textures/e.player-left.png");
}