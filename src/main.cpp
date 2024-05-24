#include <vector>
#include "graphics.h"
#include "Fish.hpp"
#include <random>

const int WIDTH = 1600;
const int HEIGHT = 900;
bool is_running = true;

struct Block {
//    地图区块,以10*10为单位
    bool is_water = true;
    std::vector<Fish *> fishes;
};

std::vector<std::vector<Block>> MAP(HEIGHT / 10, std::vector<Block>(WIDTH / 10));
std::vector<Fish *> boids;

void berlinMap() {
//    柏林噪声生成地形
//    TODO: 生成地形

//    地形输入进MAP
//    TODO: 根据地形生成地图
    for (auto &line_blocks: MAP) {
        for (auto &block: line_blocks) {
            block.is_water = true;
        }
    }
}


void generate_boids(int size) {
//    删除所有存在的鱼的示例
    for (Fish *fish: boids) {
        delete fish;
    }
    boids.clear();
//    清空地图上鱼的注册信息
    for (auto &line_blocks: MAP) {
        for (auto &block: line_blocks) {
            block.fishes.clear();
        }
    }
//    根据地图信息生成合理的鱼，并注册到鱼群和地图上
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_x(0, WIDTH);
    std::uniform_real_distribution<> dis_y(0, HEIGHT);

    for (int i = 0; i < size; i++) {
        auto x = float(dis_x(gen));
        auto y = float(dis_y(gen));

        auto block_x = int(x / 10);
        auto block_y = int(y / 10);

        while (!MAP[block_y][block_x].is_water) {
            x = float(dis_x(gen));
            y = float(dis_y(gen));
            block_x = int(x / 10);
            block_y = int(y / 10);
        }

        Fish *new_fish = new Fish(x, y);
        boids.push_back(new_fish);
        MAP[block_y][block_x].fishes.push_back(new_fish);
    }
}


bool mainWindow() {
//    主界面，可以选择模式
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
//    自由鸟群系统
    while (true) {
        cleardevice();
        rectangle(46, 34, 60, 50);
        FlushBatchDraw();
    }
}

void controlled_boids() {
//    受控鸟群系统
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

    while (is_running) {
        if (mainWindow()) {
            free_boids();
        } else {
            controlled_boids();
        }
    }

    EndBatchDraw();
    return 0;
}
