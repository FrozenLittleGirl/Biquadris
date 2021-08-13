#include "SpecialActions.h"
#include "board.h"
#include "level.h"
#include "NextBlock.h"
#include "Action.h"
#include "view.h"
#include "textdisplay.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "starblock.h"
#include <vector>
#include <string>

using namespace std;


Board::Board(int x, int y, View *v) :
    x{x},
    y{y},
    view{v},
    graphicx{x},
    graphicy{y} {
        td = new TextDisplay;
        td->attachBoard(this);
    }

void Board::clearBoard() {
    if (tmp_score > score) {
        score = tmp_score;
    }
    tmp_score = 0;
    delete action;
    action = nullptr;
    block_created = 0;
    clearRow = false;
    lose = false;
    theBoard.clear();
}

void Board::init() {
    clearBoard();
    displayScore();
    displayLevel();
    for (int i = 0; i < NUM_ROWS; i++) {
        vector<Cell> tmp;
        // initialize each column
        for (int j = 0; j < NUM_COLS; j++) {
            Cell cur{i, j, false, ' '};
            tmp.push_back(cur);
        }
        // push back each row
        theBoard.push_back(tmp);
    }

    int cell_x = 0;
    int cell_y = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
        cell_y += 2;
        for (int j = 0; j < NUM_COLS; j++) {
            cell_x += 2;
            theBoard[i][j].setDisplay(view);
            theBoard[i][j].setColour();
            theBoard[i][j].setGraphics(cell_x, cell_y);
            cell_x -= 2;
            cell_x += 30;
        }
        cell_x = 0;
        cell_y -= 2;
        cell_y += 30;
    }

    delete currentBlock;
    delete nextBlock;
    currentBlock = level->generateBlock();
    nextBlock = level->generateBlock();
    displayBoard();
    setNextBlockGraphics();
    displayNextBlock(nextBlock->getName());
}

void Board::setNextBlockGraphics() {
    // set vector<Cell> for NextBlock to display graphics
    for (int i = 0; i < 2; i++) {
        vector<Cell> tmp;
        for (int j = 0; j < 4; j++) {
            Cell cur{i, j, false, 'N'};
            tmp.push_back(cur);
        }
        nextBlockGrid.push_back(tmp);
    }
    int cell_x = 0;
    int cell_y = 0;
    for (int i = 0; i < 2; i++) {
        cell_y += 2;
        for (int j = 0; j < 4; j++) {
            cell_x += 2;
            nextBlockGrid[i][j].setDisplay(view);
            nextBlockGrid[i][j].setColour();
            nextBlockGrid[i][j].setGraphics(cell_x + 230, cell_y + 550);
            cell_x -= 2;
            cell_x += 30;
        }
        cell_x = 0;
        cell_y -= 2;
        cell_y += 30;
    }
}


void Board::displayNextBlock(char type) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            nextBlockGrid[i][j].setName('N');
        }
    }
    if (type == 'I') {
        nextBlockGrid[1][0].setName('I');
        nextBlockGrid[1][1].setName('I');
        nextBlockGrid[1][2].setName('I');
        nextBlockGrid[1][3].setName('I');
    }
    if (type == 'J') {
        nextBlockGrid[0][0].setName('J');
        nextBlockGrid[1][0].setName('J');
        nextBlockGrid[1][1].setName('J');
        nextBlockGrid[1][2].setName('J');
    }
    if (type == 'L') {
        nextBlockGrid[0][2].setName('L');
        nextBlockGrid[1][0].setName('L');
        nextBlockGrid[1][1].setName('L');
        nextBlockGrid[1][2].setName('L');
    }
    if (type == 'O') {
        nextBlockGrid[0][0].setName('O');
        nextBlockGrid[0][1].setName('O');
        nextBlockGrid[1][0].setName('O');
        nextBlockGrid[1][1].setName('O');
    }
    if (type == 'S') {
        nextBlockGrid[0][1].setName('S');
        nextBlockGrid[0][2].setName('S');
        nextBlockGrid[1][0].setName('S');
        nextBlockGrid[1][1].setName('S');
    }
    if (type == 'Z') {
        nextBlockGrid[0][0].setName('Z');
        nextBlockGrid[0][1].setName('Z');
        nextBlockGrid[1][1].setName('Z');
        nextBlockGrid[1][2].setName('Z');
    }
    if (type == 'T') {
        nextBlockGrid[0][0].setName('T');
        nextBlockGrid[0][1].setName('T');
        nextBlockGrid[0][2].setName('T');
        nextBlockGrid[1][1].setName('T');
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            nextBlockGrid[i][j].setColour();
            displayCell(i, j, nextBlockGrid);
        }
    }
}

bool Board::isShiftValid(int angle, int x, int y) {
    if (angle != 0 || x != 0 || y != 0) {
        int rotateAngle = currentBlock->getAngle() + angle;
        rotateAngle = rotateAngle % 360;
        if (rotateAngle < 0) {
            rotateAngle += 360;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                char currentChar = ' ';
                if (rotateAngle == 0) {
                    currentChar = currentBlock->getRotateDefault()[i][j];
                } else if (rotateAngle == 90) {
                    currentChar = currentBlock->getRotate90()[i][j];
                } else if (rotateAngle == 180) {
                    currentChar = currentBlock->getRotate180()[i][j];
                } else if (rotateAngle == 270) {
                    currentChar = currentBlock->getRotate270()[i][j];
                }
                if (currentChar != ' ') {
                    int currentAngle = currentBlock->getAngle();
                    int blockX = currentBlock->getXcoord();
                    int blockY = currentBlock->getYcoord();
                    int currentX = currentBlock->getXcoord() + x;
                    int currentY = currentBlock->getYcoord() + y;
                    if (currentX + j < 0 || currentY + i < 0 || currentX + j > 10 || currentY + i > 17) {
                        return false;
                    }
                    if (theBoard[currentY + i][currentX + j].isOccupied() == true) {
                        if (currentX + j < blockX || currentY + i < blockY ||
                        currentX + j > blockX + 3 || currentY + i > blockY + 3) {
                            return false;
                        }
                        if (currentAngle == 0) {
                            if (currentBlock->getRotateDefault()[y + i][x + j] == ' ') {
                                return false;
                            }
                        } else if (currentAngle == 90) {
                            if (currentBlock->getRotate90()[y + i][x + j] == ' ') {
                                return false;

                            }

                        } else if (currentAngle == 180) {
                            if (currentBlock->getRotate180()[y + i][x + j] == ' ') {
                                return false;

                            }

                        } else if (currentAngle == 270) {
                            if (currentBlock->getRotate270()[y + i][x + j] == ' ') {
                                return false;

                            }

                        }

                    }

                }

            }
        }
    } else {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int currentAngle = currentBlock->getAngle();
                int blockX = currentBlock->getXcoord();
                int blockY = currentBlock->getYcoord();
                char currentChar = ' ';
                if (currentAngle == 0) {
                    currentChar = currentBlock->getRotateDefault()[i][j];
                } else if (currentAngle == 90) {
                    currentChar = currentBlock->getRotate90()[i][j];
                } else if (currentAngle == 180) {
                    currentChar = currentBlock->getRotate180()[i][j];
                } else if (currentAngle == 270) {
                    currentChar = currentBlock->getRotate270()[i][j];
                }
                if (currentChar != ' ') {
                    if (theBoard[blockY + i][blockX + j].isOccupied() == true) {
                        return false;
                    }
                    if (blockX + j < 0 || blockY + i < 0 ||
                    blockX + j > 10 || blockY + i > 17) {
                        return false;

                    }
                }
            }
        }
    }
    return true;
}


void Board::move(int angle, int x, int y) {
    int currentAngle = currentBlock->getAngle();
    vector<string> currentRotation;
    if (currentAngle == 0) {
        currentRotation = currentBlock->getRotateDefault();
    } else if (currentAngle == 90) {
        currentRotation = currentBlock->getRotate90();
    } else if (currentAngle == 180) {
        currentRotation = currentBlock->getRotate180();
    } else if (currentAngle == 270) {
        currentRotation = currentBlock->getRotate270();
    }
    int currentX = currentBlock->getXcoord();
    int currentY = currentBlock->getYcoord();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (currentRotation[i][j] != ' ' && currentY + i < 18 && currentX + j < 11) {
                theBoard[currentY + i][currentX + j].clearCell();
                theBoard[currentY + i][currentX + j].setColour();
            }
            if (currentY + i < 18 && currentX + j < 11) {
                theBoard[currentY + i][currentX + j].setColour();
                theBoard[currentY + i][currentX + j].setDisplay(view);
                displayCell(currentY + i, currentX + j, theBoard);
            }
        }
    }
    int rotateAngle = currentAngle + angle;
    rotateAngle = rotateAngle % 360;
    if (rotateAngle < 0) {
        rotateAngle += 360;
    }
    vector<string> rotation;
    if (rotateAngle == 0) {
        rotation = currentBlock->getRotateDefault();
    } else if (rotateAngle == 90) {
        rotation = currentBlock->getRotate90();
    } else if (rotateAngle == 180) {
        rotation = currentBlock->getRotate180();
    } else if (rotateAngle == 270) {
        rotation = currentBlock->getRotate270();
    }
    currentBlock->setXcoord(currentX + x);
    currentBlock->setYcoord(currentY + y);
    currentBlock->setAngle(rotateAngle);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (rotation[i][j] != ' ' && currentY + y + i < 18 && currentX + x + j < 11) {
                theBoard[currentY + y + i][currentX + x + j].setLevel(level_n);
                theBoard[currentY + y + i][currentX + x + j].setName(rotation[i][j]);
                theBoard[currentY + y + i][currentX + x + j].setColour();
            }
            if (currentY + y + i < 18 && currentX + x + j < 11) {
                theBoard[currentY + y + i][currentX + x + j].setColour();
                theBoard[currentY + y + i][currentX + x + j].setDisplay(view);
                displayCell(currentY + y + i, currentX + x + j, theBoard);
            }
        }
    }
}

void Board::left(int steps) {
    for (int i = 0; i < steps; i++) {
        if (isShiftValid(0, -1, 0) == false) {
            break;
        } else {
            move(0, -1, 0);
        }
    }
    if (level_n >= 3 && isShiftValid(0, 0, 1) == true) {
        move(0, 0, 1);
    }
    if (action != nullptr) {
        Heavy * h = dynamic_cast<Heavy *>(action);
        if (h != nullptr) {
            for (int i = 0; i < 2; ++i) {
                if (isShiftValid(0, 0, 1) == false) {
                   drop();
                   break;
                } else {
                   move(0, 0, 1);
                }
            }
        }
    }
}



void Board::right(int steps) {
    for (int i = 0; i < steps; i++) {
        if (isShiftValid(0, 1, 0) == false) {
            break;
        } else {
            move(0, 1, 0);
        }
    }
    if (level_n >= 3 && isShiftValid(0, 0, 1) == true) {
        move(0, 0, 1);
    }
    if (action != nullptr) {
        Heavy * h = dynamic_cast<Heavy *>(action);
        if (h != nullptr) {
            for (int i = 0; i < 2; ++i) {
                if (isShiftValid(0, 0, 1) == false) {
                   drop();
                   break;
                } else {
                   move(0, 0, 1);
                }
            }
        }
    }
}


void Board::down(int steps) {
    for (int i = 0; i < steps; i++) {
        if (isShiftValid(0, 0, 1) == false) {
            break;
        } else {
            move(0, 0, 1);
        }
    }
    if (level_n >= 3 && isShiftValid(0, 0, 1) == true) {
        move(0, 0, 1);
    }
}


void Board::drop() {
    while (isShiftValid(0, 0, 1) == true) {
        move(0, 0, 1);
    }
    ++block_created;
    newBlock();
    delete action;
    action = nullptr;
    *turn += 1;
    detectRow();
}

void Board::clockwise(int angle) {
    if (isShiftValid(angle, 0, 0) == true) {
        move(angle, 0, 0);
    }
    if (level_n >= 3 && isShiftValid(0, 0, 1) == true) {
        move(0, 0, 1);
    }
}


void Board::counterclockwise(int angle) {
    if (isShiftValid(-1 * angle, 0, 0) == true) {
        move(-1 * angle, 0, 0);
    }
    if (level_n >= 3 && isShiftValid(0, 0, 1) == true) {
        move(0, 0, 1);
    }
}

// for level
void Board::addLevel(int n, int seed, bool set_seed, string file) {
    delete level;
    block_created = 0;
    level_n = n;
    displayLevel();
    if (n == 0) {
            level = new levelZero{ file, seed, set_seed };
    }
    else if (n == 1) {
            level = new levelOne{ seed, set_seed };
    }
    else if (n == 2) {
            level = new levelTwo{ seed, set_seed };
    }
    else if (n == 3) {
            level = new levelThree{ seed, set_seed };
    }
    else {
            level = new levelFour{ seed, set_seed, this };
    }
}

// This is a  helper function which returns the specific block
Block* helperBlock(int x, int y, char c) {
  Block * block;
  if (c == 'L') {
    block = new Lblock{x, y, 0, false, 0, 'L'};
  } else if (c == 'I') {
      block = new Iblock{x, y, 0, false, 0, 'I'};
  }
   else if (c == 'J') {
      block = new Jblock{x, y, 0, false, 0, 'J'};
  }
   else if (c == 'O') {
      block = new Oblock{x, y, 0, false, 0, 'O'};
  }
   else if (c == 'S') {
      block = new Sblock{x, y, 0, false, 0, 'S'};
  }
   else if (c == 'Z') {
      block = new Zblock{x, y, 0, false, 0, 'Z'};
  }
   else if (c == 'T') {
      block = new Tblock{x, y, 0, false, 0, 'T'};
  }
   else {
      block = new starblock{x, y, 0, false, 0, '*'};
  }
  return block;
}

// This is a helper function which determines if all block of the same type are cleared
bool helperCheck(bool exist, char c, vector<vector<Cell>> & v) {
    if (exist == false) {
        return false;
    }
    bool disappear = true;
    if (c == '*') {
        for (int row = 3; row < 18; ++row) {
            if (v[row][5].getName() == '*') {
                return false;
            }
        }
        return true;
    }
    for (int row = 3; row < 18; ++row) {
        if (disappear == false) {
            break;
        }
        for (int col = 0; col < 11; ++col) {
            char type = v[row][col].getName();
            if (type != ' ' && type == c) {
                disappear = false;
                break;
            }
        }
    }
    return disappear;
}

// for block
void Board::newBlock(char c) {
    if (c == 'n') {
        delete currentBlock;
        currentBlock = nextBlock;
        nextBlock = level->generateBlock();
        displayNextBlock(nextBlock->getName());
    }
    else {
        int x = currentBlock->getXcoord();
        int y = currentBlock->getYcoord();
        delete currentBlock;
        currentBlock = helperBlock(x, y, c);
    }

    Iblock * iblock = dynamic_cast<Iblock*>(currentBlock);
    if (iblock != nullptr) {
        if (isShiftValid(0,0,0) == false) {
            lose = true;
        }
    } else {
        if (isShiftValid(0,0,1) == false) {
            lose = true;
        }
    }

    levelFour* four = dynamic_cast<levelFour*>(level);
    if (four != nullptr) {
        if (block_created % 5 == 0 && block_created != 0 && clearRow == false) {
            dropStar();
         } else if (block_created % 5 == 0) {
            clearRow = false;
         }
    }
}


// to attach the opponent to the textdisplay, so we can print both boards
void Board::attach(Board* opponent, int* n) {
        this->opponent = opponent;
        turn = n;
        td->attachOpponent(opponent);
}

void Board::addAction(Board* opponent, string s) {
    delete opponent->action;
        cout << "choose an action" << endl;
        string in;
        cin >> in;
        if (in == "blind") {
                opponent->action = new Blind;
                opponent->action->applyAction();
                displayBoard();
        }
        else if (in == "heavy") {
                opponent->action = new Heavy;
        }
        else {
                char c;
                cin >> c;
                opponent->action = new Force;
                Block *current = opponent->currentBlock;
                Block *forcedBlock = nullptr;
                if (c != 'O' && c != 'L' && c != 'J' && c != 'S' && c != 'I'
                && c != 'Z' && c != 'T') {
                    return;
                }
                forcedBlock = helperBlock(0, 0, c);

                int currentAngle = current->getAngle();
                vector<string> currentRotation;
                if (currentAngle == 0) {
                    currentRotation = currentBlock->getRotateDefault();

                } else if (currentAngle == 90) {
                    currentRotation = currentBlock->getRotate90();

                } else if (currentAngle == 180) {
                    currentRotation = currentBlock->getRotate180();

                } else if (currentAngle == 270) {
                    currentRotation = currentBlock->getRotate270();

                }
                int currentX = current->getXcoord();
                int currentY = current->getYcoord();
                forcedBlock->setXcoord(currentX);
                forcedBlock->setYcoord(currentY);
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (currentRotation[i][j] != ' ') {
                            opponent->getBoard()[currentY + i][currentX + j].clearCell();

                        }

                    }
                }
                opponent->currentBlock = forcedBlock;
                if (opponent->isShiftValid(0, 0, 0) == false) {
                    opponent->currentBlock = current;
                    opponent->lose = true;
                    delete forcedBlock;
                } else {
                    delete current;
                }
        }
}


void Board::dropStar() {
    Block* tmp = currentBlock;
    currentBlock = helperBlock(5, 0, '*');
    if (isShiftValid(0, 0, 0) == false) {
        lose = true;
        return;
    }
    while (isShiftValid(0, 0, 1) == true) {
        move(0, 0, 1);
    }
    delete currentBlock;
    detectRow();
    currentBlock = tmp;
}

void Board::displayScore() {
    view->coverString(x + 47, y + 5, 12, Xwindow::White);
    view->fillString(x + 50, y + 15, to_string(tmp_score), Xwindow::Black);
}

void Board::displayLevel() {
    view->coverString(x + 47, y - 10, 12, Xwindow::White);
    view->fillString(x + 50, y, to_string(level_n), Xwindow::Black);
}


void Board::detectRow() {
    int count = 0;
    bool I = false;
    bool J = false;
    bool L = false;
    bool O = false;
    bool S = false;
    bool Z = false;
    bool T = false;
    bool Star = false;
    bool determineClear = false;
    int startRow;
    int I_level, J_level, L_level, O_level, S_level, Z_level, T_level, Star_level;
    for (int row = 17; row >= 3; --row) {
        for (int col = 0; col < 11; ++col) {
            if (theBoard[row][col].getName() == ' ') {
                break;
            }
            if (col == 10) {
                if (determineClear == false) {
                    determineClear = true;
                    startRow = row;
                }
                for (int k = 0; k < 11; ++k) {
                    char type = theBoard[row][k].getName();
                    int current_level = theBoard[row][k].getLevel();
                    if (type == 'I') {
                        I = true;
                        I_level = current_level;
                    }
                    else if (type == 'J') {
                        J = true;
                        J_level = current_level;
                    }
                    else if (type == 'L') {
                        L = true;
                        L_level = current_level;
                    }
                    else if (type == 'O') {
                        O = true;
                        O_level = current_level;
                    }
                    else if (type == 'S') {
                        S = true;
                        S_level = current_level;
                    }
                    else if (type == 'Z') {
                        Z = true;
                        Z_level = current_level;
                    }
                    else if (type == 'T') {
                        T = true;
                        T_level = current_level;
                    }
                    else {
                        Star = true;
                        Star_level = 4;
                    }
                }
                for (int i = row - 1; i >= 3; --i) {
                    for (int j = 0; j < 11; ++j) {
                        bool occupied = theBoard[i][j].getOccupied();
                        char name = theBoard[i][j].getName();
                        theBoard[i + 1][j].setOccupied(occupied);
                        theBoard[i + 1][j].setName(name);
                        theBoard[i + 1][j].setColour();
                    }
                }
                for (int j = 0; j < 11; ++j) {
                    theBoard[3][j].clearCell();
                    theBoard[3][j].setColour();
                }
                ++row;
                ++count;
            }
        }
    }
    if (count > 0) {
        clearRow = true;
        tmp_score += (level_n + count) * (level_n + count);
        if (helperCheck(I, 'I', theBoard)) {
            tmp_score += (I_level + 1) * (I_level + 1);
        }
        if (helperCheck(J, 'J', theBoard)) {
            tmp_score += (J_level + 1) * (J_level + 1);
        }
        if (helperCheck(L, 'L', theBoard)) {
            tmp_score += (L_level + 1) * (L_level + 1);
        }
        if (helperCheck(O, 'O', theBoard)) {
            tmp_score += (O_level + 1) * (O_level + 1);
        }
        if (helperCheck(S, 'S', theBoard)) {
            tmp_score += (S_level + 1) * (S_level + 1);
        }
        if (helperCheck(Z, 'Z', theBoard)) {
            tmp_score += (Z_level + 1) * (Z_level + 1);
        }
        if (helperCheck(T, 'T', theBoard)) {
            tmp_score += (T_level + 1) * (T_level + 1);
        }
        if (helperCheck(Star, '*', theBoard)) {
            tmp_score += (Star_level + 1) * (Star_level + 1);
        }
        if (tmp_score > score) {
            score = tmp_score;
        }
    }

    if (determineClear) {

    }

    displayScore();

    if (count > 1) {
        addAction(opponent, " ");
    }
}


void Board::displayCell(int r, int c, vector<vector<Cell>> grid) {
    if ( dynamic_cast<Blind*>(action) ) {
        grid[r][c].display(x - 5, y + 22, true);
    } else {
        grid[r][c].display(x - 5, y + 22, false);
    }
}


void Board::displayBoard() {
    if (!view->isGraphical()) {
        return;
    }

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if ( dynamic_cast<Blind*>(action) ) {
                theBoard[i][j].display(x - 5, y + 22, true);
            } else {
                theBoard[i][j].display(x - 5, y + 22, false);
            }
        }
    }
}

void Board::setRandom(bool set, string s) {
    level->changeState(set, s);
}

bool Board::determineLose() {
    return lose;
}

int Board::determineScore() {
    return score;
}

int Board::getScore() const {
    return tmp_score;
}

SpecialAction* Board::getAction() const {
    return action;
}


vector<vector<Cell>> Board::getBoard() const {
    return theBoard;
}

Block* Board::getNextBlock() const {
    return nextBlock;
}

int Board::getLevel() const {
    return level_n;
}

void Board::setCurrentBlock(Block * newBlock) {
    this->currentBlock = newBlock;
}

int Board::currentLevel() {
    return level_n;
}

ostream &operator<<(ostream &out, const Board &b) {
    out << *(b.td) << endl;
    return out;
}

// Destructor
Board::~Board() {
    delete level;
    delete action;
    delete currentBlock;
    delete nextBlock;
    delete td;
}
