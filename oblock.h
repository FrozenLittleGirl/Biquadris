#ifndef _OBLOCK_H
#define _OBLOCK_H


#include "block.h"
#include <iostream>
#include <vector>
#include <string>


class Oblock: public Block {
    
    public:
    Oblock(int x, int y, int angle, bool isHeavy, int heavyCount, char name);
    virtual std::vector<std::string> getRotateDefault() override;
    virtual std::vector<std::string> getRotate90() override;
    virtual std::vector<std::string> getRotate180() override;
    virtual std::vector<std::string> getRotate270() override;
    
};

#endif
