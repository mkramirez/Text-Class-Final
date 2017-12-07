#pragma once
#include "Glyph.h"
#include <string>
#include "Global.h"
#include "Frame.h"

class Font {
public:
    Font();
    ~Font() {delete [] pixels; }
    void draw(const std::string & text, double x, double y) const;

private:
    byte * pixels;
    int w;
    int h;
};