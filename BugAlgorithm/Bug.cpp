//
// Created by Noah Lichtenstein on 9/13/16
//

#include <math.h>
#include "Bug.h"

Bug::Bug()
{
	//noop
}

Bug::Bug(int rowPos, int colPos, int goalRow, int goalCol, Grid& grid)
{
	this->rowPos = rowPos;
	this->colPos = colPos;
	this->goalRow = goalRow;
	this->goalCol = goalCol;
	this->grid = grid;
	grid.setValue(rowPos, colPos, BUG);
	grid.setValue(goalRow, goalCol, GOAL);
	printGrid();
}

void Bug::move(int direction)
{
	grid.setValue(rowPos, colPos, pathVal);
	switch (direction)
	{
	case NORTH:
		if (rowPos == grid.getLength())
		{
			break;
		}
		rowPos++;
		break;
	case EAST:
		if (colPos == grid.getWidth())
		{
			break;
		}
		colPos++;
		break;
	case SOUTH:
		if (rowPos == 0)
		{
			break;
		}
		rowPos--;
		break;
	case WEST:
		if (colPos == 0)
		{
			break;
		}
		colPos--;
		break;
	default:
		break;
	}
	grid.setValue(rowPos, colPos, BUG);
	stepsMoved++;
	printGrid();
}

int Bug::sense(int direction)
{
	switch (direction)
	{
	case NORTH:
		if (rowPos == grid.getLength())
		{
			break;
		}
		return grid.getValue(rowPos+1, colPos);
	case EAST:
		if (colPos == grid.getWidth())
		{
			break;
		}
		return grid.getValue(rowPos, colPos+1);
	case SOUTH:
		if (rowPos == 0)
		{
			break;
		}
		return grid.getValue(rowPos-1, colPos);
	case WEST:
		if (colPos == 0)
		{
			break;
		}
		return grid.getValue(rowPos, colPos-1);
	default:
		return -1;
	}
}

int Bug::calculateDirection()
{
	
	int xDist = goalCol - colPos;
	int yDist = goalRow - rowPos;

	int xChanges[5] = { 0, 0, -1, 0, 1 };
	int yChanges[5] = { 0, -1, 0, 1, 0 };
	double shortestDist = sqrt(xDist*xDist + yDist*yDist);
	int direction = 0;
	for (int i = 0; i < 5; i++)
	{
		if (sqrt((xDist + xChanges[i])*(xDist + xChanges[i]) + (yDist + yChanges[i])*(yDist + yChanges[i])) < shortestDist)
		{
			shortestDist = sqrt((xDist + xChanges[i])*(xDist + xChanges[i]) + (yDist + yChanges[i])*(yDist + yChanges[i]));
			direction = i;
		}
	}

	return direction;
}

double Bug::calculateDistance()
{
	int xDist = goalRow - rowPos;
	int yDist = goalCol - colPos;
	return sqrt(xDist*xDist + yDist*yDist);
}

void Bug::setDisplayGrid(bool displayGrid)
{
	this->displayGrid = displayGrid;
}

int Bug::getStepsMoved()
{
	return stepsMoved;
}

int Bug::getRowPos()
{
	return rowPos;
}

int Bug::getColPos()
{
	return colPos;
}

void Bug::printGrid()
{
	if (displayGrid)
	{
		grid.printGrid();
	}
}

int Bug::getPathVal()
{
	return pathVal;
}

void Bug::setPathVal(int pathVal)
{
	this->pathVal = pathVal;
}