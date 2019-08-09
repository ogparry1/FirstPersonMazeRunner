#include <iostream>
#include <cstdlib> // system
#include <string> // string
#include <thread> // thread
#include <chrono> // thread
#include <cmath> // sin, cos

#include "../include/MazeRunner.hpp"

#define PI 3.14159265

using namespace Maze;

int main(int argc, char **argv)
{
    int width = std::atoi(argv[1]), 
	height = std::atoi(argv[2]), 
	degFOV = std::atoi(argv[3]),
	dir = 0;
    int rays[width] = {0};
    int S[] = {0,0},
	E[] = {0,0};
    double P[] = {0,0};

    std::string map[10] = 
    {
	"##########",
	"########.E",
	"#........#",
	"######...#",
	"#........#",
	"#........#",
	"#....#...#",
	"#..S.#...#",
	"#....#...#",
	"##########"
    };

    for (int ii = 0; ii < 10; ii++)
    {
	for (int jj = 0; jj < 10; jj++)
	{
	    if (map[ii][jj] == 'S')
	    {
		S[0] = ii;
		S[1] = jj;
	    }
	    else if (map[ii][jj] == 'E')
	    {
		E[0] = ii;
		E[1] = jj;
	    }
	    else if (map[ii][jj] == 'P')
	    {
		P[0] = ii+0.5;
		P[1] = jj+0.5;
	    }
	    else {}
	}
    }

    const double raystep = 0.5;
    while (true)
    {
	int deg = dir-degFOV/2;
	double raypos[2];
	int max = 0;

	// Ray Trace
	for (int ii = 0; ii < width; ii++)
	{
	    raypos[0] = P[0];
	    raypos[1] = P[1];
	    rays[ii] = 0;
	    while (map[(int)raypos[0]][(int)raypos[1]] != '#')
	    {
		raypos[0] += raystep*std::cos(deg*PI/180);
		raypos[1] += raystep*std::sin(deg*PI/180);
		rays[ii] += 1;
	    }
	    if (max < rays[ii]) max = rays[ii];
	    deg += degFOV/width;
	}

	// Print to Screen
	for (int ii = 0; ii < width; ii++)
	{
	}

	// Check for user input and adjust
    }
    return 0;
}
