#pragma once
#include "Image.h"
#include <vector>
#include "Object.h"
#include "Clock.h"
#include "Rectangle.h"

class StartObject: public Object {
public:
    StartObject();
    ~StartObject();
    virtual void update(double dt);
    virtual void draw() const;

private:
    std::vector<Rectangle *> rectangles;
    std::vector<Image *> images;
    std::vector<Clock *> clocks;
};