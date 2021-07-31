#ifndef _ACTION_H_
#define _ACTION_H_

#include "SpecialActions.h"

class TextDisplay;
class Board;

class Blind : public SpecialActions {
	TextDisplay* td;
	Board* b;
	bool applied = false;
public:
	Blind(TextDisplay* td, Board* b);
	void applyAction() override;
	void restore();
};

class Heavy : public SpecialActions {
	Board* b;
public:
	Heavy(Board* b);
	void applyAction() override;
};

class Force : public SpecialActions {
public:
	void applyAction() override;
};

#endif
