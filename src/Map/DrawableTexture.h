#pragma once
#include <raylib.h>
#include "../Consts/Maps.h"
#include "../Textures.h"

class DrawableTexture {
  public:
    DrawableTexture(
      int col,
      int row,
      int cellSize,
      TextureKey textureKey,
      Textures textures
    );
    Texture2D texture;
    Rectangle textureBounds;
    void Draw(Vector2 visibleOrigin);
    bool shouldDraw(Rectangle visibleBounds);
  private:
    Vector2 origin;
    int col;
    int row;
    int cellSize;
    TextureKey textureKey;
    void SetTextureBounds();
    Rectangle GetTextureBounds();
};