#include "Equipe.h"

#include <iostream>

Equipe::Equipe(string nome) {
    this->nome = nome;
}

Equipe::~Equipe() {
}

string Equipe::getNome() {
    return this->nome;
}

void Equipe::imprimir() {
    cout << "Equipe " << this->nome << endl;
}