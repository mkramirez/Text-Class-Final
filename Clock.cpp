#include "Clock.h"
#include <sstream>
#include "Font.h"

extern Frame drawFrame;
extern Font drawFont;

Clock::Clock(double x, double y){
    this->x = x;
    this->y = y;
    timer = 0;
}

void Clock::draw() const{
    std::stringstream ss;
    ss << (int)timer;
    std::string s = ss.str();
    drawFont.draw(s, 50, 30);
}

void Clock::update(double dt){
    timer = timer + dt;
}