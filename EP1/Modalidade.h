#ifndef MODALIDADE_H
#define MODALIDADE_H

#include "Equipe.h"

#include <string>

class Modalidade {
public:
    Modalidade(string nome, Equipe** participantes, int quantidade);
    ~Modalidade();

    string getNome();
    Equipe** getEquipes();
    int getQuantidadeDeEquipes();

    void setResultado(Equipe** ordem);
    int getPosicao(Equipe* participante);

    void imprimir();

private:
    string nome;

    Equipe** participantes;
    int quantidade;

    Equipe** resultado;
    bool definido;
};

#endif
