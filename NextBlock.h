#ifndef _NEXTBLOCK_H_
#define _NEXTBLOCK_H_

#include "Block.h"

class NextBlock {
protected:
	int sd;
	bool set_sd;
public:
	NextBlock(int sd, bool set_sd);
	// generate a new block
	virtual shared_ptr<Block> generateBlock() = 0;
	virtual void changeState(bool set, string s) = 0;
	~NextBlock();
};

#endif
