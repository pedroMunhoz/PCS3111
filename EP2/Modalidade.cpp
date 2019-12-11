#include "Modalidade.h"

#include <iostream>
#include <stdexcept>

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade) {
    this->nome = nome;
    if (quantidade < 2){
        throw new invalid_argument("Quantidade de Equipes menor que 2");
    }
    this->quantidade = quantidade;

    this->participantes = participantes;

    this->temRes = false;

    this->tabela = new TabelaComOrdem(participantes, quantidade);
}

Modalidade::~Modalidade() {
    delete this->tabela;
}

string Modalidade::getNome() {
    return this->nome;
}

Equipe** Modalidade::getEquipes() {
    return this->participantes;
}

int Modalidade::getQuantidadeDeEquipes() {
    return this->quantidade;
}

void Modalidade::setResultado(Equipe** ordem) {
    this->tabela->setResultado(ordem);
    this->temRes = true;
}

bool Modalidade::temResultado() {
    return this->temRes;
}

TabelaComOrdem* Modalidade::getTabela() {
    return this->tabela;
}

void Modalidade::imprimir() {
    cout << "Modalidade: " << this->nome << endl;
    this->tabela->imprimir();
}
