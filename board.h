#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include <memory>
#include <iostream>

class Board {
    vector<vector<shared_ptr<Cell>>> theBoard;
    bool won;
    Board* opponent;
    TextDisplay *td;
    SpecialAction* acton = nullptr;
    NextBlock* level = nullptr;
    shared_ptr<Block> block;
    int score;
    
    public: 
        friend &ostream operator<<(std::ostream &out, Board &b);
        void init();
        void clearBoard();
};



#endif
