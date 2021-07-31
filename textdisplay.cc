#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay() {
    // initialize level and score headers
    for (int i = 0; i < NUM_COLS; i++) {
        std::vector<char> tmp;
        for (int j = 0; j < 2; j++) {

        }
    }
}

void printNextBlock() {
    if (nextBlock == 'I') {
        cout << "          " <<
        cout << "IIII      " <<
    }
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    cout << "Level:    " << td.level << "      " << "Level:    " << opponent->score << endl;
    cout << "Score:    " << td.level << "      " << "Score:    " << opponent->score << endl;
    cout << "-----------" << "      " << "-----------" << endl;

    //
    //
    //
    //

    cout << "-----------" << "      " << "-----------" << endl;
    cout << "Next: "
    return out;
}