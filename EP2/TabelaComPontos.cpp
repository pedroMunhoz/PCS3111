#include "TabelaComPontos.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade): Tabela(participantes, quantidade) {
    if (quantidade < 2) {
        throw new invalid_argument("Quantidade de participantes menor que 2");
    }
    this->participantes = participantes;
    this->quantidade = quantidade;

    this->pontos = new int[quantidade];
    for (int i = 0; i < quantidade; i++) {
        this->pontos[i] = 0;
    }
    this->definido = false;
}

TabelaComPontos::~TabelaComPontos() {
    delete[] pontos;
}

int TabelaComPontos::getPontos(Equipe* participante) {
    for (int i = 0; i < this->quantidade; i++) {
        if (this->participantes[i] == participante) {
            return this->pontos[i];
        }
    }
    throw new invalid_argument("Equipe nao encontrada");
}

void TabelaComPontos::pontuar(Equipe* participante, int pontos) {
    int cont = 0;
    for (int i = 0; i < this->quantidade; i++) {
        if (this->participantes[i] == participante) {
            this->pontos[i] += pontos;
            cont++;
        }
    }
    if (cont == 0) {
        throw new invalid_argument("Equipe nao encontrada");
    }
    this->definido = true;
}

int TabelaComPontos::getPosicao(Equipe* participante) {
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

    int ordem[this->quantidade];
    for (int i = 0; i < this->quantidade; i++) {
        ordem[i] = 1;
    }

    for (int i = 0; i < this->quantidade; i++) {
        for (int j = 0; j < this->quantidade; j++) {
            if (this->pontos[i] < this->pontos[j]) {
                ordem[i]++;
            }
        }
    }

    for (int i = 0; i < this->quantidade; i++) {
        if (this->participantes[i] == participante) {
            return ordem[i];
        }
    }
    return 0;
}

Equipe** TabelaComPontos::getEquipesEmOrdem() {
    if (!this->definido) {
        throw new logic_error("Nao definido");
    }
    this->equipesEmOrdem = this->participantes;
    for (int i = 0; i < this->quantidade; i++) {
        for (int j = i; j < this->quantidade; j++) {
            if (pontos[j] > pontos[i]) {
                int temp = pontos[i];
                pontos[i] = pontos[j];
                pontos[j] = temp;

                Equipe* tempEq = this->equipesEmOrdem[i];
                this->equipesEmOrdem[i] = this->equipesEmOrdem[j];
                this->equipesEmOrdem[j] = tempEq;
            }
        }
    }
    return equipesEmOrdem;
}

void TabelaComPontos::imprimir() {
    if (!this->definido) {
        for (int i = 0; i < this->quantidade; i++) {
            cout << "\t" << this->participantes[i]->getNome() << endl;
        }
    } else {
        for (int i = 0; i < this->quantidade; i++) {
            cout << "\t" << this->getPosicao(this->getEquipesEmOrdem()[i]) << "o " << this->getEquipesEmOrdem()[i]->getNome() << " (" << this->pontos[i] << " pontos )" << endl;
        }
    }
}
