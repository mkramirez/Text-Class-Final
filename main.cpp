#include "Frame.h"
#include "Image.h"
#include "Engine.h"
#include "StartObject.h"
#include "Font.h"


Frame drawFrame(720, 480);
Font drawFont;

int main(int argc, char * argv[]) {
    StartObject startObject;
    Engine::addObject(&startObject);
    return Engine::run();

}