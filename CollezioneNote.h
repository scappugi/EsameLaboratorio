//
// Created by simon on 04/12/2022.
//

#ifndef ESAMELABORATORIO_COLLEZIONENOTE_H
#define ESAMELABORATORIO_COLLEZIONENOTE_H


#include "Nota.h"
#include "list"
#include "iostream"
#include "Subject.h"

using namespace std;

class CollezioneNote: public Subject {
public:
    explicit CollezioneNote(string nomeLista){ //costruttore che assegna un nome alla lista
        this->nomeLista=nomeLista;}

    //metodi gestione lista
    virtual void AddNoteToList(Nota *nota);
    virtual void removeToList(Nota *nota);
    virtual void removeAndDestroyNote(Nota *nota);
    string getNomeLista();
    //fine

    //metodi per pattern observer
    virtual void subscribe(Observer *o);
    virtual void unsubscribe(Observer *o);
    virtual void notify();
    //fine

    virtual ~CollezioneNote();

private:
    list<Nota *> listaToDo;
    Observer *observer;
    string nomeLista;

};



#endif //ESAMELABORATORIO_COLLEZIONENOTE_H
