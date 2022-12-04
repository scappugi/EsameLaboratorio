//
// Created by simon on 04/12/2022.
//

#ifndef ESAMELABORATORIO_OBSERVER_H
#define ESAMELABORATORIO_OBSERVER_H


class Observer {
public:
    virtual ~Observer(); //distruttore virtuale
    virtual void update(int size) = 0; //inserisco dimensione attuale della lista come parametro di update
    virtual void attach() = 0;
    virtual void detach() = 0;

};

#endif //ESAMELABORATORIO_OBSERVER_H
