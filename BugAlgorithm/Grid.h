//
// Created by Noah Lichtenstein on 9/12/2016.
//

#ifndef BUGALGORITHM1_BUGGRID_H
#define BUGALGORITHM1_BUGGRID_H

class Grid
{
private:
    int *gridArr;
    int width;
    int length;

public:
    Grid();
    Grid(int width, int length);
    int getWidth();
    int getLength();
    void setWidth(int width);
    void setLength(int length);
	int index(int row, int col);
	void setValue(int row, int col, int value);
	int getValue(int row, int col);
	static int getOppositeCoordinate(int coordinate);
	static int getNextCoordinate(int coordinate);
	static int getPrevCoordinate(int coordinate);
    void printGrid();
};

#endif //BUGALGORITHM1_BUGGRID_H