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
	Bug bug(0, 0, 14, 18, bugGrid);

	while (bug.calculateDirection() != 0)
	{
		bug.move(bug.calculateDirection());
	}
	std::cout << "Goal Found in " << bug.getStepsMoved() << " steps.";
    return 0;
}