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
<<<<<<< HEAD
        *Board getBoard() const;
        *Board getOpponent() const;
=======
        Board* getBoard();
        Board* getOpponent();
>>>>>>> 08394ccfa4ec569e0665f64d3d0c5e80b8b7c932
        // void notify(Cell &whoNotified) override;
        friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
        //void printBoards();

        ~TextDisplay();
};

#endif
