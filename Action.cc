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
void Heavy::Heavy(Board* b) : b{ b } {}

void Heavy::applyAction() {
	b->down(2);
}

// Force

// don't forget notify
void Force::applyAction() {}
