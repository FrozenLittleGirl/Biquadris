#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
//#include "observer.h"
#include <iostream>

class Board;

class TextDisplay {
    const int NUM_COLS = 11;
    const int NUM_ROWS = 18;
    Board *opponent;
    Board *board;
    //notifyNextBlock(*block next);
    //std::vector<std::vector<char>> theGame;
    //*Block nextBlock;

    public:
        TextDisplay();
        void attachBoard(Board* board);
        void attachOpponent(Board* opponent);
        *Block getBoard();
        *Block getOpponent();
        // void notify(Cell &whoNotified) override;
         friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
        //void printBoards();

        ~TextDisplay();
};

#endif
