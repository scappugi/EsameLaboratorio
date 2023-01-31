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
    void aggiungiNotaACollezioneBase(Nota *nota, const string& NomeCollezione);
    void aggiungiNotaACollezioneImportanti(Nota *nota, const string& NomeCollezione);
    void setAltaPriorita(Nota *nota, const string& nomeCollezione); //permette di settare una nota con priorità pari a 1(High).
    void setBassaPriorita(Nota *nota, const string& nomeCollezione);
    void setBloccoNota(Nota *nota, const string &nomeCollezione);
    void setBloccaTutteLeNote(const string &nomeCollezione); //blocca tutte le note di nomeCollezione
    void spostaNota(Nota *nota, const string& collezioneIniziale, const string& collezionefinale);
    void eliminaNota(const string& nomeCollezione, Nota *nota ); //gestisce il caso di errore con una eccezione (caso in cui la nota/colezione siano bloccate)
    void eliminaCollezione(const string& nomeCollezione);
    bool contieneCollezioni(const string& nomeCollezione);



    ////metodi inerenti al pattern Observer

    virtual void update(string name ,int size) override; //inserisco dimensione attuale della lista come parametro di update
    virtual ~PaginaHome()=default;
    
private:
    std::map<string , CollezioneNote * > collezioneNote;
    std::map<string ,CollezioneNoteImportanti *> collezioneNoteImportanti; //preferisco differenziare le due sezioni
};


#endif //ESAMELABORATORIO_PAGINAHOME_H
