#include "Engine.h"
#include <iostream>
#include <sstream>
#include "Global.h"
#include "Clock.h"


extern Frame drawFrame;

std::vector<Object *> Engine::objects;

void Engine::addObject(Object * object) {
    objects.push_back(object);
}

void Engine::removeObject(Object * Object) {
    int s = -1;
    for (int i = 0; i < objects.size(); ++i) {
        if (objects[i] == Object) {
            s = i;
            break;
        }
    }
    for (int i = s; i < objects.size() - 1; ++i) {
        objects[i] = objects[i + 1];
    }
    objects.pop_back();
}

int Engine::run() {
    // Construct the ffmpeg command to run.
    const char * cmd =
            "ffmpeg              "
                    "-y                  "
                    "-hide_banner        "
                    "-f rawvideo         " // input to be raw video data
                    "-pixel_format rgb24 "
                    "-video_size 720x480 "
                    "-r 60               " // frames per second
                    "-i -                " // read data from the standard input stream
                    "-pix_fmt yuv420p    " // to render with Quicktime
                    "-vcodec mpeg4       "
                    "-an                 " // no audio
                    "-q:v 5              " // quality level; 1 <= q <= 32
                    "output.mp4          ";

    // Run the ffmpeg command and get pipe to write into its standard input stream.

    FILE * pipe = popen(cmd, "w");

    if (pipe == nullptr) {
        std::cout << "error: " << strerror(errno) << std::endl;
        return 1;
    }
    Clock clock(20, 30);
    auto num_frames = duration_in_seconds * frames_per_second;
    for (int i = 0; i < num_frames; ++i) {
        double dt = 1.0 / frames_per_second;
        drawFrame.clear();
        for (auto &object : objects) {
            object->update(dt);
            object->draw();
        }
        clock.update(dt);
        clock.draw();
        drawFrame.write(pipe);
    }

    fflush(pipe);
    pclose(pipe);

    std::cout << "num_frames: " << num_frames << std::endl;
    std::cout << "Done." << std::endl;

    return 0;
}