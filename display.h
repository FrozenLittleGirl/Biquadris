#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include <iostream>
#include "window.h"
#include "board.h"
#include <string>
using namespace std;

class Display {
    const int NUM_COLS = 11;
    const int NUM_ROWS = 18;
    Board *opponent;
    Board *board;
    Xwindow *xw = nullptr;
    public:
        Display(bool graphical);
        ~Display();
        void attachBoard(Board* board);
        void attachOpponent(Board* opponent);
        // void notify(Cell &whoNotified) override;
        friend std::ostream &operator<<(std::ostream &out, const Display &td);
        //void printBoards();
};

#endif
