//
// Created by Noah Lichtenstein on 9/12/2016.
//

#include <iostream>
#include "Grid.h"

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
    for(int i = 0; i < this->length; i++)
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

void Grid::setWidth(int width)
{

}

void Grid::setLength(int length)
{

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
