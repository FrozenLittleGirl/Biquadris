#include "textdisplay.h"
#include "board.h"
using namespace std;
#include "SpecialActions.h"
#include "Action.h"

TextDisplay::TextDisplay() {}

TextDisplay::~TextDisplay() {
}

void TextDisplay::attachBoard(Board* board) {
    this->board = board;
}
void TextDisplay::attachOpponent(Board* opponent) {
    this->opponent = opponent;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    out << "error td.board->getLevel() ?" << endl;
    out << td.board->getLevel() << endl;
    out << "error td.board->getScore() ?" << endl;
    out << td.board->getScore() << endl;
    out << "Level:    " << td.board->getLevel() << "      " << "Level:    " << td.opponent->getLevel() << endl;
    out << "Score:    " << td.board->getScore() << "      " << "Score:    " << td.opponent->getScore() << endl;
    out << "-------------" << "    " << "-------------" << endl;
    if ( dynamic_cast<Blind*>(td.board->getAction()) ) {
        for (int i = 0; i < td.NUM_ROWS; i++) {
            cout << "-";
            for (int j = 0; j < td.NUM_COLS; j++) {
                if ( (2 <= j && j <= 8) && ( 6 <= i && i <= 15 ) ) {
                    out << '?';
                } else {
                    out << td.board->getBoard()[i][j].getName();
                }
            }
            cout << "-";
            out << "    -";
            for (int j = 0; j < td.NUM_COLS; j++) {
                out << td.opponent->getBoard()[i][j].getName();
            }  
            cout << "-";
            out << endl;
        }        
    } else if ( dynamic_cast<Blind*>(td.opponent->getAction()) ) {
        for (int i = 0; i < td.NUM_ROWS; i++) {
            cout << "-";
            for (int j = 0; j < td.NUM_COLS; j++) {
                out << td.board->getBoard()[i][j].getName();                
            }
            cout << "-";
            out << "    -";
            for (int j = 0; j < td.NUM_COLS; j++) {
                if ( (2 <= j && j <= 8) && ( 6 <= i && i <= 15 ) ) {
                    out << '?';
                } else {
                    out << td.opponent->getBoard()[i][j].getName();
                }
            }  
            cout << "-";
            out << endl;
        }
    } else {
        for (int i = 0; i < td.NUM_ROWS; i++) {
            cout << "-";
            for (int j = 0; j < td.NUM_COLS; j++) {
                out << td.board->getBoard()[i][j].getName();
            }
            cout << "-";
            out << "    -";
            for (int j = 0; j < td.NUM_COLS; j++) {
                out << td.opponent->getBoard()[i][j].getName();
            }  
            cout << "-";
            out << endl;
        }
    }
    out << "-------------" << "    " << "-------------" << endl;
    out << "Next:      " << "      " << "Next:      " << endl;
    for (int i = 2; i < 4; i++) {
        out << td.board->getNextBlock()->getRotateDefault()[i] << "             " << td.opponent->getNextBlock()->getRotateDefault()[i] << endl;
    }
    return out;
}
