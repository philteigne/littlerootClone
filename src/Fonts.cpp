#include "Fonts.h"

Fonts::Fonts() {
  int codepoints[512];
  int count = 0;

  for (int i = 32; i <= 126; i++) {
    codepoints[count++] = i;
  }

  codepoints[count++] = 0x2018; // ‘
  codepoints[count++] = 0x2019; // ’
  codepoints[count++] = 0x201C; // “
  codepoints[count++] = 0x201D; // ”
  codepoints[count++] = 0x2026; // …
  codepoints[count++] = 0x00E9; // é

  fontDialog = LoadFontEx(
    "./src/assets/fonts/pokemon-emerald.otf",
    15,
    codepoints,
    count
  );

  SetTextureFilter(fontDialog.texture, TEXTURE_FILTER_POINT);
}