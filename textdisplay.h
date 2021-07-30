#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include "observer.h"

class Cell;

class TextDisplay, public Observer {
    const int NUM_COLS = 11;
    size_t level;
    size_t score;

    std::vector<std::vector<char>> theGame;
    std::vector<std::vector<char>> curLevel;
    std::vector<std::vector<char>> curScore;
    std::vector<std::vector<char>> nextBlock;
    
    public:
        TextDisplay();
        void notify(Cell &whoNotified) override;
        friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
        ~TextDisplay();
};