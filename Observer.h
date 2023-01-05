//
// Created by simon on 04/12/2022.
//

#ifndef ESAMELABORATORIO_OBSERVER_H
#define ESAMELABORATORIO_OBSERVER_H
#include "string"
using namespace std;

class Observer {
public:
    virtual ~Observer()=default; //distruttore virtuale
    virtual void update(string name ,int size) = 0; //inserisco dimensione attuale della lista come parametro di update
};

#endif //ESAMELABORATORIO_OBSERVER_H
