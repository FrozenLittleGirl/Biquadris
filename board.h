#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "block.h"
#include "cell.h"

class View;
class TextDisplay;
class SpecialAction;
class NextBlock;

class Board {
    const int NUM_COLS = 11;
    const int NUM_ROWS = 18;
    int x;
    int y;
    std::std::vector<std::std::vector<Cell>> theBoard;
    std::vector<std::vector<Cell>> nextBlockGrid;
    Board* opponent = nullptr;
    View *view = nullptr;
    TextDisplay *td = nullptr;
    SpecialAction* action = nullptr;
    NextBlock* level = nullptr;
    int level_n = 0;
    Block* currentBlock = nullptr;
    Block* nextBlock = nullptr;
    void move(int angle, int x, int y);  // rotate "angle" degree, move x step horizontally, move y vertically
    bool isShiftValid(int angle, int x, int y);  // determine if rotate/left/right/down is valid
    void detectRow();  // detect if any row of cells is filled
    int* turn;
    int graphicx;
    int graphicy;

    int block_created = 0;
    bool clearRow = false;
    void dropStar();  // drop the starblock
    void displayScore();
    void displayLevel();
    void displayBoard();
    void displayCell(int r, int c, std::vector<std::vector<Cell>> grid);
    void setNextBlockGraphics();
    void displayNextBlock(char type);

    int score = 0;
    int tmp_score = 0;
    bool lose = false;
    void addAction(Board* opponent, std::string s);  // add a special action to the opponent

    public:
        Board(int x, int y, View *v);
        friend ostream &operator<<(ostream &out, const Board &b);
        void init();  // initialize/restart the board
        void clearBoard();  // empty the board

        void drop();  // drop block
        void down(int steps);  // move block steps downward
        void left(int steps);  // move block steps leftward
        void right(int steps);  // move block steps rightward
        void clockwise(int angle);  // rotate block angle degrees
        void counterclockwise(int angle);  // rotate block -angle degrees
        bool determineLose();  // determine if the board loses
        int determineScore();  // return score
        void attach(Board* opponent, int* n);  // attach opponent and turn to the board
        void setRandom(bool set, std::string s);  // set randomness to level 3 or 4
        void addLevel(int n, int seed, bool set_seed, std::string file);  // attach a new level to the board
        void newBlock(char c = 'n');  // generate a new block
        Block* getNextBlock() const;  // get next block
        int getLevel() const;  // return current level
        int getScore() const;  // return current score
        void setCurrentBlock(Block * newBlock);  // set currentblock
        SpecialAction* getAction() const;  // return current special action
        std::vector<std::vector<Cell>> getBoard() const;  // return a copy of the cells of the board
        int currentLevel();

        ~Board();
};

#endif
