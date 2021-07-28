#ifndef _LBLOCK_H
#define _LBLOCK_H

#include "block.h"
#include <vector>
#include <string>

class Lblock: public Block {
    
    public:
    Lblock(size_t x, size_t y, size_t angle, bool isHeavy, size_t heavyCount, char name);
    virtual std::vector<std::string> getRotateDefault() override;
    virtual std::vector<std::string> getRotate90() override;
    virtual std::vector<std::string> getRotate180() override;
    virtual std::vector<std::string> getRotate270() override;
    
};

#endif


