#ifndef TABELACOMORDEM_H
#define TABELACOMORDEM_H

#include "Tabela.h"
#include "Equipe.h"

class TabelaComOrdem:public Tabela{
public:
    TabelaComOrdem (Equipe** participantes, int quantidade);
    virtual ~TabelaComOrdem();

    int getPosicao(Equipe* participante);
    Equipe** getEquipesEmOrdem();
 
    void setResultado (Equipe** ordem);

    void imprimir();
private:
    bool definido;
    Equipe** ordem;
};

#endif