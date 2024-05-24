#include "graphics.h"

const int WIDTH = 1600;
const int HEIGHT = 900;

int main() {
    bool running = true;
    initgraph(WIDTH, HEIGHT);
    circle(320, 240, 100);
    while (running) {
        Sleep(200);
    }
    return 0;
}
