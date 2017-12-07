#include "Clock.h"
#include <sstream>
#include "Font.h"

extern Frame drawFrame;

Font drawFont;

using namespace std;

Clock::Clock(int x, int y){
    this->x = x;
    this->y = y;
    elapsedSeconds = 0;
}

void Clock::draw() const{
    stringstream ss;
    ss << (int)elapsedSeconds;
    string s = ss.str();
    drawFont.draw(ss.str(), 17, 20);
}

void Clock::update(double dt){
    elapsedSeconds = elapsedSeconds + dt;
}