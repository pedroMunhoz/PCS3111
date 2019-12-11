#include "Competicao.h"

#include <iostream>
#include <stdexcept>

Competicao::Competicao(string nome, Equipe **equipes, int quantidade) {
    if (quantidade < 2) {
        throw new invalid_argument("Quantidade menor que 2");
    }
    this->nome = nome;
    this->equipes = equipes;
    this->quantidadeDeEquipes = quantidade;
}

Competicao::~Competicao() {}

string Competicao::getNome() {
    return this->nome;
}

int Competicao::getQuantidadeDeEquipes() {
    return this->quantidadeDeEquipes;
}

Equipe** Competicao::getEquipes() {
    return this->equipes;
}
/*
void Competicao::imprimir() {
    cout << this->nome << endl;
    this->tabela->imprimir();
}*/