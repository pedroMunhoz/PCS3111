#include "Pessoa.h"

double Pessoa::valorPorHoraPadrao = 8;

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias, int nusp) : Recurso(nome), FuncionarioUSP(nusp) {
    this->nome = nome;
    this->valorPorHora = valorPorHora;
    this->horasDiarias = horasDiarias;
    this->nusp = nusp;
    this->recebePadrao = false;
}

Pessoa::Pessoa(string nome, int horasDiarias, int nusp) : Recurso(nome), FuncionarioUSP(nusp) {
    this->nome = nome;
    this->horasDiarias = horasDiarias;
    this->nusp = nusp;
    this->valorPorHora = Pessoa::valorPorHoraPadrao;
    this->recebePadrao = true;
}

Pessoa::~Pessoa() {}

double Pessoa::getValorPorHora() {
    if(this->recebePadrao) {
        return Pessoa::valorPorHoraPadrao;
    } else {
        return this->valorPorHora;
    }
}

int Pessoa::getHorasDiarias() {
    return this->horasDiarias;
}

double Pessoa::getCusto(int dias) {
    if(this->recebePadrao) {
        return dias*this->horasDiarias*Pessoa::valorPorHoraPadrao;
    } else {
        return dias*this->horasDiarias*this->valorPorHora;
    }
}

bool Pessoa::recebeValorPadrao() {
    return this->recebePadrao;
}

void Pessoa::setValorPorHoraPadrao(double valor) {
    Pessoa::valorPorHoraPadrao = valor;
}

double Pessoa::getValorPorHoraPadrao() {
    return Pessoa::valorPorHoraPadrao;
}