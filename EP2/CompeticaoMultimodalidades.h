#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H

#include "Competicao.h"
#include <list>
#include <vector>

class CompeticaoMultimodalidades: public Competicao {
public:
    CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
    virtual ~CompeticaoMultimodalidades();

    Tabela* getTabela();

    void adicionar(Modalidade* m);
    list<Modalidade*>* getModalidades();

    static void setPontuacao(vector<int>* pontos);
    static int getPontoPorPosicao(int posicao);

    void imprimir();
private:
    TabelaComPontos* tabela;
    list<Modalidade*>* modalidades = new list<Modalidade*>();
    static vector<int>* pontosComp;
};

#endif