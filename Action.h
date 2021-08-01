#ifndef _ACTION_H_
#define _ACTION_H_

#include "SpecialActions.h"

class Blind : public SpecialActions {
public:
	void applyAction() override;
};

class Heavy : public SpecialActions {
public:
	void applyAction() override;
};

class Force : public SpecialActions {
public:
	void applyAction() override;
};

#endif
