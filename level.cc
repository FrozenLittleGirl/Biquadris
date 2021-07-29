#include <fstream>
#include <memory>
#include "level.h"
#include "Block.h"
#include "random.h"

using namespace std;

// Level0
levelZero::levelZero(string file, int sd, bool set_sd) : NextBlock{ sd, set_sd } {
	ifstream infile{ file };
    char c;
    while (true) {
        infile >> c;
        if (infile.fail()) break;
        sequence.emplace_back(c);
        ++size;
    }
}

shared_ptr<Block> levelZero::generateBlock() {
    char c = sequence[current];
    auto p = make_shared<Block>(c);
    return p;
}

// Level1
levelOne::levelOne(int sd, bool set_sd) : NextBlock{sd, set_sd} {}

shared_ptr<Block> levelOne::generateBlock() {
    char c = setChar(probSZ, probOther, sd, set_sd);
    auto p = make_shared<Block>(c);
    return p;
}

// Level2
levelTwo::levelTwo(int sd, bool set_sd) : NextBlock{ sd, set_sd } {}

shared_ptr<Block> levelTwo::generateBlock() {
    char c = setChar(prob, prob, sd, set_sd);
    auto p = make_shared<Block>(c);
    return p;
}

// Level3
levelThree::levelThree(int sd, bool set_sd) : NextBlock{ sd, set_sd } {}

shared_ptr<Block> levelThree::generateBlock() {
    char c = setChar(probSZ, probOther, sd, set_sd);
    auto p = make_shared<Block>(c);
    return p;
}

// Level4
levelFour::levelFour(int sd, bool set_sd): NextBlock{ sd, set_sd } {}

shared_ptr<Block> levelFour::generateBlock() {
    ++count;
    char c = setChar(probSZ, probOther, sd, set_sd);
    auto p = make_shared<Block>(c);
    if (count % 5 == 0 && clear == false) {
        auto dot = make_shared<Block>('*');
        dot->drop();
    }
    return p;
}

void levelFour::setclear(bool clear) {
    this->clear = clear;
}
