#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "subject.h"

class Board;

class Observer {
    public:
        virtual void notify(Board &b) = 0;
        virtual ~Observer() = default;
};

#endif