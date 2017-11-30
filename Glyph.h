#pragma once
#include <string>
#include "Global.h"

class Glyph {
private:
    Glyph(char c);
    int fx;
    int fy;
    int fw;
    int fh;
    int xOffset;
    int yOffset;
    int xAdvance;

    friend class Font;
};