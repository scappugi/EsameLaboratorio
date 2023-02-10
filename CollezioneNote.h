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
    explicit CollezioneNote(const string& nomeLista): nomeLista(nomeLista){ //costruttore che assegna un nome alla list
      }

     ~CollezioneNote() override = default; //distruttore

    ///metodi per aggiungere
    virtual void AddNoteToList(Nota &nota); //NON AGGIUNGERE NOTE CON LO STESSO TITOLO, ESSO DEVE ESSERE UNIVOCO


    ///metodi per rimuovere
    virtual bool removeToList(Nota &nota);
    virtual bool removeAndDestroyNote(Nota &nota);


    ///metodi get e set
    void setNomeLista(const string &name);
    bool bloccaNota(Nota &nota); //ritorna 1 se bloccata con successo altrimenti 0
    bool sbloccaNota(Nota &nota); //permette di togliere il blocco messo da bloccaNota
    void bloccaTutteLeNote();//pone tutte le note su bloccato
    void aumentaPrioritaNota(Nota &nota);
    void diminuisciPrioritaNota(Nota &nota);
    string getNomeLista();
    Nota getNota(const string &nomeNota); //restituisce la prima nota con quel nome


    ///metodi per modificare e ricercare
    void modificaNota(Nota &nota, const string &newTitle); //vuole andare a cambiare il titolo della nota
    void stampaNote();
    bool cercaNote(const Nota &nota);


    ///metodi per pattern observer
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    void notify() override;

    ///sovraccaricamento operatore ==


protected:

    list<Nota> listaToDo;
    string nomeLista;//utilizzo una sola variabile poichè ci sara da notificare solamente PaginaHome degli aggiornamenti
};


#endif //ESAMELABORATORIO_COLLEZIONENOTE_H
