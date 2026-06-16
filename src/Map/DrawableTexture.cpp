#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "DrawableTexture.h"


DrawableTexture::DrawableTexture(
  int col,
  int row,
  int cellSize,
  TextureKey textureKey,
  Textures textures
) : 
  col(col),
  row(row),
  cellSize(cellSize),
  textureKey(textureKey)
{

  switch(textureKey) {
    case G0:
      texture = textures.BGGrass;
      break;
    case G1:
      texture = textures.BGTallGrass;
      break;
    case F0:
      texture = textures.BGFlower;
      break;
    case S0:
      texture = textures.BGSign;
      break;
    case R0:
      texture = textures.BGRidge;
      break;
    case R1:
      texture = textures.BGRidgeL;
      break;
    case R2:
      texture = textures.BGRidgeR;
      break;
    case M0:
      texture = textures.BGMatted;
      break;
    case M1:
      texture = textures.BGMattedTR;
      break;
    case M2:
      texture = textures.BGMattedTL;
      break;
    case M3:
      texture = textures.BGMattedBR;
      break;
    case M4:
      texture = textures.BGMattedBL;
      break;
    case M5:
      texture = textures.BGMattedB;
      break;
    case P0:
      texture = textures.BGPath;
      break;
    case T0:
      texture = textures.BGTree;
      break;
    case T1:
      texture = textures.FGTree;
      break;
    case D0:
      texture = textures.Default;
      break;
    case C1:
      texture = textures.FGHouse1;
      break;
    case C2:
      texture = textures.FGHouse2;
      break;
    case C3:
      texture = textures.FGHouse3;
      break;
    case H1:
      texture = textures.BGHouse1;
      break;
    case H2:
      texture = textures.BGHouse2;
      break;
    case H3:
      texture = textures.BGHouse3;
      break;
    case X0:
      texture = textures.Empty;
      break;
    default:
      texture = textures.Default;
      break;
  }

  SetTextureBounds();
}

void DrawableTexture::Draw(Vector2 visibleOrigin) {
  Vector2 visibleOriginPixels = Vector2Scale(visibleOrigin, cellSize);
  Vector2 drawOrigin = Vector2Subtract(origin, visibleOriginPixels);
  DrawTexture(texture, drawOrigin.x, drawOrigin.y, WHITE);
}

bool DrawableTexture::shouldDraw(Rectangle visibleBounds) {
  if (CheckCollisionRecs(visibleBounds, textureBounds)) {
    return true;
  }

  return false;
}

void DrawableTexture::SetTextureBounds() {
  float x = col * cellSize;
  float y = (row * cellSize) + cellSize - texture.height;
  float width = texture.width;
  float height = texture.height;
  
  origin = {x, y};
  textureBounds =  Rectangle{
    origin.x,
    origin.y,
    width,
    height
  };

}