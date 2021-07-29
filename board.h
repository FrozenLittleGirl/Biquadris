#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include <memory>
#include <iostream>

class Board {
    vector<vector<shared_ptr<Cell>>> theBoard;
    bool won;
    TextDisplay *td;
    int level;
    int score;
    
    public: 
        friend &ostream operator<<(std::ostream &out, Board &b);
        void init();
        void clearBoard();
};



#endif