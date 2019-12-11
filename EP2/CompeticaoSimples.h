#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H

#include "Competicao.h"

class CompeticaoSimples:public Competicao {
public:
    CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m);
    virtual ~CompeticaoSimples();
    
    Modalidade* getModalidade();

    Tabela* getTabela();
    
    void imprimir();
private:
    TabelaComOrdem* tabela;
    Modalidade* modalidade;
};

#endif