#ifndef _SPECIALACTIONS_H_
#define _SPECIALACTIONS_H_

class SpecialAction {
public:
        virtual void applyAction() = 0;
        virtual ~SpecialAction();
};

#endif
