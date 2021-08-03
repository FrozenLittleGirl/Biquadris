#ifndef _CELL_H
#define _CELL_H
#include <iostream>
#include <vector>
#include <string>


class Display;

class Cell {
    int x;
    int y;
    bool occupied;
    char name;
    int colour;
    int level_n = 0;
    
    public:
    Cell(int x, int y, bool occupied, char c);
    int getX();
    int getY();
    void setColour();
    void display(int x_coord, int y_coord);
    void setX(int x);
    void setY(int y);
    bool isOccupied();
    char getName();
    void setName(char c);
    void setLevel(int level_n);
    int getLevel();
    void clearCell();
};

#endif
