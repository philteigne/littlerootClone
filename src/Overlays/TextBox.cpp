#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "TextBox.h"
#include "../Textures.h"
#include "../Consts/Colors.h"

TextBox::TextBox(
  int rowCount,
  int colCount,
  int cellSize,
  Texture2D texture,
  Font font
) : boxTexture(texture),
  font(font)
{
  
  drawOrigin = {
    1,
    float ((rowCount * cellSize) - boxTexture.height - 3),
  };

  // x-padding 15px from outer edge of text box
  // y-padding 9px from outer edge of text box
  textOrigin = Vector2Add(
    drawOrigin,
    Vector2{15, 6}
  );
}

// Draw the basic textbox texture, the otput is hidden by the isVisible toggle
void TextBox::Draw() {
  if (isVisible) {
    DrawTexture(boxTexture, drawOrigin.x, drawOrigin.y, WHITE);

    // The text is drawn 3 times, 2 shadow layers slightly offset then one
    // for the primary text layer.

    // Shadow 01
    DrawTextEx(
      font,
      TextFormat(text.c_str()),
      Vector2Add(textOrigin, Vector2{0, 1}),
      fontSize,
      spacing,
      Colors::Text::TEXT_SECONDARY
    );
    
    // Shadow 02
    DrawTextEx(
      font,
      TextFormat(text.c_str()),
      Vector2Add(textOrigin, Vector2{1, 1}),
      fontSize,
      spacing,
      Colors::Text::TEXT_SECONDARY
    );
    
    // Primary Text
    DrawTextEx(
      font,
      TextFormat(text.c_str()),
      textOrigin,
      fontSize,
      spacing,
      Colors::Text::TEXT_PRIMARY
    );
  }
}

// Show textbox with desired text
void TextBox::Show(std::string text) {
  this->text = text;
  isVisible = true;
}

void TextBox::Hide() {
  isVisible = false;
  this->text = "";
}

