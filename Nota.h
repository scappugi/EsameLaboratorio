//
// Created by simon on 04/12/2022.
//

#ifndef ESAMELABORATORIO_NOTA_H
#define ESAMELABORATORIO_NOTA_H


#include <string>
using namespace  std;

class Nota {
public: Nota (string nome, string descrizione=""): nomeNota(nome), descrizioneNota(descrizione){}
private:
    string nomeNota;
    string descrizioneNota;
    bool blocco=0;
    bool priorita=0;
    bool inseritoInUnaLista=0;
    bool inseritoInUnaListaHpriorita=0;
public:
    const string getNomeNota() const;

    void setNomeNota(const string &nomeNota);

    const string &getDescrizioneNota() const;

    void setDescrizioneNota(const string &descrizioneNota);

    bool getBlocco() const; //blocca modifica e cancellazione

    void setBlocco(bool blocco);

    bool getPriorita() const;

    void setPriorita(bool priorita);

    bool isInseritoInUnaLista() const;

    void setInseritoInUnaLista(bool inseritoInUnaLista);

    bool isInseritoInUnaListaHpriorita() const;

    void setInseritoInUnaListaHpriorita(bool inseritoInUnaListaHpriorita);

    virtual ~Nota()=default;
};


#endif //ESAMELABORATORIO_NOTA_H
