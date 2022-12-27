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
    virtual void AddNoteToList(Nota *nota); //NON AGGIUNGERE NOTE CON LO STESSO TITOLO, ESSO DEVE ESSERE UNIVOCO
    virtual void removeToList(Nota *nota);
    virtual void removeAndDestroyNote(Nota *nota);
    void setNomeLista(string name);
    bool bloccaNota(Nota *nota); //ritorna 1 se bloccata con successo altrimenti 0
    bool sbloccaNota(Nota *nota); //permette di togliere il blocco messo da bloccaNota
    void bloccaTutteLeNote();//pone tutte le note su bloccato
    void aumentaPrioritàNota(Nota *nota);
    void diminuisciPrioritàNota(Nota *nota);
    void modificaNota(Nota *nota, string const newTitle); //vuole andare a cambiare il titolo della nota
    Nota* getNota(string const nomeNota); //restituisce la prima nota con quel nome
    string getNomeLista();
    //fine

    //metodi per pattern observer
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    void notify() override;
    //fine

    virtual ~CollezioneNote();

private:
    list<Nota *> listaToDo;
    Observer *observer;
    string nomeLista;

};



#endif //ESAMELABORATORIO_COLLEZIONENOTE_H
