#pragma once
#include "Object.h"
#include <vector>
#include <iostream>
#include "Frame.h"

class Clock : public Object{
public:
    virtual void update(double dt);
    virtual void draw() const;
    Clock(double x, double y);

private:
    double timer, x, y;
};