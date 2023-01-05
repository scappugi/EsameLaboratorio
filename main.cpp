#include <iostream>
#include "Nota.h"
#include "CollezioneNote.h"
#include "CollezioneNoteImportanti.h"
int main() {
Nota nota1 ("Lavori", "lavori da fare durante la settimana");
Nota nota2 ("Esami","schedulazione esami da fare durante l' anno");
Nota nota3 ("Analisi I" );
Nota nota4 ("Analisi II");
Nota nota5 ("Fisica II");

CollezioneNote collezione1 ("lista preparazione esami");

collezione1.AddNoteToList(nota3);

}
