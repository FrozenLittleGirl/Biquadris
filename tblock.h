#ifndef _TBLOCK_H
#define _TBLOCK_H

#include "block.h"
#include <vector>
#include <string>


class Tblock: public Block {
    
    public:
    Tblock(int x, int y, int angle, bool isHeavy, int heavyCount, char name);
    virtual std::vector<std::string> getRotateDefault() override;
    virtual std::vector<std::string> getRotate90() override;
    virtual std::vector<std::string> getRotate180() override;
    virtual std::vector<std::string> getRotate270() override;
    
};

#endif
