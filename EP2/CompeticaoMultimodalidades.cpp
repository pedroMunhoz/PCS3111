#include "CompeticaoMultimodalidades.h"
#include <stdexcept>
#include <iostream>

vector<int>* CompeticaoMultimodalidades::pontosComp = new vector<int>({13, 10, 8, 7, 5, 4, 3, 2, 1});

CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade): Competicao(nome, equipes, quantidade) {
    if (quantidade < 2) {
        throw new invalid_argument("Quantidade menor que 2");
    }
    this->nome = nome;
    this->equipes = equipes;
    this->quantidadeDeEquipes = quantidade;

    this->tabela = new TabelaComPontos(equipes, quantidade);
}

CompeticaoMultimodalidades::~CompeticaoMultimodalidades() {
    delete this->tabela;
    delete this->modalidades;
}

Tabela* CompeticaoMultimodalidades::getTabela() {
    if (this->modalidades->empty()) {
        throw new invalid_argument("Sem modalidades");
    }

    Equipe** ordem;

    list<Modalidade*>::iterator m = modalidades->begin();
     while(m != modalidades->end()) {
        if ((*m)->temResultado()) {
            ordem = (*m)->getTabela()->getEquipesEmOrdem();
            for (int i = 0; i < (*m)->getQuantidadeDeEquipes(); i++) {
                for (int j = 0; j < this->getQuantidadeDeEquipes(); j++) {
                    if (ordem[i] == this->equipes[j]) {
                        if ((unsigned int)i < CompeticaoMultimodalidades::pontosComp->size()) {
                            this->tabela->pontuar(this->equipes[j], (*CompeticaoMultimodalidades::pontosComp)[i]);
                        }
                    }
                }
            }
        }
        m++;
    }
    return tabela;
}

void CompeticaoMultimodalidades::adicionar(Modalidade* m) {
    this->modalidades->push_back(m);
}

list<Modalidade*>* CompeticaoMultimodalidades::getModalidades() {
    return this->modalidades;
}

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos) {
    CompeticaoMultimodalidades::pontosComp = pontos;
}

int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao) {
    if (posicao <= 0 || (unsigned int)posicao > CompeticaoMultimodalidades::pontosComp->size() ) {
        return 0;
    }
    posicao--;
    return (*CompeticaoMultimodalidades::pontosComp)[posicao];
}

void CompeticaoMultimodalidades::imprimir() {
    cout << this->nome << endl;
    this->getTabela()->imprimir();
}
