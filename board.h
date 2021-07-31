#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include <memory>
#include <iostream>
#include "Block.h"

class TextDisplay;
class SpecialAction;
class NextBlock;

class Board {
    Block *currentBlock;
    Block *nextBlock;
    vector<vector<shared_ptr<Cell>>> theBoard;
    Board* opponent;
    TextDisplay *td;
    SpecialAction* acton = nullptr;
    NextBlock* level = nullptr;
    size_t level_n;
    shared_ptr<Block> block;
    
    protected:
    int score;
    bool lose = false;
    void restore();
    void addAction(Board* opponent, string s);

    public: 
        friend &ostream operator<<(std::ostream &out, Board &b);
        void init();
        void clearBoard();

        void drop();
        void left();
        void right();
        void clockwise();
        void counterclockwise();
        bool determineLose();
        void setLoseOrWin(bool);
        int determineScore();
        void attach(Board* opponent, int* n);
        void setRandom(bool set, string s);
        void addLevel(int n, int seed, bool set_seed, string file);
        void newBlock(char c = 'n');
        

        ~Board();
};



#endif
