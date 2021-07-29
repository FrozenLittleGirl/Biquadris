#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "NextBlock.h"
#include <vector>

using namespace std;

class Block;

class levelZero : public NextBlock {
	vector<char> sequence;
	int size;
	int current;
public:
	levelZero(string file, int sd, bool set_sd);
	shared_ptr<Block> generateBlock() override;
};

class levelOne : public NextBlock {
	double probSZ = 1;
	double probOther = 2;
public:
	levelOne(int sd, bool set_sd);
	shared_ptr<Block> generateBlock() override;
};

class levelTwo : public NextBlock {
	double prob = 1;
public:
	levelTwo(int sd, bool set_sd);
	shared_ptr<Block> generateBlock() override;
};

class levelThree : public NextBlock {
	double probSZ = 2;
	double probOther = 1;
public:
	levelThree(int sd, bool set_sd);
	shared_ptr<Block> generateBlock() override;
};

class levelFour : public NextBlock {
	double probSZ = 2;
	double probOther = 1;
	int count = 0;
	bool clear = false;
public:
	levelFour(int sd, bool set_sd);
	shared_ptr<Block> generateBlock() override;

	// set field clear true or false
	// This decides whether there is at least one row been cleared after every 5 blocks created
	void setclear(bool clear);
};

#endif
