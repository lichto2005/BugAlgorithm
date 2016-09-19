//
// Created by Noah Lichtenstein on 9/12/2016.
//

#include <iostream>
#include "Grid.h"

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

Grid::Grid()
{
    gridArr = new int[100 * 100];
	for (int i = 0; i < 100 * 100; i++)
	{
		gridArr[i] = 0;
	}
}

Grid::Grid(int width, int length)
{
    this->width = width;
    this->length = length;
    gridArr = new int[width * length];
	for (int i = 0; i < width * length; i++)
	{
		gridArr[i] = 0;
	}
}

void Grid::printGrid()
{
    for(int i = this->length-1; i >= 0; i--)
    {
        for(int j = 0; j < this->width; j++)
        {
            std::cout << gridArr[index(i,j)] << " ";
        }
		std::cout << std::endl;
    }
	std::cout << std::endl;
}

int Grid::getWidth()
{
    return this->width;
}

int Grid::getLength()
{
    return this->length;
}

int Grid::index(int row, int col)
{
	return col + row * width;
}

void Grid::setValue(int row, int col, int value)
{
	gridArr[index(row, col)] = value;
}

int Grid::getValue(int row, int col)
{
	return gridArr[index(row,col)];
}

int Grid::getOppositeCoordinate(int coordinate)
{
	switch (coordinate)
	{
	case NORTH:
		return SOUTH;
	case SOUTH:
		return NORTH;
	case EAST:
		return WEST;
	case WEST:
		return EAST;
	default:
		return -1;
	}
}

int Grid::getNextCoordinate(int coordinate)
{
	switch (coordinate)
	{
	case NORTH:
		return EAST;
	case EAST:
		return SOUTH;
	case SOUTH:
		return WEST;
	case WEST:
		return NORTH;
	default:
		return -1;
	}
}

int Grid::getPrevCoordinate(int coordinate)
{
	switch (coordinate)
	{
	case NORTH:
		return WEST;
	case EAST:
		return NORTH;
	case SOUTH:
		return EAST;
	case WEST:
		return SOUTH;
	default:
		return -1;
	}
}
