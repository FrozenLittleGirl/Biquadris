#include "board.h"


init Board::init() {
    shared_ptr<TextDisplay> td = <make_unique>();
    for (int i = 0; i < NUM_COLS; i++) {
        vector<Cell> tmp;
        // initialize each column
        for (int j = 0; j < NUM_ROWS; j++) {
            Cell cur{i, j, false, ' '};
            tmp.push_back(Cell);
        }
        // push back each row
        theBoard.push_back(tmp);
    }

}