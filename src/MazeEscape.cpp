#include <chrono> // thread
#include <cmath> // sin, cos
#include <cstdlib> // system
#include <iostream>
#include <ncurses.h>
#include <string> // string
#include <thread> // thread
#include <unistd.h> 

//#include "../include/MazeRunner.hpp"

#define PI 3.14159265

const std::string LINE_DEL = "\033[1A\033[K";
const int MAX_STEPS = (int)sqrt(2*pow(8,2))*10;

std::string map[10] = 
{
    "##########",
    "#........X",
    "#........#",
    "#........#",
    "#....P...#",
    "#........#",
    "#.....#..#",
    "#....#...#",
    "#........#",
    "##########"
};

struct Position
{
    double x = 1.0;
    double y = 1.0;
    Position(const Position &pos)
    {
	x = pos.x;
	y = pos.y;
    }
    Position()
    {
	x = 1.0;
	y = 1.0;
    }
};

char getObject(const Position &pos)
{
    return map[(int)pos.x][(int)pos.y];
}

int rayTrace(int *dists, const int &numrays, const Position &pos, const int &dir, const double &fov)
{
    int max = 0;
    double angle = dir-(fov/2);
    double increment = fov/numrays;
    for (int ii = 0; ii < numrays; ii++)
    {
	Position ray(pos);
	dists[ii] = 0;
	while (getObject(ray) != '#' && getObject(ray) != 'X')
	{
	    ray.x += 0.1*cos(angle*PI/180);
	    ray.y += 0.1*sin(angle*PI/180);
	    dists[ii]++;
	    if (max < dists[ii]) 
		max = dists[ii];
	}
	angle += increment;
    }
    return max;
}

void renderScreen(int width, int height, int *steps)
{
    std::string screen[height]{""};

    for (int ii = 0; ii < height; ii++)
    {
	std::cout << LINE_DEL;
    }

    for (int ii = 0; ii < height; ii++)
    {
	for (int jj = 0; jj < width; jj++)
	{
	    double ratio = (double)steps[width-jj-1]/(double)MAX_STEPS;
	    std::string str_char = " ";
	    if (ratio > .66)
	    {
		str_char = "\u2591";
	    }
	    else if (ratio > .33)
	    {
		str_char = "\u2592";
	    }
	    else
	    {
		str_char = "\u2593";
	    }

	    int wallHeight = (int)(((double)MAX_STEPS-(double)steps[width-jj-1])*((double)height/(double)MAX_STEPS));
	    int bottom = (height-wallHeight)/2;
	    int top = height - bottom;
	    if (ii >= bottom && ii <= top)
	    {
		screen[ii] += str_char;
	    }
	    else if (ii < bottom)
	    {
		screen[ii] += "`";
	    }
	    else
	    {
		screen[ii] += "~";
	    }
	}
    }


    for (int ii = 0; ii < height; ii++)
    {
	std::cout << screen[ii] << std::endl;
    }
}

int main(int argc, char **argv)
{

    // Get the parameter settings
    int height = std::atoi(argv[1]), 
	width = std::atoi(argv[2]), 
	fov = std::atoi(argv[3]),
	dir = 0;

    Position playerPos;
    for (int ii = 0 ; ii < 10; ii++)
    {
	std::size_t jj = map[ii].find("P");
	if (jj != std::string::npos)
	{
	    playerPos.x = (double)ii;
	    playerPos.y = (double)jj;
	}
	std::cout << map[ii] << std::endl;
    }

    //std::cout << "\u2591\u2592\u2593\tMax: " << MAX_STEPS << std::endl;
    for (int ii = 0 ; ii < height; ii++)
	std::cout << std::endl;

    // Initialize screen
    int *distances = new int[width];
    while (true)
    {
	// Ray Trace
	rayTrace(distances, width, playerPos, dir, fov);
	renderScreen(width, height, distances);
	dir = (dir+1)%360;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
