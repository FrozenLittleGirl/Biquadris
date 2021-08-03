#include "display.h"
#include "SpecialActions.h"
#include "Action.h"
using namespace std;


Display::Display(bool graphical) : graphical{graphical}, xw{nullptr} {
    if (graphical) {
        xw = new Xwindow(1000, 800, Xwindow::Black);
        xw->fillRectangle(0, 0, 1000, 800, Xwindow::Black);
        xw->drawString(400, 40, "Biquadris", Xwindow::White);
        xw->drawString(120, 700, "Next:", Xwindow::White);
        xw->drawString(620, 700, "Next:", Xwindow::White)
    }
}

Display::~Display() {
    delete xw;
}

void Display::attachBoard(Board* board) {
    this->board = board;
}

void Display::attachOpponent(Board* opponent) {
    this->opponent = opponent;
}


void Display::coverString(int x, int y, int width, int colour) {
    if (graphical) {
        xw->fillRectangle(x, y, width, 15, colour);
    }
}


void Display::fillString(int x, int y, string s, int colour) {
    if (graphical) {
        xw->drawString(x, y, s, colour);
    }
}


void Display::fillCell(int x, int y, int width, int colour) {
    if (graphical) {
        xw->fillRectangle(x, y, width, width, colour);
    }
}


ostream &operator<<(ostream &out, const Display &d) {
    out << "Level:    " << d.board->getLevel() << "      " << "Level:    " << d.opponent->getLevel() << endl;
    out << "Score:    " << d.board->getScore() << "      " << "Score:    " << d.opponent->getScore() << endl;
    out << "-----------" << "      " << "-----------" << endl;
    if ( dynamic_cast<Blind*>(d.board->getAction()) ) {
        for (int i = 0; i < d.NUM_ROWS; i++) {
            cout << "-";
            for (int j = 0; j < d.NUM_COLS; j++) {
                if ( (2 <= j && j <= 8) && ( 6 <= i && i <= 15 ) ) {
                    out << '?';
                } else {
                    out << d.board->getBoard()[i][j].getName();
                }
            }
            cout << "-";
            out << "    -";
            for (int j = 0; j < d.NUM_COLS; j++) {
                out << d.opponent->getBoard()[i][j].getName();
            }  
            cout << "-";
            out << endl;
        }        
    } else if ( dynamic_cast<Blind*>(d.opponent->getAction()) ) {
        for (int i = 0; i < d.NUM_ROWS; i++) {
            cout << "-";
            for (int j = 0; j < d.NUM_COLS; j++) {
                out << d.board->getBoard()[i][j].getName();                
            }
            cout << "-";
            out << "    -";
            for (int j = 0; j < d.NUM_COLS; j++) {
                if ( (2 <= j && j <= 8) && ( 6 <= i && i <= 15 ) ) {
                    out << '?';
                } else {
                    out << d.opponent->getBoard()[i][j].getName();
                }
            }  
            cout << "-";
            out << endl;
        }
    } else {
        for (int i = 0; i < d.NUM_ROWS; i++) {
            cout << "-";
            for (int j = 0; j < d.NUM_COLS; j++) {
                out << d.board->getBoard()[i][j].getName();
            }
            cout << "-";
            out << "    -";
            for (int j = 0; j < d.NUM_COLS; j++) {
                out << d.opponent->getBoard()[i][j].getName();
            }  
            cout << "-";
            out << endl;
        }
    }
    out << "-----------" << "      " << "-----------" << endl;
    out << "Next:      " << "      " << "Next:      " << endl;
    for (int i = 2; i < 4; i++) {
        out << d.board->getNextBlock()->getRotateDefault()[i] << "             " << d.opponent->getNextBlock()->getRotateDefault()[i] << endl;
    }
    return out;
}
