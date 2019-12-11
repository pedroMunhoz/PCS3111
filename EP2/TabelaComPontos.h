#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H

#include "Tabela.h"
#include "Equipe.h"

class TabelaComPontos:public Tabela{
public:
    TabelaComPontos (Equipe** participantes, int quantidade);
    virtual ~TabelaComPontos();

    int getPosicao(Equipe* participante);
    Equipe** getEquipesEmOrdem();
    
    int getPontos (Equipe* participante);
    void pontuar (Equipe* participante, int pontos);

    void imprimir();
private:
    bool definido;
    int* pontos;
};

#endif