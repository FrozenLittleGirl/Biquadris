#ifndef _BLOCK_H
#define _BLOCK_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Block {
    protected:
    size_t xCoord;         // x coordinate of the top left piece of the block
    size_t yCoord;         // y coordinate of the top left piece of the block
    size_t rotateAngle;    // angle of rotation of the block, can only be 4 values:
                           // 0, 90, 180, 270
    bool heavy;            // true if the current block is affect by the "heavy" effect
    size_t howHeavy;       // if it is heavy, how many rows will it fall for each move
                           // otherwise the value of howHeavy is 0
    char name;             // name of the current block, (ex. 'S', 'T', 'O', and so on)
    
    public:
    Block(size_t x, size_t y, size_t angle, bool isHeavy, size_t heavyCount, char name);
    // constructor
    virtual ~Block() = default;          // destructor
    
    virtual std::vector<std::string> getRotateDefault() = 0;
    virtual std::vector<std::string> getRotate90() = 0;
    virtual std::vector<std::string> getRotate180() = 0;
    virtual std::vector<std::string> getRotate270() = 0;
    // return the string representation of rotation of the block in 0, 90, 180, 270 degrees
    size_t getXcoord();            // returns the x coordinate
    size_t getYcoord();            // returns the y coordinate
    size_t getAngle();             // returns the current angle rotated
    bool isHeavy();                // returns if the block is affected by the "Heavy" effect
    char getName();                // returns the name(type) of the block
    size_t getHowHeavy();          // returns how heavy the block is
    void setXcoord(size_t x);      // sets the x coordinate
    void setYcoord(size_t y);      // sets the y coordinate
    void setAngle(size_t angle);   // sets the current rotated angle
    void setHeavy(bool isHeavy);   // sets if the current block is heavy or not
    void setHowHeavy(size_t heavyCount);        // sets how heavy the block is
};




#endif
