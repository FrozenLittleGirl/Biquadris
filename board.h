#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include <memory>
#include <iostream>
//#include "subject.cc"
#include "block.h"
#include "cell.h"
using namespace std;

class TextDisplay;
class SpecialAction;
class NextBlock;

class Board {
    const int NUM_COLS = 11;
    const int NUM_ROWS = 18;
    vector<vector<Cell>> theBoard;
    Board* opponent = nullptr;
    TextDisplay *td = nullptr;
    SpecialAction* action = nullptr;
    NextBlock* level = nullptr;
    int level_n;
    Block* currentBlock = nullptr;  // Nata: change the name from block to currentBlock
    Block* nextBlock = nullptr;
    void move(int angle, int x, int y);
    bool isShiftValid(int angle, int x, int y);
    void detectRow();
    int* turn;

    int block_created = 0;
    bool clearRow = false;
    void dropStar();

    protected:
    int score = 0;
    int tmp_score = 0;          // Nata: since there are restart, we need a temporarily score to hold current game's score
    bool lose = false;
    //void restore();
    void addAction(Board* opponent, string s);

    public:
        Board();
        friend ostream &operator<<(ostream &out, const Board &b);
        void init();
        void clearBoard();

        void drop();
        void down(int steps);
        void left(int steps);
        void right(int steps);
        void clockwise(int angle);
        void counterclockwise(int angle);
        bool determineLose();
        bool canBeDropped();
        //void setLoseOrWin(bool);  // Nata: I have a determineLose above
        int determineScore();
        void attach(Board* opponent, int* n);
        void setRandom(bool set, string s);
        void addLevel(int n, int seed, bool set_seed, string file);
        void newBlock(char c = 'n');
        Block* getNextBlock() const;
        int getLevel() const;
        int getScore() const;
        Block *getCurrentBlock();
        void setCurrentBlock();
        SpecialAction* getAction() const;
        vector<vector<Cell>> getBoard() const;
        void print();   // Nata: this is for temporarily testing

        ~Board();
};

#endif
