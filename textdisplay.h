#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include "observer.h"
#include "Nec"

class Board;

class TextDisplay, public Observer {
    const int NUM_COLS = 11;
    size_t level;
    size_t score;
    Board *opponent;

    std::vector<std::vector<char>> theGame;
    char nextBlock;

    void attachOpponent(TextDisplay* td);
    
    public:
        TextDisplay();
        void notify(Cell &whoNotified) override;
        friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
        ~TextDisplay();
};