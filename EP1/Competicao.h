#ifndef COMPETICAO_H
#define COMPETICAO_H

#include "Equipe.h"
#include "Tabela.h"
#include "Modalidade.h"

#include <string>
using namespace std;

class Competicao {
public:
    Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades);
    ~Competicao();

    string getNome();

    Equipe** getEquipes();
    int getQuantidadeDeEquipes();

    bool adicionar(Modalidade* m);
    Modalidade** getModalidades();
    int getQuantidadeDeModalidades();

    Tabela* getTabela();

    void imprimir();
private:
    string nome;

    Equipe** equipes;
    Modalidade** modalidades;
    int* pontos;

    int quantidadeDeEquipes;
    int quantidadeDeModalidades;
    int maximoDeModalidades;

    Tabela* tabela;

};

#endif