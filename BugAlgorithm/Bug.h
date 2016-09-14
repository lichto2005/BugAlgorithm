//
// Created by Noah Lichtenstein on 9/13/16
//

#ifndef BUG_H
#define BUG_H

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
public:
	Bug();
	Bug(int rowPos, int colPos, int goalRow, int goalCol, Grid grid);
	void move(int direction);
	int sense(int direction);
	int calculateDirection();
	void setDisplayGrid(bool displayGrid);
	int getStepsMoved();
};

#endif