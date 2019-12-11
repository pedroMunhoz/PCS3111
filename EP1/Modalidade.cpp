#include "Modalidade.h"

#include <iostream>

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade) {
    this->nome = nome;
    this->quantidade = quantidade;

    this->participantes = participantes;

    this->resultado = new Equipe*[quantidade];
    this->definido = false;
}

Modalidade::~Modalidade() {}

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
    this->resultado = ordem;
    this->definido = true;
}

int Modalidade::getPosicao(Equipe *participante) {
    if (!this->definido) {
        return -1;
    }

    for (int posicao = 0; posicao < this->quantidade; posicao++) {
        if (this->resultado[posicao] == participante) {
            return posicao+1;
        }
    }

    return -1;
}

void Modalidade::imprimir() {
    if (!this->definido) {
        cout << "Modalidade: " << this->nome << endl
             << "Participantes: " << endl;
        for (int i = 0; i < this->quantidade; i++) {
            cout << "\t" << this->participantes[i]->getNome() << endl;
        }
    } else {
        cout << "Modalidade: " << this->nome << endl
             << "Resultado: " << endl;
        for (int i = 0; i < this->quantidade; i++) {
            cout << "\t" << i+1 << "o " << this->resultado[i]->getNome() << endl;
        }
    }
}
