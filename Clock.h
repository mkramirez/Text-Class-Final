#pragma once

#include "Object.h"

class Clock : public Object{
public:
    virtual void update(double dt);
    virtual void draw() const;
    Clock(int x, int y);

private:
    double elapsedSeconds;
    double x;
    double y;
};