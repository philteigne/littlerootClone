#include "Textures.h"

Textures::Textures() {
  Default = LoadTexture("src/assets/textures/default.png");
  Empty = LoadTexture("src/assets/textures/empty.png");
  GRDGrass = LoadTexture("src/assets/textures/grd.grass.png");
  GRDMattedBL = LoadTexture("src/assets/textures/grd.matted_bottom-left.png");
  GRDMattedBR = LoadTexture("src/assets/textures/grd.matted_bottom-right.png");
  GRDMattedB = LoadTexture("src/assets/textures/grd.matted_bottom.png");
  GRDMattedR = LoadTexture("src/assets/textures/grd.matted_right.png");
  GRDMattedTL = LoadTexture("src/assets/textures/grd.matted_top-left.png");
  GRDMattedTR = LoadTexture("src/assets/textures/grd.matted_bottom-right.png");
  GRDMatted = LoadTexture("src/assets/textures/grd.matted.png");
  GRDPath = LoadTexture("src/assets/textures/grd.path.png");
  OBJFlower = LoadTexture("src/assets/textures/obj.flower.png");
  OBJRidgeL = LoadTexture("src/assets/textures/obj.ridge_left.png");
  OBJRidgeR = LoadTexture("src/assets/textures/obj.ridge_right.png");
  OBJRidge = LoadTexture("src/assets/textures/obj.ridge.png");
  OBJSign = LoadTexture("src/assets/textures/obj.sign.png");
  OBJTallGrass = LoadTexture("src/assets/textures/obj.tall_grass.png");
  OBJTreeBL = LoadTexture("src/assets/textures/obj.tree_bottom-left.png");
  OBJTreeBR = LoadTexture("src/assets/textures/obj.tree_bottom-right.png");
  OBJTreeTL = LoadTexture("src/assets/textures/obj.tree_top-left.png");
  OBJTreeTR = LoadTexture("src/assets/textures/obj.tree_top-right.png");
  PlayerUp = LoadTexture("src/assets/textures/player-up.png");
  PlayerRight = LoadTexture("src/assets/textures/player-right.png");
  PlayerDown = LoadTexture("src/assets/textures/player-down.png");
  PlayerLeft = LoadTexture("src/assets/textures/player-left.png");
}