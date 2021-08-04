#ifndef _VIEW_H_
#define _VIEW_H_
#include <iostream>
#include "window.h"
#include <string>
using namespace std;

class Board;

class View {
    const int NUM_COLS = 11;
    const int NUM_ROWS = 18;
    Board *opponent;
    Board *board;
    Xwindow *xw = nullptr;
    public:
        View(bool graphical);
        ~View();
        void attachBoard(Board* board);
        void attachOpponent(Board* opponent);
        friend std::ostream &operator<<(std::ostream &out, const View &td);
        //void printBoards();
};

#endif
