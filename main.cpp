#include <iostream>
#include "Nota.h"
#include "CollezioneNote.h"
#include "CollezioneNoteImportanti.h"
#include "PaginaHome.h"

int main() {

Nota nota1 ("Lavori", "lavori da fare durante la settimana");

Nota nota2 ("Esami","schedulazione esami da fare durante l' anno");

Nota nota3 ("Analisi I","Esame di analisi I" );

Nota nota4 ("Analisi II", "Esame di analisi II" );

Nota nota5 ("Fisica II");

PaginaHome paginaHome;

CollezioneNote collezione1 ("lista preparazione esami");

paginaHome.addCollezione(&collezione1);

collezione1.AddNoteToList(&nota3); //aggiunge alla collezione e stampa con observer
collezione1.bloccaNota(&nota3);
collezione1.AddNoteToList(&nota4);
//collezione1.removeAndDestroyNote(&nota3); //distrugge dalla collezione e stampa con observer
collezione1.stampaNote();
collezione1.removeToList(&nota4);
collezione1.stampaNote();



}
