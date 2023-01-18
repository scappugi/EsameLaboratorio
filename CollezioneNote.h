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

class CollezioneNote : public Subject {
public:
    explicit CollezioneNote(const string nomeLista): nomeLista(nomeLista){ //costruttore che assegna un nome alla list
      }

    ~CollezioneNote() override = default;

    ///metodi gestione lista
    virtual void AddNoteToList(Nota *nota); //NON AGGIUNGERE NOTE CON LO STESSO TITOLO, ESSO DEVE ESSERE UNIVOCO
    virtual bool removeToList(Nota *nota);

    virtual void removeAndDestroyNote(Nota *nota);

    void setNomeLista(const string &name);

    bool bloccaNota(Nota *nota); //ritorna 1 se bloccata con successo altrimenti 0
    bool sbloccaNota(Nota *nota); //permette di togliere il blocco messo da bloccaNota
    void bloccaTutteLeNote();//pone tutte le note su bloccato
    void aumentaPrioritaNota(Nota *nota);
    void diminuisciPrioritaNota(Nota *nota);
    void modificaNota(Nota *nota, const string &newTitle); //vuole andare a cambiare il titolo della nota
    Nota *getNota(const string &nomeNota); //restituisce la prima nota con quel nome
    string getNomeLista();
    void stampaNote();
    bool cercaNote(Nota *nota);
    ///fine

    ///metodi per pattern observer
    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify() override;
    ///fine



protected:
    Observer *observer;
    list<Nota *> listaToDo;
    string nomeLista;//utilizzo una sola variabile poichè ci sara da notificare solamente PaginaHome degli aggiornamenti
};


#endif //ESAMELABORATORIO_COLLEZIONENOTE_H
