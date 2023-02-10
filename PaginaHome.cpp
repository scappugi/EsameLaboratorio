//
// Created by simon on 04/12/2022.
//

#include "PaginaHome.h"

void PaginaHome::addCollezione(CollezioneNote *collezioneNote) {
    this->collezioneNote.insert(make_pair((collezioneNote)->getNomeLista(), collezioneNote));
    collezioneNote->subscribe(
            this); //metodo attach implementato qua; passo a questo metodo il mio indirizzo cosi salva subito PaginaHome come Observer
}


void PaginaHome::addCollezioneNoteImportanti(CollezioneNoteImportanti *collezioneNoteImportanti) {
    this->collezioneNoteImportanti.insert(
            make_pair((collezioneNoteImportanti)->getNomeLista(), collezioneNoteImportanti));
    collezioneNoteImportanti->subscribe(
            this); //metodo attach implementato qua; passo a questo metodo il mio indirizzo cosi salva subito PaginaHome come Observer
}


void PaginaHome::creaNuovaCollezione(const string &nomeCollezione) {
    if (collezioneNote.find(nomeCollezione) == collezioneNote.end()) {
        //questo if ricerca se abbiamo non già una collezione di liste con questo nome
        CollezioneNote *nuovaCollezione = new CollezioneNote(nomeCollezione); //crea una nuova collezione
        addCollezione(nuovaCollezione);
    } else cout << "hai gia creato una collezione con questo nome" << endl;
}

void PaginaHome::creaNuovaCollezioneNoteImportanti(const string &nomeCollezione) {
    if (collezioneNoteImportanti.find(nomeCollezione) == collezioneNoteImportanti.end()) {
        //questo if ricerca se abbiamo non già una collezione di liste con questo nome
        CollezioneNoteImportanti nuovaCollezione(nomeCollezione);
        addCollezioneNoteImportanti(&nuovaCollezione);
    } else cout << "hai gia creato una collezione con questo nome";
}

bool PaginaHome::verificaImportanza(const Nota &nota) {
    if (nota.getPriorita() == false)return false;
    else return true;
}

bool PaginaHome::aggiungiNotaACollezioneBase(Nota &nota, const string &nomeCollezione) {
    auto it = collezioneNote.find(nomeCollezione);
    if (it != collezioneNote.end()) {
        //se if positivo allora esiste una collezione con il nome cercato quindi si procede ad inserire al suo interno la nota
        it->second->AddNoteToList(nota); //accedo all elemento lista di note e inserisco la nota che dovevo inserire.
        return true;
    }
    else return false;
}

void PaginaHome::aggiungiNotaACollezioneImportanti(Nota &nota, const string &NomeCollezione) {
    auto it = collezioneNoteImportanti.find(NomeCollezione);
    if (it != collezioneNoteImportanti.end()) {
        it->second->AddNoteToList(nota);
    }
}

void PaginaHome::setAltaPriorita(Nota &nota, const string &nomeCollezione) {
    auto it = collezioneNote.find(nomeCollezione);
    if (it != collezioneNote.end()) {
        it->second->aumentaPrioritaNota(nota);//in questo metodo si aumenta automaticamente la priorità di una nota
    }
}

void PaginaHome::update(const string &name,int size) { //stampa a schermata il numero di note nella collezione con il nome passato come parametro
    std::cout << "la collezione -- " << name << " -- ha in questo momento n: " << size << " note " << endl;
}

void PaginaHome::setBassaPriorita(Nota &nota, const string &nomeCollezione) {
    auto it = collezioneNoteImportanti.find(nomeCollezione);
    if (it != collezioneNoteImportanti.end()) {
        it->second->diminuisciPrioritaNota(
                nota);//in questo metodo si diminuisce automaticamente la priorità di una nota
    }
    auto itr = collezioneNote.find(nomeCollezione);
    if (itr != collezioneNote.end()) {
        itr->second->diminuisciPrioritaNota(nota);//in questo metodo si diminuisce automaticamente la priorità di una nota
    }
}

void PaginaHome::setBloccoNota(Nota &nota, const string &nomeCollezione) {
    auto it = collezioneNote.find(nomeCollezione);
    if (it != collezioneNote.end()) {
        it->second->bloccaNota(nota);
    } //bisogna fare due ricerche nel caso in cui la nota non si trovi nella collezione delle collezioni basi
    auto itr = collezioneNoteImportanti.find(nomeCollezione);
    if (itr != collezioneNoteImportanti.end()) {
        itr->second->bloccaNota(nota);
    }
}

void PaginaHome::setBloccaTutteLeNote(const string &nomeCollezione) {
    auto it = collezioneNote.find(nomeCollezione);
    if (it != collezioneNote.end()) {
        it->second->bloccaTutteLeNote();
    }
    auto itr = collezioneNoteImportanti.find(nomeCollezione);
    if (itr != collezioneNoteImportanti.end()) {
        itr->second->bloccaTutteLeNote();
    }
}

void PaginaHome::spostaNota(Nota &nota, const string &collezioneIniziale, const string &collezionefinale) {
    auto it = collezioneNote.find(collezioneIniziale);
    if (it != collezioneNote.end()) {
        it->second->removeToList(nota);
    }
    auto itr = collezioneNoteImportanti.find(collezioneIniziale);
    if (itr != collezioneNoteImportanti.end()) {
        itr->second->removeToList(nota);
    }
    auto it1 = collezioneNote.find(collezionefinale);
    if (it1 != collezioneNote.end()) {
        it1->second->AddNoteToList(nota);
    }
    auto itr1 = collezioneNoteImportanti.find(collezionefinale);
    if (itr1 != collezioneNoteImportanti.end()) {
        itr1->second->AddNoteToList(nota);
    }
}

bool PaginaHome::eliminaNota(const string &nomeCollezione, Nota &nota) {
    auto it = collezioneNote.find(nomeCollezione);
    if (it != collezioneNote.end()) {
        return it->second->removeToList(nota);
    }
    auto itr = collezioneNoteImportanti.find(nomeCollezione);
    if (itr != collezioneNoteImportanti.end()) {
        return itr->second->removeToList(nota);
    }
    return false;
}

bool PaginaHome::contieneCollezioni(const string &collection) {
    return (collezioneNote.find(collection) != collezioneNote.end()); //vero se la trova, falso il contrario
}

bool PaginaHome::eliminaCollezione(const string &nomeCollezione) {

    auto it = collezioneNote.find(nomeCollezione);
    if (it != collezioneNote.end()) {
        collezioneNote.erase(it);
        return true;
    } else {
        cout << "la collezione " << nomeCollezione << " non esiste." << endl;
        return false;
    }
}

bool PaginaHome::verificaBloccoNota(const Nota &nomeNota) {
    if (nomeNota.getBlocco() == false)return false;
    else return true;
}

bool PaginaHome::contieneNote( Nota const &nota, const string &nomeCollezione) {
    auto it=collezioneNote.find(nomeCollezione);
    if( it != collezioneNote.end()){ //se vero allora esiste una collezione con quel nome
        return it->second->cercaNote(nota); //funzione che ritorna vero se la nota viene trovata.
    } else return false; //la collezione non è stata trovata
}






