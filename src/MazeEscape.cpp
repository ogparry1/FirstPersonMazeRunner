#include <iostream>
#include <cstdlib> // system
#include <string> // string
#include <thread> // thread
#include <chrono> // thread

#include "../include/MazeRunner.hpp"

using namespace Maze;

int main(int argc, char **argv)
{
    int width = argv[1], height = argv[2];
    int start[2] = {0,0}, end[2] = {0,0};
    std::string map[10] = 
    {
	"#E########",
	"#.#......#",
	"#.#.####.#",
	"#.#.#S.#.#",
	"#.#.##.#.#",
	"#.#....#.#",
	"#.#....#.#",
	"#.######.#",
	"#........#",
	"##########"
    };
    for (int ii = 0; ii < arrSize(map); ii++)
    {
	for (int jj = 0; jj < arrSize(map); jj++)
	{
	}
    }

    MazeRunner runner(100, 100);
    return 0;
}
