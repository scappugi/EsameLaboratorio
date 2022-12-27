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

    void addCollezione(CollezioneNote *collezioneNote); //aggiungo alla mappa una chiave che è il nome della mia collezione + gli passo la collezione stessa
    void addCollezioneNoteImportanti(CollezioneNoteImportanti *collezioneNoteImportanti);
    void creaNuovaCollezione(const string& nomeCollezione);
    void creaNuovaCollezioneNoteImportanti(const string& nomeCollezione);
    bool verificaImportanza(Nota &collezioneNote); //verifica se una nota è settata come importante o no
    void aggiungiNotaACollezioneBase(Nota *nota, string NomeCollezione);
    void aggiungiNotaACollezioneImportanti(Nota *nota, string NomeCollezione);
    void setAltaPriorità(Nota *nota, string nomeCollezione); //permette di settare una nota con priorità pari a 1(High).
    void setBassaPriorità(Nota *nota, string nomeCollezione);
    void setBloccoNota(Nota *nota, string nomeCollezione);
    void setBloccaTutteLeNote(string nomeCollezione); //blocca tutte le note di nomeCollezione
    void spostaNota(Nota *nota, string collezioneIniziale, string collezionefinale);
    void eliminaNota(Nota *nota, string nomeCollezione); //gestisce il caso di errore con una eccezione (caso in cui la nota/colezione siano bloccate)
    void eliminaCollezione(string nomeCollezione);


    ////metodi inerenti al pattern Observer

    virtual void update(string name ,int size) override; //inserisco dimensione attuale della lista come parametro di update
    virtual ~PaginaHome();
    
private:
    std::map<string , CollezioneNote * > collezioneNote;
    std::map<string ,CollezioneNoteImportanti *> collezioneNoteImportanti; //preferisco differenziare le due sezioni
};


#endif //ESAMELABORATORIO_PAGINAHOME_H
