//
// Created by simon on 04/12/2022.
//

#ifndef ESAMELABORATORIO_PAGINAHOME_H
#define ESAMELABORATORIO_PAGINAHOME_H

#include <map>
#include "list"
#include "Observer.h"
#include "CollezioneNote.h"
using namespace std;
class PaginaHome: public  Observer  {
public:
//lui dovrà implementare metodi uno molto importante è quello che consente di mettere la priorità nella nota.
    void addCollezione(CollezioneNote *collezioneNote); //aggiungo alla mappa una chiave che è il nome della mia collezione + gli passo la collezione stessa

//metodi inerenti al pattern Observer
    virtual void update(string name ,int size); //inserisco dimensione attuale della lista come parametro di update
    virtual void attach();
    virtual void detach();

private:
    std::map<string , CollezioneNote * > collezioneNote;
};


#endif //ESAMELABORATORIO_PAGINAHOME_H
