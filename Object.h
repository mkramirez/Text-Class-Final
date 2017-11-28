#pragma once
#include "Frame.h"

class Object {
public:
    virtual void draw(Frame &frame) const;
    virtual void update(double dt) = 0;
    virtual void draw() const = 0;
};