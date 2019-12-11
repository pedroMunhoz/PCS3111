#include "TabelaComOrdem.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TabelaComOrdem::TabelaComOrdem(Equipe** participantes, int quantidade): Tabela(participantes, quantidade) {
    if (quantidade < 2) {
        throw new invalid_argument("Quantidade de equipes menor que 2");
    }
    this->participantes = participantes;
    this->quantidade = quantidade;

    this->ordem = new Equipe*[quantidade];
    this->definido = false;
}

TabelaComOrdem::~TabelaComOrdem() {
    delete this->ordem;
}

void TabelaComOrdem::setResultado(Equipe** ordem) {
    this->ordem = ordem;
    this->definido = true;
}

int TabelaComOrdem::getPosicao(Equipe* participante) {
    if (!this->definido) {
        throw new logic_error("Nao definido");
    }

    int cont = 0;
    for (int i = 0; i < this->quantidade; i++) {
        if (this->participantes[i] == participante) {
            cont++;
        }
    }
    if (cont == 0) {
        throw new invalid_argument("Pessoa nao esta na tabela");
    }

    for (int i = 0; i < this->quantidade; i++) {
        if (this->ordem[i] == participante) {
            return i + 1;
        }
    }
    return 0;
}

Equipe** TabelaComOrdem::getEquipesEmOrdem() {
    if (!this->definido) {
        throw new logic_error("Nao definido");
    }
    return this->ordem;
}

void TabelaComOrdem::imprimir() {
    if (!this->definido) {
        for (int i = 0; i < this->quantidade; i++) {
            cout << "\t" << this->participantes[i]->getNome() << endl;
        }
    } else {
        for (int i = 0; i < this->quantidade; i++) {
            cout << "\t" << i + 1 << "o " << this->ordem[i]->getNome() << endl;
        }
    }
}