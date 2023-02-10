//
// Created by simon on 04/12/2022.
//

#ifndef ESAMELABORATORIO_NOTA_H
#define ESAMELABORATORIO_NOTA_H


#include <string>

using namespace std;

class Nota {
public:
    explicit
    Nota(string nome) : nomeNota(nome) {}

    Nota(string nome, string descrizione) : nomeNota(nome), descrizioneNota(descrizione) {}

    ~Nota() = default;

    string getNomeNota() const;

    void setNomeNota(const string &nomeNota);

    string getDescrizioneNota() const;

    void setDescrizioneNota(const string &descrizioneNota);

    bool getBlocco() const; //blocca modifica e cancellazione

    void setBlocco(bool blocco);

    bool getPriorita() const;

    void setPriorita(bool priorita);

    bool isInseritoInUnaLista() const;

    void setInseritoInUnaLista(bool inseritoInUnaLista);

    bool isInseritoInUnaListaHpriorita() const;

    void setInseritoInUnaListaHpriorita(bool inseritoInUnaListaHpriorita);

    ///sovraccaricamento operatore ==
     bool operator==(const Nota &nota);
    Nota &operator=(const Nota &nota);

private:
    string nomeNota;
    string descrizioneNota;
    bool blocco = false;
    bool priorita = false;
    bool inseritoInUnaLista = false;
    bool inseritoInUnaListaHpriorita = false;
};


#endif //ESAMELABORATORIO_NOTA_H
