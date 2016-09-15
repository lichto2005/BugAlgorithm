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

#define BUG_TYPE 1

int main() {
    std::cout << "Bug Algorithm\n" << std::endl;
	Grid bugGrid(25, 25);
	for (int i = 1; i < 15; i++)
	{
		bugGrid.setValue(i, 10, 1);
	}
	Bug bug(0, 0, 14, 18, bugGrid);
	bug.setDisplayGrid(true);

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

				while (bug.sense(direction) == 1)
				{
					bug.move(Grid::getNextCoordinate(direction));
				}
				bug.move(direction);
				direction = Grid::getNextCoordinate(direction);

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
					if (bug.getColPos() == shortestCol && bug.getRowPos() == shortestRow) atShortest = true;
					bug.move(nextDirection);
				}
				bug.move(direction);
				while (bug.sense(prevDirection) == 1 && !atShortest)
				{
					if (bug.getColPos() == shortestCol && bug.getRowPos() == shortestRow) atShortest = true;
					bug.move(direction);
				}
				bug.move(prevDirection);
				while (bug.sense(oppDirection) == 1 && !atShortest)
				{
					if (bug.getColPos() == shortestCol && bug.getRowPos() == shortestRow) atShortest = true;
					bug.move(prevDirection);
				}
				bug.move(oppDirection);
				while (bug.sense(nextDirection) == 1 && !atShortest)
				{
					if (bug.getColPos() == shortestCol && bug.getRowPos() == shortestRow) atShortest = true;
					bug.move(oppDirection);
				}
				bug.move(nextDirection);
				while (bug.getColPos() != startCol || bug.getRowPos() != startRow && !atShortest)
				{
					if (bug.getColPos() == shortestCol && bug.getRowPos() == shortestRow) atShortest = true;
					bug.move(nextDirection);
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

	std::cout << "Goal Found in " << bug.getStepsMoved() << " steps.";
    return 0;
}