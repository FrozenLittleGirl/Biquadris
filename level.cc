#include <fstream>
#include "level.h"
#include "Board.h"
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
    auto p = make_shared<Block>(0, 0, 0, false, 0, c);
    ++current;
    if (current == size) {
        current = 0;
    }
    return p;
}

void levelZero::changeState(bool set, string s) {}

// Level1
levelOne::levelOne(int sd, bool set_sd) : NextBlock{sd, set_sd} {}

shared_ptr<Block> levelOne::generateBlock() {
    char c = setChar(probSZ, probOther, sd, set_sd);
    auto p = make_shared<Block>(0, 0, 0, false, 0, c);
    return p;
}

// Level2
levelTwo::levelTwo(int sd, bool set_sd) : NextBlock{ sd, set_sd } {}

shared_ptr<Block> levelTwo::generateBlock() {
    char c = setChar(prob, prob, sd, set_sd);
    auto p = make_shared<Block>(0, 0, 0, false, 0, c);
    return p;
}

void levelTwo::changeState(bool set, string s) {}

// Level3
levelThree::levelThree(int sd, bool set_sd) : NextBlock{ sd, set_sd } {}

shared_ptr<Block> levelThree::generateBlock() {
    shared_ptr<Block> p;
    if (random == true) {
        char c = setChar(probSZ, probOther, sd, set_sd);
        p = make_shared<Block>(0, 0, 0, false, 0, c);
    }
    else {
        char c2 = sequence[current];
        p = make_shared<Block>(0, 0, 0, false, 0, c2);
        ++current;
        if (current == size) {
            current = 0;
        }
    }
    return p;
}

void levelThree::changeState(bool set, string s) {
    random = set;
    if (random == false) {
        sequence.clear();
        size = 0;
        current = 0;
        ifstream infile{ s };
        char c;
        while (true) {
            infile >> c;
            if (infile.fail()) break;
            sequence.emplace_back(c);
            ++size;
        }
    }
}

// Level4
levelFour::levelFour(int sd, bool set_sd, Board* b) : NextBlock{ sd, set_sd }, b{ b } {}

shared_ptr<Block> levelFour::generateBlock() {
    ++count;
    shared_ptr<Block> p;
    if (random == true) {
        char c = setChar(probSZ, probOther, sd, set_sd);
        p = make_shared<Block>(0, 0, 0, false, 0, c);
    }
    else {
        char c2 = sequence[current];
        p = make_shared<Block>(0, 0, 0, false, 0, c2);
        ++current;
        if (current == size) {
            current = 0;
        }
    }
    if (b->block_created % 5 == 0 && b->clearRow == false) {
        b->dropStar();
    }
    return p;
}

void levelFour::changeState(bool set, string s) {
    random = set;
    if (random == false) {
        sequence.clear();
        size = 0;
        current = 0;
        ifstream infile{ s };
        char c;
        while (true) {
            infile >> c;
            if (infile.fail()) break;
            sequence.emplace_back(c);
            ++size;
        }
    }
}
