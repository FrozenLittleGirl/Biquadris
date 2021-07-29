#ifndef _CELL_H
#define _CELL_H
#include <iostream>
#include <vector>
#include <string>


class Cell {
    size_t x;
    size_t y;
    bool occupied;
    char name;
    
    public:
    Cell(size_t x, size_t y, bool occupied, char c);
    size_t getX();
    size_t getY();
    void setX(size_t x);
    void setY(size_t y);
    bool isOccupied();
    char getName();
    void setName(char c);
    void clearCell();
};

#endif
