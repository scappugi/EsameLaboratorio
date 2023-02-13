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

    ///metodi per aggiungere
    void addCollezione(CollezioneNote *collezioneNote); //aggiungo alla mappa una chiave che è il nome della mia collezione + gli passo la collezione stessa
    void addCollezioneNoteImportanti(CollezioneNoteImportanti *collezioneNoteImportanti);
    bool aggiungiNotaACollezioneBase(Nota &nota, const string& NomeCollezione);
    void aggiungiNotaACollezioneImportanti(Nota &nota, const string& NomeCollezione);

    ///metodi per creare
    void creaNuovaCollezione(const string& nomeCollezione);
    void creaNuovaCollezioneNoteImportanti(const string& nomeCollezione);

    ///metodi get
    bool verificaImportanza(const Nota &nomeNota); //verifica se una nota è settata come importante o no
    bool verificaBloccoNota(const Nota &nomeNota);

    ///metodi set
    void setAltaPriorita(Nota &nota, const string& nomeCollezione); //permette di settare una nota con priorità pari a 1(High).
    void setBassaPriorita(Nota &nota, const string& nomeCollezione);
    void setBloccoNota(Nota &nota, const string &nomeCollezione);
    void setBloccaTutteLeNote(const string &nomeCollezione); //blocca tutte le note di nomeCollezione

    ///metodi per eliminare
    bool eliminaNota(const string& nomeCollezione, Nota &nota ); //gestisce il caso di errore con una eccezione (caso in cui la nota/colezione siano bloccate)
    bool eliminaCollezione(const string& nomeCollezione);

    ///metodi per cercare e spostare
    bool contieneCollezioni(const string& nomeCollezione);
    bool contieneNote(const Nota &nota,const string& nomeCollezione);
    void spostaNota(Nota &nota, const string& collezioneIniziale, const string& collezionefinale);

    ////metodi inerenti al pattern Observer
    virtual void update(const string &name ,int size) override; //inserisco dimensione attuale della lista come parametro di update
    virtual ~PaginaHome()=default;
    
private:
    std::map<string ,CollezioneNote * > collezioneNote;
    std::map<string ,CollezioneNoteImportanti * > collezioneNoteImportanti; //preferisco differenziare le due sezioni
};


#endif //ESAMELABORATORIO_PAGINAHOME_H
