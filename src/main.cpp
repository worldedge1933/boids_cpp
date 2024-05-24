#include "graphics.h"

const int WIDTH = 1600;
const int HEIGHT = 900;
bool running = true;


bool mainWindow() {
    while (true) {
        cleardevice();
        setfillcolor(RGB(255, 0, 0));

        solidrectangle(500, 300, 1100, 450);
        solidrectangle(500, 500, 1100, 650);

        FlushBatchDraw();
        ExMessage msg;
        while (peekmessage(&msg)) {
            if (msg.message == WM_LBUTTONUP && msg.x >= 500 && msg.x <= 1100 && msg.y >= 300 && msg.y <= 450) {
                return true;
            } else if (msg.message == WM_LBUTTONUP && msg.x >= 500 && msg.x <= 1100 && msg.y >= 500 && msg.y <= 650) {
                return false;
            }

        }

    }

}

void free_boids() {
    while (true) {
        cleardevice();
        rectangle(46, 34, 60, 50);
        FlushBatchDraw();
    }
}

void controlled_boids() {
    while (true) {
        cleardevice();
        circle(46, 34, 20);
        FlushBatchDraw();
    }

}

int main() {
    initgraph(WIDTH, HEIGHT);
    BeginBatchDraw();

    circle(320, 240, 100);

    while (running) {
        if (mainWindow()) {
            free_boids();
        } else {
            controlled_boids();
        }
    }

    EndBatchDraw();
    return 0;
}
