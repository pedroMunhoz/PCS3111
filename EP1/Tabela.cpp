#include "Tabela.h"

#include <iostream>

Tabela::Tabela(Equipe **participantes, int quantidade) {
    this->participantes = participantes;
    this->quantidade = quantidade;

    this->pontos = new int[quantidade];

    for ( int i = 0; i < quantidade; i++) {
        this->pontos[i] = 0;
    }
}

Tabela::~Tabela() {
    delete[] pontos;
}

void Tabela::pontuar(Equipe *participante, int pontos) {
    for ( int i=0; i<this->quantidade; i++) {
        if (this->participantes[i] == participante) {
            this->pontos[i] += pontos;
        }
    }
}

int Tabela::getPontos(Equipe *participante) {
    for (int i = 0; i < this->quantidade; i++) {
        if (this->participantes[i] == participante) {
            return this->pontos[i];
        }
    }
    return -1;
}

int Tabela::getPosicao(Equipe *participante) {
    int index = 0;
    int pos = 1;

    for (int i = 0; i < this->quantidade; i++) {
        if (this->participantes[i] == participante) {
            index = i;
        }
    }
    for (int i = 0; i < this->quantidade; i++) {
        if (this->pontos[index] < this->pontos[i] && i!=index) {
            pos++;
        }
    }
    return pos;
}

void Tabela::imprimir() {
    for (int i = 0; i < this->quantidade; i++) {
        cout << this->participantes[i]->getNome() << " - " << this->pontos[i] << " pontos - (" << this->getPosicao(participantes[i]) << "o)" << endl;
    }
}

