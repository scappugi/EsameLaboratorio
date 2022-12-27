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

bool CollezioneNote::bloccaNota(Nota *nota) {
    for (auto itr = listaToDo.begin(); itr != listaToDo.end(); itr++) {
        if (*itr == nota) {
            nota->setBlocco(true);
            return true;
        } else {
            cout << "nella lista " << getNomeLista() << " non esiste nessuna nota con il nome " << nota->getNomeNota()<< endl;
            return false; //caso di fallimento
        }
    }
}

bool CollezioneNote::sbloccaNota(Nota *nota) {
    for (auto itr = listaToDo.begin(); itr != listaToDo.end(); itr++) {
        if (*itr == nota){
            nota->setBlocco(0);
            return true;
        }
        else {
            cout << "nella lista " << getNomeLista() << " non esiste nessuna nota con il nome " << nota->getNomeNota()<< endl;
            return false;
        }
    }
    }

void CollezioneNote::modificaNota(Nota *nota, string const newTitle) {
    for (auto itr = listaToDo.begin(); itr != listaToDo.end(); itr++) {
        if (*itr == nota){ //la nota è in quella lista
        nota->setNomeNota(newTitle);
        }
    }
}

void CollezioneNote::bloccaTutto() {
    for (auto it :listaToDo){
        (*it).setBlocco(true);
    }
}

Nota* CollezioneNote::getNota(string const nomeNota) {
    for (auto it :listaToDo){
        if(it->getNomeNota()==nomeNota)
            return it; //ritorno la nota che ha il nome cercato
    }
}

void CollezioneNote::aumentaPrioritàNota(Nota *nota) {
    for(auto it : listaToDo){
        if(it == nota){
            it->setPriorita(1);//imposta la priorità ad alta
        }
    }
}

