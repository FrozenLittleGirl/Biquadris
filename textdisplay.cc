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

ostream &operator<<(ostream &out, const TextDisplay &td) {
    out << "Level:    " << td.board->level << "      " << "Level:    " << td.opponent->level << endl;
    out << "Score:    " << td.board->score << "      " << "Score:    " << td.opponent->score << endl;
    out << "-----------" << "      " << "-----------" << endl;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            out << td.board->getBoard[i][j].getName();
        }
        out << "      ";
        for (int j = 0; j < NUM_COLS; j++) {
            out << td.opponent->getBoard[i][j].getName();
        }
        out << endl;
    }
    out << "-----------" << "      " << "-----------" << endl;
    out << "Next:      " << "      " << "Next:      " << endl;
    for (int i = 0; i < 5; i++) {
        out << td.board->nextBlock->getRotateDefault()[i] << "            " << td.opponent->nextBlock->getRotateDefault()[i]; << endl;
    }
    return out;
}
