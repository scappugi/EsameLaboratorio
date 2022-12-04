//
// Created by simon on 04/12/2022.
//

#include "CollezioneNote.h"
void CollezioneNote::AddNoteToList(Nota *nota) {
    if (nota->isInseritoInUnaLista() == 0) { //controllo che non sia già stato inserito in un altra lista
        nota->setInseritoInUnaLista(1);
        listaToDo.push_back(nota); //inserisco in una lista
        notify();
    }
    else cout << "la seguente nota è gia stata inserita in un altra lista, non puoi riserirla anche qua"; //stampare i dettagli della lista
}

void CollezioneNote::removeToList(Nota *nota) {
    for ( auto itr = listaToDo.begin() ; itr != listaToDo.end(); itr++){
        if (*itr == nota){
            listaToDo.remove(nota);
            nota->setInseritoInUnaLista(0); //permette alla nota di essere riserita in una lista
            notify();
        }
        else cout<<"il dato che stai provado ad eliminare non esiste in questa lista"<<endl;
    }
}
void CollezioneNote::removeAndDestroyNote(Nota *nota) {
    listaToDo.remove(nota);
    nota->setInseritoInUnaLista(0); //permette alla nota di essere riserita in una lista
    delete nota; //elimina il puntatore nota.
    notify();
}

void CollezioneNote::subscribe(Observer *o) {
    this->observer=o;//aggiunto observer verso il quale dovremmo inviare notifche
}

void CollezioneNote::unsubscribe(Observer *o) {
    this->observer= nullptr; //tolto l' observer
}

void CollezioneNote::notify() {

    observer->update(getNomeLista(),listaToDo.size()); //passo al notify i numeri inerenti al numero di cose attuali in quella lista
}

string CollezioneNote::getNomeLista() {
    return nomeLista;
}

void CollezioneNote::setNomeLista(string name) {
    nomeLista=name;
}
