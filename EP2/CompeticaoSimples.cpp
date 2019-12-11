#include "CompeticaoSimples.h"
#include <iostream>
#include <stdexcept>

CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m): Competicao(nome, equipes, quantidade) {
    if (quantidade < 2) {
        throw new invalid_argument("Quantidade menor que 2");
    }
    this->nome = nome;
    this->equipes = equipes;
    this->quantidadeDeEquipes = quantidade;
    this->modalidade = m;

    this->tabela = this->modalidade->getTabela();
}

CompeticaoSimples::~CompeticaoSimples() {}

Tabela* CompeticaoSimples::getTabela() {
    return this->tabela;
}

Modalidade* CompeticaoSimples::getModalidade() {
    return this->modalidade;
}

void CompeticaoSimples::imprimir() {
    cout << this->nome << endl;
    this->tabela->imprimir();
}