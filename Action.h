#ifndef _ACTION_H_
#define _ACTION_H_

#include "SpecialActions.h"

class Blind : public SpecialAction {
public:
        void applyAction() override;  // really does nothing at current level of implementation
};

class Heavy : public SpecialAction {
public:
        void applyAction() override;  // really does nothing at current level of implementation
};

class Force : public SpecialAction {
public:
        void applyAction() override;  // really does nothing at current level of implementation
};

#endif
