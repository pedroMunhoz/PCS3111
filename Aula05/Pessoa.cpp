#include "Pessoa.h"

Pessoa::Pessoa(string nome, int horasDiarias) {
    this->horasDiarias = horasDiarias;
    this->nome = nome;
}

Pessoa::~Pessoa() {
    cout << " Pessoa " << this->nome << " destruida" << endl;
}

string Pessoa::getNome() {
    return this->nome;
}

int Pessoa::getHorasDiarias() {
    return this->horasDiarias;
}

void Pessoa::imprimir() {
    cout << this->nome << ": " << this->horasDiarias << " hora(s) por dia" << endl;
}
