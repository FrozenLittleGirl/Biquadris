#ifndef _NEXTBLOCK_H_
#define _NEXTBLOCK_H_
#include <string>
#include "block.h"

using namespace std;

class NextBlock {
protected:
        int sd;
        bool set_sd;
public:
        // initialzie the block with seed if set_seed is true
        NextBlock(int sd, bool set_sd);
        // generate a new block
        virtual Block* generateBlock() = 0;
        // convert level 3 or 4 to random/nonrandom based on bool set
        virtual void changeState(bool set, string s) = 0;
        virtual ~NextBlock();
};

#endif
