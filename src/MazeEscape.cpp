#include <chrono> // thread
#include <cmath> // sin, cos
#include <cstdlib> // system
#include <iostream>
#include <string> // string
#include <thread> // thread

//#include "../include/MazeRunner.hpp"

#define PI 3.14159265

const std::string LINE_DEL = "\033[1A\033[K";

std::string map[10] = 
{
    "##########",
    "#........E",
    "#........#",
    "#........#",
    "#........#",
    "#....S...#",
    "#........#",
    "#........#",
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
	while (getObject(ray) != '#' && getObject(ray) != 'E')
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

char getASCII(int steps, int max)
{
    double ratio = (double)steps/(double)max;
    if (ratio < .50)
    {
	return '.';
	//return '\xB0';
    }
    else if (ratio < .75)
    {
	return '*';
	//return '\xB1';
    }
    else
    {
	return '#';
	//return '\xB2';
    }
}

int main(int argc, char **argv)
{
    // Get the parameter settings
    int height = std::atoi(argv[1]), 
	width = std::atoi(argv[2]), 
	fov = std::atoi(argv[3]),
	dir = 45;
    Position playerPos;
    for (int ii = 0 ; ii < 10; ii++)
    {
	std::size_t jj = map[ii].find("S");
	if (jj != std::string::npos)
	{
	    playerPos.x = (double)ii;
	    playerPos.y = (double)jj;
	}
	std::cout << map[ii] << std::endl;
    }
    std::cout << "Player Position = { " << playerPos.x << ", " << playerPos.y << " }" << std::endl;

    // Ray Trace
    int *distances = new int[width];
    int maxDist = rayTrace(distances, width, playerPos, dir, fov);
    for (int ii = 0 ; ii < height; ii++)
    {
	for (int jj = 0 ; jj < width; jj++)
	{
	    std::cout << getASCII(distances[jj], maxDist);
	}
	std::cout << std::endl;
    }

    return 0;
}
