#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>

class Observer;

class Subject {
    protected:
        std::vector<Observer*> observers;
    public:
        void virtual notifyObservers() = 0;
        void attach(Observer *o);
};

#endif
