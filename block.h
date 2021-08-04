#ifndef _BLOCK_H
#define _BLOCK_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Block {
    protected:
    int xCoord;         // x coordinate of the top left piece of the block
    int yCoord;         // y coordinate of the top left piece of the block
    int rotateAngle;    // angle of rotation of the block, can only be 4 values:
                           // 0, 90, 180, 270
    bool heavy;            // true if the current block is affect by the "heavy" effect
    int howHeavy;       // if it is heavy, how many rows will it fall for each move
                           // otherwise the value of howHeavy is 0
    char name;             // name of the current block, (ex. 'S', 'T', 'O', and so on)
    int level_n = 0;

    public:
    Block(int x, int y, int angle, bool isHeavy, int heavyCount, char name);
    // constructor
    virtual ~Block() = default;          // destructor

    virtual std::vector<std::string> getRotateDefault() = 0;
    virtual std::vector<std::string> getRotate90() = 0;
    virtual std::vector<std::string> getRotate180() = 0;
    virtual std::vector<std::string> getRotate270() = 0;
    // return the string representation of rotation of the block in 0, 90, 180, 270 degrees
    int getXcoord();            // returns the x coordinate
    int getYcoord();            // returns the y coordinate
    int getAngle();             // returns the current angle rotated
    bool isHeavy();                // returns if the block is affected by the "Heavy" effect
    char getName();                // returns the name(type) of the block
    int getHowHeavy();          // returns how heavy the block is
    void setXcoord(int x);      // sets the x coordinate
    void setYcoord(int y);      // sets the y coordinate
    void setAngle(int angle);   // sets the current rotated angle
    void setHeavy(bool isHeavy);   // sets if the current block is heavy or not
    void setHowHeavy(int heavyCount);        // sets how heavy the block is
    void setLevel(int level_n);
    int getLevel();
};




#endif
