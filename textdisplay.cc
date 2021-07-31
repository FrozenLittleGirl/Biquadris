#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay() {}

void TextDisplay::attachBoard(Board* board) {
    this->board = board;
}
void TextDisplay::attachOpponent(Board* opponent) {
    this->opponent = opponent;
}

void printBoards() {
    cout << "Level:    " << board->level << "      " << "Level:    " << opponent->level << endl;
    cout << "Score:    " << board->score << "      " << "Score:    " << opponent->score << endl;
    cout << "-----------" << "      " << "-----------" << endl;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            cout << board->getBoard[i][j].getName();  
        }
        cout << "      ";
        for (int j = 0; j < NUM_COLS; j++) {
            cout << opponent->getBoard[i][j].getName();
        }
        cout << endl;
    }
    cout << "-----------" << "      " << "-----------" << endl;
    cout << "Next:      " << "      " << "Next:      " << endl;
    for (int i = 0; i < 5; i++) {
        cout << nextBlock->getRotateDefault()[i] << "            " << opponent->nextBlock->getRotateDefault()[i]; << endl;
    }
}