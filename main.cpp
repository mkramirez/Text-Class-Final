#include "Frame.h"
#include "Image.h"
#include <fstream>

typedef unsigned char byte;

const double frames_per_second = 30;
const int duration_in_seconds = 3;

Frame drawFrame(720, 480);

int main(int argc, char * argv[]) {

    const char * cmd =
            "ffmpeg              "
                    "-y                  "
                    "-hide_banner        "
                    "-f rawvideo         "
                    "-pixel_format rgb24 "
                    "-video_size 720x480 "
                    "-r 60               "
                    "-i -                "
                    "-pix_fmt yuv420p    "
                    "-vcodec mpeg4       "
                    "-an                 "
                    "-q:v 5              "
                    "output.mp4          ";

    FILE * pipe = popen(cmd, "w");
    if (pipe == nullptr) {
        std::cout << "error: " << strerror(errno) << std::endl;
        return 1;
    }
    Image img1;
    Image img2;
    Image img3;
    img1.getX(0.0);
    img1.getY(0.0);
    img2.getX(0.0);
    img2.getY(150.0);
    img3.getX(0.0);
    img3.getY(300.0);

    img1.setSpeed(100, 0);
    img2.setSpeed(100, 0);
    img3.setSpeed(100, 0);

    img1.load("Spongebob1.png", 150, 150);
    img2.load("Spongebob2.png", 150, 150);
    img3.load("Spongebob3.png", 150, 150);

    int num_frames = duration_in_seconds * frames_per_second;
    for (int i = 0; i < num_frames; ++i) {
        double dt = 1.0 / frames_per_second;
        drawFrame.clear();
        img1.draw();
        img2.draw();
        img3.draw();
        img1.update(dt);
        img2.update(dt);
        img3.update(dt);

        drawFrame.write(pipe);
    }

    fflush(pipe);
    pclose(pipe);

    std::cout << "num_frames: " << num_frames << std::endl;
    std::cout << "Done." << std::endl;

    return 0;
}