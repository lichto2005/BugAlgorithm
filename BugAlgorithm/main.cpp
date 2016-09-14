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

int main() {
    std::cout << "Bug Algorithm\n" << std::endl;
	Grid bugGrid(25, 25);
	//
	Bug bug(0, 0, 14, 18, bugGrid);
	bug.setDisplayGrid(true);

	while (bug.calculateDirection() != 0)
	{
		int direction = bug.calculateDirection();
		if (bug.sense(direction) == 1)
		{
			//std::cout << bug.sense(direction) << std::endl;
			direction++;
			if (direction == 5) direction = 1;
		}
		bug.move(direction);
	}
	std::cout << "Goal Found in " << bug.getStepsMoved() << " steps.";
    return 0;
}