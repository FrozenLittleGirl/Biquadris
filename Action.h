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
	void recover(bool restore) override;
};

class Heavy : public SpecialActions {
	shared_ptr b;
public:
	void applyAction() override;
};

class Force : public SpecialActions {
	bool applied = false;
	char type;
	TextDisplay* td;
	Board* b;
public:
	Force(TextDisplay* td, Board* b);
	void applyAction() override;
};

#endif
