#ifndef TABELA_H
#define TABELA_H

#include "Equipe.h"

#include <string>
using namespace std;

class Tabela {
public:
    Tabela(Equipe** participantes, int quantidade);
    ~Tabela();

    void pontuar(Equipe* participante, int pontos);
    int getPontos(Equipe* participante);
    int getPosicao(Equipe* participante);

    void imprimir();
private:
    Equipe** participantes;
    int quantidade;
    int* pontos;
};

#endif