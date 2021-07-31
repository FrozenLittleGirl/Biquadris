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
    vector<vector<Cell>> theBoard;   // Shirley: My implementation used vector<vector<Cell>> instead, is it okay that
                                         // we change it back? Since all the methods such as drop, left, right and so on used 
                                           // vector<vector<Cell>>
                                     // Nata: changed
    Board* opponent;
    TextDisplay *td;
    SpecialAction* acton = nullptr;
    NextBlock* level = nullptr;
    int level_n;
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
        
        void print();   // Nata: this is for temporarily testing

        ~Board();
};



#endif
