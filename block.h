#ifndef _BLOCK_H
#define _BLOCK_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Block {
    protected:
    unsigned int xCoord;
    unsigned int yCoord;
    unsigned int rotateAngle;
    bool heavy;
    unsigned int heavyLevel;
    
    public:
    Block(size_t x, size_t y, size_t angle, bool isHeavy, size_t heavyLevel);
    ~Block();
    
    size_t getXcoord();
    size_t getYcoord();
    size_t getAngle();
    bool isHeavy();
    size_t getHeavyLevel();
    
    void setXcoord();
    void setYcoord();
    void setAngle();
    void setHeavy(size_t heavyLevel);
    
};


#endif
