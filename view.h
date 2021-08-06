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
    bool graphical;
    Xwindow *xw = nullptr;

    public:
        View(bool graphical);
        ~View();
        void attachBoard(Board* board);
        void attachOpponent(Board* opponent);
        void coverString(int x, int y, int width, int colour);
        void fillString(int x, int y, string s, int colour);
        void fillCell(int x, int y, int width, int colour);
        bool isGraphical() const;
};

#endif
