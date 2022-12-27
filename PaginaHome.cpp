//
// Created by simon on 04/12/2022.
//

#include "PaginaHome.h"

void PaginaHome::addCollezione(CollezioneNote *collezioneNote) {
        this->collezioneNote.insert(make_pair((*collezioneNote).getNomeLista(), collezioneNote));
        collezioneNote->subscribe(this); //metodo attach implementato qua; passo a questo metodo il mio indirizzo cosi salva subito PaginaHome come Observer
}


void PaginaHome::addCollezioneNoteImportanti(CollezioneNote *collezioneNoteImportanti) {
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
        CollezioneNote* nuovaCollezione;
        nuovaCollezione->setNomeLista(nomeCollezione);
        addCollezioneNoteImportanti(nuovaCollezione);
    }
    else cout<<"hai gia creato una collezione con questo nome";
}

bool PaginaHome::verificaImportanza(Nota &nota) {
    if (nota.isPriorita()==false)return false;
    else return true;
}

void PaginaHome::aggiungiNotaACollezioneBase(Nota *nota, string nomeCollezione) {
    auto it=collezioneNote.find(nomeCollezione);
    if  (it != collezioneNote.end()){
        //se if positivo allora esiste una collezione con il nome cercato quindi si procede ad inserire al suo interno la nota
        it->second->AddNoteToList(nota); //accedo all elemento lista di note e inserisco la nota che dovevo inserire.
    }
}

void PaginaHome::aggiungiNotaACollezioneImportanti(Nota *nota, string NomeCollezione) {
    auto it = collezioneNoteImportanti.find(NomeCollezione);
    if ( it != collezioneNoteImportanti.end()){
        it->second->AddNoteToList(nota);
    }
}

void PaginaHome::setAltaPriorità(Nota *nota, string nomeCollezione) {
    auto it = collezioneNoteImportanti.find(nomeCollezione);
    if ( it != collezioneNoteImportanti.end()){
        it->second->aumentaPrioritàNota(nota);//in questo metodo si aumenta automaticamente la priorità di una nota
    }
}
//pensare a se fare un metodo per le liste prioritarie o no
