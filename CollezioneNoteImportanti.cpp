//
// Created by simon on 04/12/2022.
//

#include <iostream>
#include "CollezioneNoteImportanti.h"

void CollezioneNoteImportanti::AddNoteToList(Nota *nota) {
    if (nota->isPriorita()==1 && nota->isInseritoInUnaListaHpriorita()==0) { //controllo che sia di priorità, e che non sia gia in un altra lista a priorità alt
        nota->setInseritoInUnaListaHpriorita(1);
        listaToDoImportanti.push_back(nota); //inserisco in una lista
    }
    else cout << "la seguente nota è gia stata inserita in un altra lista, non puoi riserirla anche qua"; //stampare i dettagli della lista
}
