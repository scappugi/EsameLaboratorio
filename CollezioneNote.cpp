//
// Created by simon on 04/12/2022.
//

#include "CollezioneNote.h"

void CollezioneNote::AddNoteToList(Nota  &nota) {
    if (nota.isInseritoInUnaLista() == false) { //controllo che non sia già stato inserito in un altra lista
        nota.setInseritoInUnaLista(true);
        listaToDo.push_back(nota); //inserisco in una lista
        notify();
    } else
        cout<< "la seguente nota è gia stata inserita in un altra lista, non puoi riserirla anche qua"; //stampare i dettagli della lista
}

bool CollezioneNote::removeToList(Nota &nota) {
    std::list<Nota>::iterator itr;
    for (itr = listaToDo.begin(); itr != listaToDo.end(); itr++) {
        if (*itr == nota) {
            if ((*itr).getBlocco() == false) {
                listaToDo.remove(nota);
                nota.setInseritoInUnaLista(false);
                cout << "il dato e' stato eliminato" << endl;
                notify();
                return true;
            } else {
                cout << "il dato che vuoi eliminare e' bloccato in questo momento" << endl;
                return false;
            }
        }
    }
    cout << "il dato non esiste" << endl;
    return false;
}

bool CollezioneNote::removeAndDestroyNote(Nota &nota) {
    for (auto itr: listaToDo) {
        if (itr == nota) {
            if (nota.getBlocco() == false){
                listaToDo.remove(nota);
                nota.setInseritoInUnaLista(false); //permette alla nota di essere riserita in una lista
                delete &nota; //elimina il puntatore nota.
                notify();
                return true;
            } else {
                cout << "il dato -- " << nota.getNomeNota() << " -- e' bloccato, non puoi eliminarlo" << endl;

            }
        }
    }
    cout << "il dato che stai provado ad eliminare non esiste in questa lista" << endl;
    return false;
}

void CollezioneNote::subscribe(Observer *o) {
    this->o = o;//aggiunto observer verso il quale dovremmo inviare notifche
}

void CollezioneNote::unsubscribe(Observer *o) {
    this->o = nullptr; //tolto l' observer
}

void CollezioneNote::notify() { //da qua si vede che ho implementato l' observer in modalità push.
    if (o != nullptr)//controllo se ho un observer da avvisare.
        o->update(this->getNomeLista(),
                  this->listaToDo.size()); //passo al notify i numeri inerenti al numero di cose attuali in quella lista
}

string CollezioneNote::getNomeLista() {
    return nomeLista;
}

void CollezioneNote::setNomeLista(const string &name) {
    nomeLista = name;
}

bool CollezioneNote::bloccaNota(Nota &nota) {
    std::list<Nota>::iterator itr;
    for (itr = listaToDo.begin(); itr != listaToDo.end(); ++itr) {
        if (*itr == nota) {
            /*  listaToDo.remove(nota);
              nota.setBlocco(true);
              listaToDo.push_back(nota);*/
            (*itr).setBlocco(true);
            return true;
        } else {
            cout << "nella lista " << getNomeLista() << " non esiste nessuna nota con il nome " << nota.getNomeNota()
                 << endl;
            return false; //caso di fallimento
        }
    }
    return false;
}

bool CollezioneNote::sbloccaNota(Nota &nota) {
    for (auto itr = listaToDo.begin(); itr != listaToDo.end(); itr++) {
        if (*itr == nota) {
            (*itr).setBlocco(false);
            return true;
        } else {
            cout << "nella lista " << getNomeLista() << " non esiste nessuna nota con il nome " << nota.getNomeNota()
                 << endl;
            return false;
        }
    }
    return false;
}

void CollezioneNote::modificaNota(Nota &nota, const string &newTitle) { //questo metodo prende due stringhe, usa la stringa old per fare la ricerca della nota, ciò comporta pero a dover avere UNIVOCI i nomi delle note(non ho impostato questo controllo)
    for (auto itr: listaToDo) {
        if (itr == nota) { //la nota è in quella lista
            if (nota.getBlocco() == 0) {
                listaToDo.remove(itr);
                nota.setNomeNota(newTitle);
                listaToDo.push_back(nota);
            }
        }
    }
}

void CollezioneNote::bloccaTutteLeNote() {
    std::list<Nota>::iterator it;
    if (listaToDo.empty()) {
        cout << "lista vuota, non c'e' nulla da bloccare";
    } else {
        for (it = listaToDo.begin(); it != listaToDo.end(); it++) {
            (*it).setBlocco(true);
        }
    }
}

Nota CollezioneNote::getNota(const string &nomeNota) {
    for (auto it: listaToDo) {
        if (nomeNota == it.getNomeNota()) {
            return it;
        }
    }
    return Nota("");
}

void CollezioneNote::aumentaPrioritaNota(const Nota &nota) {
    for (auto it: listaToDo) {
        if (&it == &nota) {
            it.setPriorita(true);//imposta la priorità ad alta
        }
    }
}

void CollezioneNote::diminuisciPrioritaNota(const Nota &nota) {
    for (auto it: listaToDo) {
        if (it == nota) {
            it.setPriorita(false);//imposta la priorità ad alta
        }
    }
}

void CollezioneNote::stampaNote() {
    for (auto it: listaToDo) {
        if (!listaToDo.empty()) {
            cout << it.getNomeNota() << it.getBlocco() << endl;
        }
    }
    cout << "lista vuota" << endl;
}


bool CollezioneNote::cercaNote(const Nota &nota) {
    for (auto it: listaToDo) {
        //if (it->getNomeNota().compare(nota->getNomeNota())==0){ //confronto le stringhe per vedere se esiste l'' elemento in quella lista
        if (it.getNomeNota() == nota.getNomeNota()) {
            return true;
        }
    }
    return false;
}



