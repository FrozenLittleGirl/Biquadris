#include "textdisplay.h"
#include "board.h"
using namespace std;

TextDisplay::TextDisplay() {}

void TextDisplay::attachBoard(Board* board) {
    this->board = board;
}
void TextDisplay::attachOpponent(Board* opponent) {
    this->opponent = opponent;
}

*Board TextDisplay::getBoard() {
    return board;
}

*Board TextDisplay::getOpponent() {
    return opponent;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    out << "Level:    " << td.getBoard()->getLevel() << "      " << "Level:    " << td.getOpponent()->getLevel() << endl;
    out << "Score:    " << td.getBoard()->getScore() << "      " << "Score:    " << td.getOpponent()->getScore() << endl;
    out << "-----------" << "      " << "-----------" << endl;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            out << td.getBoard()->getBoard()[i][j].getName();
        }
        out << "      ";
        for (int j = 0; j < NUM_COLS; j++) {
            out << td.getOpponent()->getBoard()[i][j].getName();
        }
        out << endl;
    }
    out << "-----------" << "      " << "-----------" << endl;
    out << "Next:      " << "      " << "Next:      " << endl;
    for (int i = 0; i < 5; i++) {
        out << td.getBoard()->getNextBlock()->getRotateDefault()[i] << "            " << td.getOpponent()->getNextBlock()->getRotateDefault()[i] << endl;
    }
    return out;
}
