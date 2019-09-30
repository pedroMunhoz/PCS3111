#include "Projeto.h"

Projeto::Projeto(string nome, int maximoAtividades) {
    this->nome = nome;
    this->maximoAtividades = maximoAtividades;

    this->atividades = new Atividade*[maximoAtividades];

    this->quantidade = 0;
}

Projeto::~Projeto() {
    for (int i = 0; i < quantidade; i++) {
        delete this->atividades[i];
    }
}

int Projeto::getDuracao() {
    int soma = 0;
    for (int i = 0; i < this->quantidade; i++) {
        soma += this->atividades[i]->getDuracao();
    }
    return soma;
}

int Projeto::getQuantidade() {
    return this->quantidade;
}

bool Projeto::adicionar(Atividade* a) {
    for (int i = 0; i < this->quantidade; i++) {
        if ( a == atividades[i]) {
            return false;
        }
    }
    if (this->quantidade == this->maximoAtividades) {
        return false;
    }
    this->atividades[quantidade] = a;
    this->quantidade++;
    return true;
}