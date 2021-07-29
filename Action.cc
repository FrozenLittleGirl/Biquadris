#include "Action.h"
#include "TextDisplay.h"
#include "Board.h"
#include <string>
#include <iostream>

using namespace std;

// Blind
Blind::Blind(TextDisplay* td, Board* b): td{td}, b{b} {}

void Blind::applyAction() {
	if (applied == false) {
		td->notifyBlind();
	}
	applied = true;
}

void Blind::restore() {
	b->restore();
}

// Heavy
void Heavy::applyAction() {
	b->moveDown();
	b->moveDown();
}

// Force
Force::Force(TextDisplay* td, Board* b) : td{ td }, b{ b } { cin >> type; }

void Force::applyAction() {
	if (applied == false) {

	}
	applied = true;
}
