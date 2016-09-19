//
// Created by Noah Lichtenstein on 9/12/16
//

#include <iostream>
#include "Grid.h"
#include "Bug.h"

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

#define BUG_TYPE 2

int main() {
    std::cout << "Bug Algorithm\n" << std::endl;
	Grid bugGrid(25, 25);
	int goalRow = 14, goalCol = 18;
	Bug bug(0, 0, goalRow, goalCol, bugGrid);
	bug.setDisplayGrid(true);
	
	if (BUG_TYPE == 2)
	{
		Bug mLine(0, 0, goalRow, goalCol, bugGrid);
		mLine.setPathVal(MLINE);
		mLine.setDisplayGrid(false);
		while (mLine.calculateDirection() != 0)
		{
			int direction = mLine.calculateDirection();
			mLine.move(direction);
		}
		bugGrid.setValue(0, 0, BUG);
		bugGrid.setValue(goalRow, goalCol, GOAL);
		mLine.setDisplayGrid(true);
	}

	for (int i = 1; i < 15; i++)
	{
		bugGrid.setValue(i, 10, WALL);
	}
	
	if (BUG_TYPE == 0)
	{
		//Bug0
		while (bug.calculateDirection() != 0)
		{
			int direction = bug.calculateDirection();
			if (bug.sense(direction) == 1)
			{
				//std::cout << bug.sense(direction) << std::endl;
				direction--;
				if (direction == 0) direction = 4;
			}
			bug.move(direction);
		}
	}
	else if (BUG_TYPE == 1)
	{
		bool onWall;
		int direction = bug.calculateDirection();
		onWall = bug.sense(direction) == 1;
		while (bug.calculateDirection() != 0)
		{
			if (onWall)
			{
				bool atShortest = false;

				/*while (bug.sense(direction) == 1)
				{
					bug.move(Grid::getNextCoordinate(direction));
				}
				bug.move(direction);
				direction = Grid::getNextCoordinate(direction);*/

				int startRow = bug.getRowPos();
				int startCol = bug.getColPos();

				double shortestDistance = bug.calculateDistance();
				int shortestRow = bug.getRowPos();
				int shortestCol = bug.getColPos();

				int nextDirection = Grid::getNextCoordinate(direction);
				int prevDirection = Grid::getPrevCoordinate(direction);
				int oppDirection = Grid::getOppositeCoordinate(direction);
				while (bug.sense(direction) == 1)
				{
					double dist = bug.calculateDistance();
					if (dist < shortestDistance)
					{
						shortestDistance = dist;
						shortestRow = bug.getRowPos();
						shortestCol = bug.getColPos();
					}
					bug.move(nextDirection);
				}
				bug.move(direction);
				while (bug.sense(prevDirection) == 1)
				{
					double dist = bug.calculateDistance();
					if (dist < shortestDistance)
					{
						shortestDistance = dist;
						shortestRow = bug.getRowPos();
						shortestCol = bug.getColPos();
					}
					bug.move(direction);
				}
				bug.move(prevDirection);
				while (bug.sense(oppDirection) == 1)
				{
					double dist = bug.calculateDistance();
					if (dist < shortestDistance)
					{
						shortestDistance = dist;
						shortestRow = bug.getRowPos();
						shortestCol = bug.getColPos();
					}
					bug.move(prevDirection);
				}
				bug.move(oppDirection);
				while (bug.sense(nextDirection) == 1)
				{
					double dist = bug.calculateDistance();
					if (dist < shortestDistance)
					{
						shortestDistance = dist;
						shortestRow = bug.getRowPos();
						shortestCol = bug.getColPos();
					}
					bug.move(oppDirection);
				}
				bug.move(nextDirection);
				while (bug.getColPos() != startCol || bug.getRowPos() != startRow)
				{
					double dist = bug.calculateDistance();
					if (dist < shortestDistance)
					{
						shortestDistance = dist;
						shortestRow = bug.getRowPos();
						shortestCol = bug.getColPos();
					}
					bug.move(nextDirection);
				}
				while (bug.sense(direction) == 1 && !atShortest)
				{
					bug.move(nextDirection);
					if (bug.getColPos() == shortestCol && bug.getRowPos() == shortestRow) atShortest = true;
					
				}
				if(!atShortest) bug.move(direction);
				while (bug.sense(prevDirection) == 1 && !atShortest)
				{
					bug.move(direction);
					if (bug.getColPos() == shortestCol && bug.getRowPos() == shortestRow) atShortest = true;
					
				}
				if(!atShortest) bug.move(prevDirection);
				while (bug.sense(oppDirection) == 1 && !atShortest)
				{
					bug.move(prevDirection);
					if (bug.getColPos() == shortestCol && bug.getRowPos() == shortestRow) atShortest = true;
					
				}
				if(!atShortest) bug.move(oppDirection);
				while (bug.sense(nextDirection) == 1 && !atShortest)
				{
					bug.move(oppDirection);
					if (bug.getColPos() == shortestCol && bug.getRowPos() == shortestRow) atShortest = true;
				}
				if(!atShortest) bug.move(nextDirection);
				while ((bug.getColPos() != startCol || bug.getRowPos() != startRow) && !atShortest)
				{
					bug.move(nextDirection);
					if (bug.getColPos() == shortestCol && bug.getRowPos() == shortestRow) atShortest = true;

				}
				if(atShortest == true) onWall = false;
				
			}
			else
			{
				direction = bug.calculateDirection();
				if (bug.sense(direction) == 1)
				{
					onWall = true;
					continue;
				}
				bug.move(direction);
			}
		}
	}
	else if (BUG_TYPE == 2)
	{
		bugGrid.printGrid();
		while (bug.calculateDirection() != 0)
		{
			double currentDistance = bug.calculateDistance();
			for (int i = 1; i < 5; i++)
			{
				if (bug.sense(i) == 1 && bug.calculateDirection() == i)
				{
					int direction = i;
					int nextDirection = Grid::getNextCoordinate(direction);
					int prevDirection = Grid::getPrevCoordinate(direction);
					int oppDirection = Grid::getOppositeCoordinate(direction);
					bool foundLine = false;
					while (bug.sense(direction) == 1 && !foundLine)
					{
						if (bug.sense(Grid::getOppositeCoordinate(direction)) == 6)
						{
							foundLine = true;
							break;
						}
						bug.move(nextDirection);
					}
					if(!foundLine) bug.move(direction);
					while (bug.sense(prevDirection) == 1 && !foundLine)
					{
						if (bug.sense(Grid::getOppositeCoordinate(prevDirection)) == 6)
						{
							foundLine = true;
							break;
						}
						bug.move(direction);
					}
					if(!foundLine) bug.move(prevDirection);
					while (bug.sense(oppDirection) == 1 && !foundLine)
					{
						if (bug.sense(Grid::getOppositeCoordinate(oppDirection)) == 6)
						{
							foundLine = true;
							break;
						}
						bug.move(prevDirection);
					}
					if(!foundLine) bug.move(oppDirection);
					while (bug.sense(nextDirection) == 1 && !foundLine)
					{
						if (bug.sense(Grid::getOppositeCoordinate(prevDirection)) == 6)
						{
							foundLine = true;
							break;
						}
						bug.move(oppDirection);
					}
					if(!foundLine) bug.move(nextDirection);
				}
				if (bug.sense(i) == 6)
				{
					bug.move(i);
					break;
				}

				if(bug.sense(i) == GOAL)
				{
					bug.move(i);
				}
			}
		}
	}

	std::cout << "Goal Found in " << bug.getStepsMoved() << " steps.";
    return 0;
}