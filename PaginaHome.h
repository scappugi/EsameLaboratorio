//
// Created by simon on 04/12/2022.
//

#ifndef ESAMELABORATORIO_PAGINAHOME_H
#define ESAMELABORATORIO_PAGINAHOME_H

#include <map>
#include "list"
#include "Observer.h"
#include "CollezioneNote.h"
#include "Subject.h"
#include "CollezioneNoteImportanti.h"

using namespace std;
class PaginaHome: public  Observer  {
public:
//lui dovrà implementare metodi uno molto importante è quello che consente di mettere la priorità nella nota.
    void addCollezione(CollezioneNote *collezioneNote); //aggiungo alla mappa una chiave che è il nome della mia collezione + gli passo la collezione stessa
    void addCollezioneNoteImportanti(CollezioneNote *collezioneNoteImportanti);
    void creaNuovaCollezione(const string& nomeCollezione);
    void creaNuovaCollezioneNoteImportanti(const string& nomeCollezione);
    bool verificaImportanza(Nota &collezioneNote); //verifica se una nota è settata come importante o no
    void aggiungiNotaACollezioneBase(Nota *nota, string NomeCollezione);
    void aggiungiNotaACollezioneImportanti(Nota *nota, string NomeCollezione);
    void setAltaPriorità(Nota *nota, string nomeCollezione); //permette di settare una nota con priorità pari a 1(High).

    ////metodi inerenti al pattern Observer

    virtual void update(string name ,int size); //inserisco dimensione attuale della lista come parametro di update
    virtual ~PaginaHome();
private:
    std::map<string , CollezioneNote * > collezioneNote;
    std::map<string ,CollezioneNote *> collezioneNoteImportanti; //preferisco differenziare le due sezioni
};


#endif //ESAMELABORATORIO_PAGINAHOME_H
