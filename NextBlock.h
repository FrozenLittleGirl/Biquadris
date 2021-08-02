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
        NextBlock(int sd, bool set_sd);
        // generate a new block
        virtual Block* generateBlock() = 0;
        virtual void changeState(bool set, string s) = 0;
        virtual ~NextBlock();
};

#endif
