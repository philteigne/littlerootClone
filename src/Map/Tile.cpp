#include "Tile.h"
#include <functional>
#include "../Consts/Maps.h"
#include "../Textures.h"

Tile::Tile(
  GroundTexture groundLayer,
  ObjectTexture objectLayer,
  Textures textures,
  bool isAccessible,
  std::function<void()> onEnter,
  std::function<void()> onInteract
) 
  : groundLayer(groundLayer),
  objectLayer(objectLayer),
  textures(textures),
  isAccessible(isAccessible),
  onEnter(onEnter),
  onInteract(onInteract)
  {
    LoadGroundTexture();
    LoadObjectTexture();
  }

void Tile::Enter() {
  onEnter();
}

void Tile::Interact() {
  onInteract();
}

void Tile::LoadGroundTexture() {
  // G0: grass
  // M0: matted grass
  // M1: matted grass right
  // M2: matted grass top left
  // M3: matted grass bottom right
  // M4: matted grass bottom left
  // M5: matted grass bottom
  // P0: dirt path
  switch (groundLayer) {
    case(G0):
      groundTexture = textures.GRDGrass;
      break;
    case(M0):
      groundTexture = textures.GRDMatted;
      break;
    case(M1):
      groundTexture = textures.GRDMattedR;
      break;
    case(M2):
      groundTexture = textures.GRDMattedTL;
      break;
    case(M3):
      groundTexture = textures.GRDMattedBR;
      break;
    case(M4):
      groundTexture = textures.GRDMattedBL;
      break;
    case(M5):
      groundTexture = textures.GRDMattedB;
      break;
    case(P0):
      groundTexture = textures.GRDPath;
      break;
    default:
      groundTexture = textures.Default;
  }
}

void Tile::LoadObjectTexture() {
  switch (objectLayer) {
    case(X0):
      objectTexture = textures.Empty;
      break;
    case(G1):
      objectTexture = textures.OBJTallGrass;
      break;
    case(T0):
      objectTexture = textures.OBJTreeTL;
      break;
    case(T1):
      objectTexture = textures.OBJTreeTR;
      break;
    case(T2):
      objectTexture = textures.OBJTreeBL;
      break;
    case(T3):
      objectTexture = textures.OBJTreeBR;
      break;
    case(F0):
      objectTexture = textures.OBJFlower;
      break;
    case(S0):
      objectTexture = textures.OBJSign;
      break;
    case(D0):
      objectTexture = textures.Default;
      break;
    case(R0):
      objectTexture = textures.OBJRidge;
      break;
    case(R1):
      objectTexture = textures.OBJRidgeL;
      break;
    case(R2):
      objectTexture = textures.OBJRidgeR;
      break;
    default:
      objectTexture = textures.Empty;
  }
}
