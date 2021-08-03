#ifndef _SBLOCK_H
#define _SBLOCK_H
#include <vector>
#include <string>
#include "block.h"


class Sblock: public Block {
    
    public:
    Sblock(int x, int y, int angle, bool isHeavy, int heavyCount, char name);
    virtual std::vector<std::string> getRotateDefault() override;
    virtual std::vector<std::string> getRotate90() override;
    virtual std::vector<std::string> getRotate180() override;
    virtual std::vector<std::string> getRotate270() override;
    
};

#endif
