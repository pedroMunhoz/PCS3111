#include "Pessoa.h"

#include <iostream>

void Pessoa::setNome (string nome) {
  this->nome = nome;
}

void Pessoa::setDisponivel (bool disponivel) {
  this->disponivel = disponivel;
}

void Pessoa::setHorasDiarias (int horasDiarias) {
  this->horasDiarias = horasDiarias;
}

bool Pessoa::isDisponivel() {
  return disponivel;
}

int Pessoa::getHorasDiarias() {
  return horasDiarias;
}

void Pessoa::imprimir() {
  cout << nome << ": ";
  if (!disponivel) {
    cout << "in";
  }
  cout << "disponivel - " << horasDiarias << " hora(s) por dia" << endl;
}
