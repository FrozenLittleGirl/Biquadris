#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "NextBlock.h"
#include <string>
#include <vector>

class Board;

class levelZero : public NextBlock {
        std::vector<char> sequence;
        int size = 0;
        int current = 0;
public:
        levelZero(std::string file, int sd, bool set_sd);
        Block* generateBlock() override;

        // really does nothing
        void changeState(bool set, std::string s) override;
};

class levelOne : public NextBlock {
        double probSZ = 1;
        double probOther = 2;
public:
        levelOne(int sd, bool set_sd);
        Block* generateBlock() override;

        // really does nothing
        void changeState(bool set, std::string s) override;
};

class levelTwo : public NextBlock {
        double prob = 1;
public:
        levelTwo(int sd, bool set_sd);
        Block* generateBlock() override;

        // really does nothing
        void changeState(bool set, std::string s) override;
};

class levelThree : public NextBlock {
        double probSZ = 2;
        double probOther = 1;
        bool random = true;
        std::vector<char> sequence;
        int size = 0;
        int current = 0;
public:
        levelThree(int sd, bool set_sd);
        Block* generateBlock() override;
        void changeState(bool set, std::string s) override;
};

class levelFour : public NextBlock {
        double probSZ = 2;
        double probOther = 1;
        bool random = true;
        std::vector<char> sequence;
        int size = 0;
        int current = 0;
        Board* b;
public:
        levelFour(int sd, bool set_sd, Board* b);
        Block* generateBlock() override;
        void changeState(bool set, std::string s) override;
};

#endif
