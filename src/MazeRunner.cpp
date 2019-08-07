#include <chrono> // thread
#include <cstdlib> // system
#include <iostream>
#include <mutex> // mutex
#include <string> // string
#include <thread> // thread

#include "../include/MazeRunner.hpp"

namespace Maze
{

MazeRunner::MazeRunner(int w, int h): angle(0), degrees(45), width(w), height(h), mtx()
{
    std::thread th1([]() { std::system("tput civis"); });
    th1.join();
    std::thread th2([]() { std::system("clear"); });
    th2.join();
    map = new std::string[10];
    screen = new std::string[height];
    rays = new int[width];
}

void MazeRunner::renderScreen()
{
    mtx.lock();

    // Move Cursor to Top
    for (int ii = 0; ii < height; ii++)
	std::cout << "\033[1A";  // move cursor one line up

    // Draw the screen
    for (int ii = 0; ii < height; ii++)
	std::cout << screen[ii] << std::endl;

    mtx.unlock();
}

void MazeRunner::rayTrace()
{
    mtx.lock();
    mtx.unlock();
}

void MazeRunner::turnLeft() {}

void MazeRunner::turnRight() {}

void MazeRunner::moveForward() {}

void MazeRunner::moveBackward() {}

MazeRunner::~MazeRunner()
{
    std::thread th1([]() { std::system("tput cnorm"); });
    th1.join();
    std::thread th2([]() { std::system("clear"); });
    th2.join();
    delete map;
    delete screen;
    delete rays;
}

}
