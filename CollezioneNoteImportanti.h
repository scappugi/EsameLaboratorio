//
// Created by simon on 04/12/2022.
//

#ifndef ESAMELABORATORIO_COLLEZIONENOTEIMPORTANTI_H
#define ESAMELABORATORIO_COLLEZIONENOTEIMPORTANTI_H


#include "Nota.h"
#include "list"
#include "Subject.h"
#include "CollezioneNote.h"

class CollezioneNoteImportanti: public CollezioneNote{
public:
    virtual void AddNoteToList(Nota *nota) override;
    virtual ~CollezioneNoteImportanti();

private:
    list<Nota *> listaToDoImportanti;
    string nomeLista;
};


#endif //ESAMELABORATORIO_COLLEZIONENOTEIMPORTANTI_H
