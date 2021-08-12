#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "NextBlock.h"
#include <string>
#include <vector>

using namespace std;

class Board;

class levelZero : public NextBlock {
        vector<char> sequence;
        int size = 0;
        int current = 0;
public:
        levelZero(string file, int sd, bool set_sd);
        Block* generateBlock() override;

        // really does nothing
        void changeState(bool set, string s) override;
};

class levelOne : public NextBlock {
        double probSZ = 1;
        double probOther = 2;
public:
        levelOne(int sd, bool set_sd);
        Block* generateBlock() override;

        // really does nothing
        void changeState(bool set, string s) override;
};

class levelTwo : public NextBlock {
        double prob = 1;
public:
        levelTwo(int sd, bool set_sd);
        Block* generateBlock() override;

        // really does nothing
        void changeState(bool set, string s) override;
};

class levelThree : public NextBlock {
        double probSZ = 2;
        double probOther = 1;
        bool random = true;
        vector<char> sequence;
        int size = 0;
        int current = 0;
public:
        levelThree(int sd, bool set_sd);
        Block* generateBlock() override;
        void changeState(bool set, string s) override;
};

class levelFour : public NextBlock {
        double probSZ = 2;
        double probOther = 1;
        bool random = true;
        vector<char> sequence;
        int size = 0;
        int current = 0;
        Board* b;
public:
        levelFour(int sd, bool set_sd, Board* b);
        Block* generateBlock() override;
        void changeState(bool set, string s) override;
};

#endif
