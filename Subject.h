//
// Created by simon on 04/12/2022.
//

#ifndef ESAMELABORATORIO_SUBJECT_H
#define ESAMELABORATORIO_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer *o) = 0;
    virtual void unsubscribe(Observer *o) = 0;
    virtual void notify() = 0;
    virtual ~Subject();
};

#endif //ESAMELABORATORIO_SUBJECT_H
