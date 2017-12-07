#include <iostream>
#include "Image.h"
#include "Rectangle.h"
#include "Clock.h"
#include "StartObject.h"
#include "Engine.h"

extern Frame drawFrame;

StartObject::StartObject() {
    Clock clock(20,30);
    auto * r1 = new Rectangle(45, 45, 150, 50, 0xff, 0x00, 0xff);
    auto * r2 = new Rectangle(45, 45, 200, 55, 0xff, 0xff, 0x00);
    auto * r3 = new Rectangle(45, 45, 5, 150, 0x00, 0x00, 0xff);
    auto * r4 = new Rectangle(45, 45, 30, 5, 0x00, 0xff, 0x00);
    auto * image = new Image();
    auto * image2 = new Image();
    r1->setSpeed(20, 30);
    r2->setSpeed(40, 150);
    r3->setSpeed(20, 30);
    r4->setSpeed(43, 0);
    image->getX(5);
    image->getY(20);
    image2->getX(200);
    image2->getY(200);
    image->setSpeed(20, 40);
    image2->setSpeed(31,0);
    image->load("Spongebob1.png", 150, 150);
    image2->load("Spongebob2.png", 100, 100);
    images.push_back(image);
    images.push_back(image2);
    rectangles.push_back(r1);
    rectangles.push_back(r2);
    rectangles.push_back(r3);
    rectangles.push_back(r4);
    for (int i = 0; i < clocks.size(); ++i) {
        Engine::addObject(clocks[i]);
    }
    for (int i = 0; i < rectangles.size(); ++i) {
        Engine::addObject(rectangles[i]);
    }
    for (int i = 0; i < images.size(); ++i) {
        Engine::addObject(images[i]);
    }
}

StartObject::~StartObject() {
    for (int i = 0; i < clocks.size(); ++i) {
        delete clocks[i];
    }
    for (int i = 0; i < rectangles.size(); ++i) {
        delete rectangles[i];
    }
    for (int i = 0; i < images.size(); ++i) {
        delete images[i];
    }
}

void StartObject::draw() const {
    for (int i = 0; i <clocks.size(); ++i) {
        clocks[i]->draw();
    }

    for (int i = 0; i < images.size(); ++i) {
        images[i]->draw();
    }

    for (int i = 0; i < rectangles.size(); ++i) {
        rectangles[i]->draw();
    }
}

void StartObject::update(double dt) {
    for (int i = 0; i < clocks.size(); ++i) {
        clocks[i]->update(dt);
    }

    for (int i = 0; i < images.size(); ++i) {
        images[i]->update(dt);
    }

    for (int i = 0; i < rectangles.size(); ++i) {
        rectangles[i]->update(dt);
    }
}