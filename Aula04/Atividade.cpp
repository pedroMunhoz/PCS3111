#include <iostream>
#include <cmath>
#include "Atividade.h"

void Atividade::setNome(string nome) {
    this->nome = nome;
}

void Atividade::setHorasNecessarias(int horasNecessarias) {
    this->horasNecessarias = horasNecessarias;
}

int Atividade::getHorasNecessarias() {
    return this->horasNecessarias;
}

int Atividade::getQuantidade() {
    return this->quantidade;
}

bool Atividade::adicionar(Pessoa *p) {
    if (this->quantidade == NUMERO_MAXIMO_VALORES || !p->isDisponivel()) {
        return false;
    } else {
        this->pessoas[quantidade] = new Pessoa;
        this->pessoas[quantidade] = p;
        p->setDisponivel(false);
        this->quantidade++;
        return true;
    }
}

int Atividade::getDuracao() {
    if (this->quantidade == 0) {
        return -1;
    } else {
        double soma = 0;
        for (int i = 0; i < this->quantidade; i++ ) {
            soma += this->pessoas[i]->getHorasDiarias();
        }
        return ceil((this->horasNecessarias)/soma);
    }
}

void Atividade::imprimir() {
    cout << this->nome << " - " << this->getDuracao() << " dias estimados" << endl;
    for (int i = 0; i < this->quantidade; i++ ) {
        this->pessoas[i]->imprimir();
    }

}
