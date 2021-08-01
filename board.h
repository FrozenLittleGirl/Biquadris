#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include <memory>
#include <iostream>
#include "subject.cc"
#include "Block.h"
#include "Cell.h"
using namespace std;

class TextDisplay;
class SpecialAction;
class NextBlock;

class Board, public Subject {
    const int NUM_COLS = 11;
    const int NUM_ROWS = 18;
    vector<vector<Cell>> theBoard;
    Board* opponent;
    TextDisplay *td;
    SpecialAction* acton = nullptr;
    NextBlock* level = nullptr;
    int level_n;
    shared_ptr<Block> currentBlock;  // Nata: change the name from block to currentBlock
    shared_ptr<Block> nextBlock;
    
    protected:
    int score = 0;
    int tmp_score = 0;          // Nata: since there are restart, we need a temporarily score to hold current game's score
    int block_created = 0;
    bool clearRow = false;
    bool lose = false;
    //void restore();
    void addAction(Board* opponent, string s);
    void dropStar();

    public: 
        friend ostream &operator<<(ostream &out, const Board &b);
        void init();
        void clearBoard();

        void drop();
        void left(int steps);
        void right(int steps);
        void clockwise(int angle);
        void counterclockwise(int angle);
        bool determineLose();
        //void setLoseOrWin(bool);  // Nata: I have a determineLose above
        int determineScore();    
        void attach(Board* opponent, int* n);
        void setRandom(bool set, string s);
        void addLevel(int n, int seed, bool set_seed, string file);
        void newBlock(char c = 'n');
        vector<vector<Cell>> getBoard();
        void print();   // Nata: this is for temporarily testing

        ~Board();
};

#endif
