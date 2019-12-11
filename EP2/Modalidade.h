#ifndef MODALIDADE_H
#define MODALIDADE_H

#include "Equipe.h"
#include "TabelaComOrdem.h"
#include "TabelaComPontos.h"

#include <string>
using namespace std;

class Modalidade {
public:
    Modalidade(string nome, Equipe** participantes, int quantidade);
    virtual ~Modalidade();

    virtual string getNome();
    virtual Equipe** getEquipes();
    virtual int getQuantidadeDeEquipes();

    virtual void setResultado(Equipe** ordem);
    virtual bool temResultado();
    virtual TabelaComOrdem* getTabela();

    virtual void imprimir();

private:
    string nome;

    Equipe** participantes;
    int quantidade;

    TabelaComOrdem* tabela;

    bool temRes;
};

#endif
