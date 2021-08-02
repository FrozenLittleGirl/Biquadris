#ifndef _ACTION_H_
#define _ACTION_H_

#include "SpecialActions.h"

class Blind : public SpecialAction {
public:
        void applyAction() override;
};

class Heavy : public SpecialAction {
public:
        void applyAction() override;
};

class Force : public SpecialAction {
public:
        void applyAction() override;
};

#endif
