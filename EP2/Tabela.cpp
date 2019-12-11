#include "Tabela.h"

#include <iostream>
#include <stdexcept>

Tabela::Tabela(Equipe **participantes, int quantidade) {
    if (quantidade < 2) {
        throw new invalid_argument("Quantidade menor que 2");;
    }
    this->participantes = participantes;
    this->quantidade = quantidade;
}

Tabela::~Tabela() {}

int Tabela::getQuantidadeDeEquipes() {
    return this->quantidade;;
}