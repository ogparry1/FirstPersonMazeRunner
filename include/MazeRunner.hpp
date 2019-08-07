#include <chrono> // thread
#include <cstdlib> // system
#include <iostream>
#include <mutex> // mutex
#include <string> // string
#include <thread> // thread

namespace Maze
{

struct Maze
{
    std::string map[10] = {""};
    int start[2], end[2];
    double pos[2];



    Maze(std::string m[10])
    {
	map = m;
	for (int ii = 0; ii < 10; ii++)
	{
	    for (int jj = 0; jj < 10; jj++)
	    {
		if (map[ii][jj] == 'S')
		{
		    start = {ii,jj};
		    pos = {ii,jj};
		}
		if (map[ii][jj] == 'E')
		{
		    end = {ii,jj};
		}
	    }
	}
    }

};

class MazeRunner
{
    public:
	MazeRunner(int w, int h);
	void renderScreen();
	void turnLeft();
	void turnRight();
	void moveForward();
	void moveBackward();
	~MazeRunner();

    private:
	int angle, degrees;
	int width, height;
	std::string *screen;
	std::mutex mtx;
	int *rays;

};



}
