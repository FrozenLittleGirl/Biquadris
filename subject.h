#ifndef _SUBJECT_H_
#define _SUBJECT_H_

class Observer;

class Subject {
    protected:
        std::vector<Observer*> observers;
    public:
        void attach(Observer *o);
};

#endif