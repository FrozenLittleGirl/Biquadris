#include <fstream>
#include "level.h"
#include "board.h"
#include "random.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "starblock.h"
#include <iostream> // delete this

using namespace std;

Block* hblock(int x, int y, char c) {
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
  cout << "error generate" << endl;
  return block;
}

// Level0
levelZero::levelZero(string file, int sd, bool set_sd) : NextBlock{ sd, set_sd } {
	ifstream infile{ file };
    char c;
    while (true) {
        infile >> c;
        if (infile.fail()) break;
        sequence.emplace_back(c);
        ++size;
    }
    for (auto p : sequence) {
        cout << "error " << p << endl; 
    }
}

Block* levelZero::generateBlock() {
    char c = sequence[current];
    cout << "error random" << endl;
    auto p = hblock(0, 0, c);
    cout << "error generateblock" << endl;
    ++current;
    if (current == size) {
        current = 0;
    }
    return p;
}

void levelZero::changeState(bool set, string s) {}

// Level1
levelOne::levelOne(int sd, bool set_sd) : NextBlock{sd, set_sd} {}

Block* levelOne::generateBlock() {
    char c = setChar(probSZ, probOther, sd, set_sd);
    auto p = hblock(0, 0, c);
    return p;
}

void levelOne::changeState(bool set, string s) {}

// Level2
levelTwo::levelTwo(int sd, bool set_sd) : NextBlock{ sd, set_sd } {}

Block* levelTwo::generateBlock() {
    char c = setChar(prob, prob, sd, set_sd);
    auto p = hblock(0, 0, c);
    return p;
}

void levelTwo::changeState(bool set, string s) {}

// Level3
levelThree::levelThree(int sd, bool set_sd) : NextBlock{ sd, set_sd } {}

Block* levelThree::generateBlock() {
    Block* p;
    if (random == true) {
        char c = setChar(probSZ, probOther, sd, set_sd);
        p = hblock(0, 0, c);
    }
    else {
        char c2 = sequence[current];
        p = hblock(0, 0, c2);
        ++current;
        if (current == size) {
            current = 0;
        }
    }
    return p;
}

void levelThree::changeState(bool set, string s) {
    random = set;
    if (random == false) {
        sequence.clear();
        size = 0;
        current = 0;
        ifstream infile{ s };
        char c;
        while (true) {
            infile >> c;
            if (infile.fail()) break;
            sequence.emplace_back(c);
            ++size;
        }
    }
}

// Level4
levelFour::levelFour(int sd, bool set_sd, Board* b) : NextBlock{ sd, set_sd }, b{ b } {}

Block* levelFour::generateBlock() {
    Block* p;
    if (random == true) {
        char c = setChar(probSZ, probOther, sd, set_sd);
        p = hblock(0, 0, c);
    }
    else {
        char c2 = sequence[current];
        p = hblock(0, 0, c2);
        ++current;
        if (current == size) {
            current = 0;
        }
    }
    return p;
}

void levelFour::changeState(bool set, string s) {
    random = set;
    if (random == false) {
        sequence.clear();
        size = 0;
        current = 0;
        ifstream infile{ s };
        char c;
        while (true) {
            infile >> c;
            if (infile.fail()) break;
            sequence.emplace_back(c);
            ++size;
        }
    }
}
