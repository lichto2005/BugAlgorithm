//
// Created by Noah Lichtenstein on 9/13/16
//

#ifndef BUG_H
#define BUG_H

#define BUG 5
#define PATH 2
#define START 3
#define GOAL 4
#define MLINE 6
#define WALL 1

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

#include "Grid.h"

class Bug
{
private:
	Grid grid;
	int stepsMoved = 0;
	int rowPos = 0, colPos = 0;
	int goalRow, goalCol;
	void printGrid();
	bool displayGrid = true;
	int pathVal = PATH;
public:
	Bug();
	Bug(int rowPos, int colPos, int goalRow, int goalCol, Grid& grid);
	void move(int direction);
	int sense(int direction);
	int calculateDirection();
	double calculateDistance();
	void setDisplayGrid(bool displayGrid);
	int getStepsMoved();
	int getRowPos();
	int getColPos();
	int getPathVal();
	void setPathVal(int pathVal);
};

#endif