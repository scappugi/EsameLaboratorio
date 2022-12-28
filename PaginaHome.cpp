//
// Created by simon on 04/12/2022.
//

#include "PaginaHome.h"

void PaginaHome::addCollezione(CollezioneNote *collezioneNote) {
        this->collezioneNote.insert(make_pair((*collezioneNote).getNomeLista(), collezioneNote));
        collezioneNote->subscribe(this); //metodo attach implementato qua; passo a questo metodo il mio indirizzo cosi salva subito PaginaHome come Observer
}


void PaginaHome::addCollezioneNoteImportanti(CollezioneNoteImportanti *collezioneNoteImportanti) {
        this->collezioneNoteImportanti.insert(make_pair((*collezioneNoteImportanti).getNomeLista(), collezioneNoteImportanti));
        collezioneNoteImportanti->subscribe(this); //metodo attach implementato qua; passo a questo metodo il mio indirizzo cosi salva subito PaginaHome come Observer
}


void PaginaHome::creaNuovaCollezione( const string &nomeCollezione) {
        if (collezioneNote.find(nomeCollezione) != collezioneNote.end()){
        //questo if ricerca se abbiamo non già una collezione di liste con questo nome
        CollezioneNote* nuovaCollezione;
        nuovaCollezione->setNomeLista(nomeCollezione);
        addCollezione(nuovaCollezione);
        }
        else cout<<"hai gia creato una collezione con questo nome";
}
void PaginaHome::creaNuovaCollezioneNoteImportanti( const string &nomeCollezione) {
    if (collezioneNoteImportanti.find(nomeCollezione) != collezioneNoteImportanti.end()){
        //questo if ricerca se abbiamo non già una collezione di liste con questo nome
        CollezioneNoteImportanti* nuovaCollezione;
        nuovaCollezione->setNomeLista(nomeCollezione);
        addCollezioneNoteImportanti(nuovaCollezione);
    }
    else cout<<"hai gia creato una collezione con questo nome";
}

bool PaginaHome::verificaImportanza(Nota &nota) {
    if (nota.getPriorita()==false)return false;
    else return true;
}

void PaginaHome::aggiungiNotaACollezioneBase(Nota *nota,const string& nomeCollezione) {
    auto it=collezioneNote.find(nomeCollezione);
    if  (it != collezioneNote.end()){
        //se if positivo allora esiste una collezione con il nome cercato quindi si procede ad inserire al suo interno la nota
        it->second->AddNoteToList(nota); //accedo all elemento lista di note e inserisco la nota che dovevo inserire.
    }
}

void PaginaHome::aggiungiNotaACollezioneImportanti(Nota *nota,const string& NomeCollezione) {
    auto it = collezioneNoteImportanti.find(NomeCollezione);
    if ( it != collezioneNoteImportanti.end()){
        it->second->AddNoteToList(nota);
    }
}

void PaginaHome::setAltaPriorità(Nota *nota,const string& nomeCollezione) {
    auto it = collezioneNote.find(nomeCollezione);
    if ( it != collezioneNote.end()){
        it->second->aumentaPrioritàNota(nota);//in questo metodo si aumenta automaticamente la priorità di una nota
    }
}

void PaginaHome::update(string name, int size) {

}

void PaginaHome::setBassaPriorità(Nota *nota,const string& nomeCollezione) {
    auto it = collezioneNoteImportanti.find(nomeCollezione);
    if ( it != collezioneNoteImportanti.end()){
        it->second->diminuisciPrioritàNota(nota);//in questo metodo si diminuisce automaticamente la priorità di una nota
    }
    auto itr=collezioneNote.find(nomeCollezione);
    if ( itr != collezioneNote.end()){
        itr->second->diminuisciPrioritàNota(nota);//in questo metodo si diminuisce automaticamente la priorità di una nota
    }
}

void PaginaHome::setBloccoNota(Nota *nota, const string &nomeCollezione) {
    auto it =collezioneNote.find(nomeCollezione);
    if(it != collezioneNote.end()){
        it->second->bloccaNota(nota);
    } //bisogna fare due ricerche nel caso in cui la nota non si trovi nella collezione delle collezioni basi
    auto itr =collezioneNoteImportanti.find(nomeCollezione);
    if(itr != collezioneNoteImportanti.end()){
        itr->second->bloccaNota(nota);
    }
}

void PaginaHome::setBloccaTutteLeNote(const string &nomeCollezione) {
    auto it =collezioneNote.find(nomeCollezione);
    if(it != collezioneNote.end()){
        it->second->bloccaTutteLeNote();
    }
    auto itr =collezioneNoteImportanti.find(nomeCollezione);
    if(itr != collezioneNoteImportanti.end()){
        itr->second->bloccaTutteLeNote();
    }
}

void PaginaHome::spostaNota(Nota *nota, const string& collezioneIniziale, const string& collezionefinale) {
    auto it =collezioneNote.find(collezioneIniziale);
    if(it != collezioneNote.end()){
        it->second->removeToList(nota);
    }
    auto itr =collezioneNoteImportanti.find(collezioneIniziale);
    if(itr != collezioneNoteImportanti.end()){
        itr->second->removeToList(nota);
    }
    auto it1 =collezioneNote.find(collezionefinale);
    if(it1 != collezioneNote.end()){
        it1->second->AddNoteToList(nota);
    }
    auto itr1 =collezioneNoteImportanti.find(collezionefinale);
    if(itr1 != collezioneNoteImportanti.end()){
        itr1->second->AddNoteToList(nota);
    }
}

void PaginaHome::eliminaNota(const string &nomeCollezione, Nota *nota) {
    auto it =collezioneNote.find(nomeCollezione);
    if(it != collezioneNote.end()){
            it->second->removeAndDestroyNote(nota);
    }
    auto itr =collezioneNoteImportanti.find(nomeCollezione);
    if(itr != collezioneNoteImportanti.end()){
        itr->second->removeAndDestroyNote(nota);
    }
}




//pensare a se fare un metodo per le liste prioritarie o no
