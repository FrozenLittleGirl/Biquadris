#ifndef _CELL_H
#define _CELL_H
#include <iostream>
#include <vector>
#include <string>


class Cell {
    int x;
    int y;
    bool occupied;
    char name;
    
    public:
    Cell(int x, int y, bool occupied, char c);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    bool isOccupied();
    char getName();
    void setName(char c);
    void clearCell();
};

#endif
