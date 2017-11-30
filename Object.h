#pragma once
#include "Frame.h"

class Object {
public:
    virtual void update(double dt) = 0;
    virtual void draw() const = 0;
};