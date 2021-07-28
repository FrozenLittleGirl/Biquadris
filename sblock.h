#ifndef _SBLOCK_H
#define _SBLOCK_H
#include <vector>
#include <string>
#include "block.h"


class Sblock: public Block {
    
    public:
    Sblock(size_t x, size_t y, size_t angle, bool isHeavy, size_t heavyCount, char name);
    virtual std::vector<std::string> getRotateDefault() override;
    virtual std::vector<std::string> getRotate90() override;
    virtual std::vector<std::string> getRotate180() override;
    virtual std::vector<std::string> getRotate270() override;
    
};

#endif
