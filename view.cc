#include "view.h"
#include "SpecialActions.h"
#include "Action.h"
#include "board.h"
using namespace std;


View::View(bool graphical) : graphical{graphical}, xw{nullptr} {
    if (graphical) {
        xw = new Xwindow(1000, 750);
        xw->fillRectangle(0, 0, 1000, 750, Xwindow::White);
        xw->drawString(400, 40, "Biquadris", Xwindow::Black);
        xw->drawString(120, 70, "Level:", Xwindow::Black);
        xw->drawString(120, 85, "Score:", Xwindow::Black);
        xw->drawString(600, 70, "Level:", Xwindow::Black);
        xw->drawString(600, 85, "Score:", Xwindow::Black);
        xw->drawString(120, 650, "Next:", Xwindow::Black);
        xw->drawString(600, 650, "Next:", Xwindow::Black);
    }
}

View::~View() {
    delete xw;
}

 bool View::isGraphical() const {
     return graphical;
 }


void View::attachBoard(Board* board) {
    this->board = board;
}

void View::attachOpponent(Board* opponent) {
    this->opponent = opponent;
}


void View::coverString(int x, int y, int width, int colour) {
    if (graphical) {
        xw->fillRectangle(x, y, width, width, colour);
    }
}


void View::fillString(int x, int y, string s, int colour) {
    if (graphical) {
        xw->drawString(x, y, s, colour);
    }
}


void View::fillCell(int x, int y, int width, int colour) {
    cout << "x: " << x << "y: " << y << "width: " << width << endl;
    if (graphical) {
        xw->fillRectangle(x, y, width, width, colour);
    }
}
