#include "view.h"
#include "SpecialActions.h"
#include "Action.h"
#include "board.h"
using namespace std;


View::View(bool graphical) : graphical{graphical} {
    if (graphical) {
        xw = new Xwindow(1000, 800);
        xw->fillRectangle(0, 0, 1000, 800, Xwindow::Black);
        xw->drawString(400, 40, "Biquadris", Xwindow::White);
        xw->drawString(120, 70, "Level:", Xwindow::White);
        xw->drawString(120, 85, "Score:", Xwindow::White);
        xw->drawString(620, 70, "Level:", Xwindow::White);
        xw->drawString(620, 85, "Score:", Xwindow::White);
        xw->drawString(120, 700, "Next:", Xwindow::White);
        xw->drawString(620, 700, "Next:", Xwindow::White);
    }
}


 bool View::isGraphical() const {
     return graphical;
 }

View::~View() {
    delete xw;
}

void View::attachBoard(Board* board) {
    this->board = board;
}

void View::attachOpponent(Board* opponent) {
    this->opponent = opponent;
}


void View::coverString(int x, int y, int width, int colour) {
    if (graphical) {
        xw->fillRectangle(x, y, width, 15, colour);
    }
}


void View::fillString(int x, int y, string s, int colour) {
    if (graphical) {
        xw->drawString(x, y, s, colour);
    }
}


void View::fillCell(int x, int y, int width, int colour) {
    if (graphical) {
        xw->fillRectangle(x, y, width, width, colour);
    }
}

ostream &operator<<(ostream &out, const View &td) {
    out << "Level:    " << td.board->getLevel() << "      " << "Level:    " << td.opponent->getLevel() << endl;
    out << "Score:    " << td.board->getScore() << "      " << "Score:    " << td.opponent->getScore() << endl;
    out << "-----------" << "      " << "-----------" << endl;
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
    out << "-----------" << "      " << "-----------" << endl;
    out << "Next:      " << "      " << "Next:      " << endl;
    for (int i = 2; i < 4; i++) {
        out << td.board->getNextBlock()->getRotateDefault()[i] << "             " << td.opponent->getNextBlock()->getRotateDefault()[i] << endl;
    }
    return out;
}
