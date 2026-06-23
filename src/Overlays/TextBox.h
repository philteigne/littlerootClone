#pragma once
#include <string>
#include <raylib.h>

class TextBox {
  public:
    TextBox(
      int rowCount,
      int colCount,
      int cellSize,
      Texture2D texture,
      Font font
    );
    void Draw();
    void Show(std::string text);
    void Hide();
    bool isVisible = false;
  private:
    Texture2D boxTexture;
    Font font;
    float fontSize = 15;
    float spacing = 0;
    std::string text;
    Vector2 drawOrigin;
    Vector2 textOrigin;
};