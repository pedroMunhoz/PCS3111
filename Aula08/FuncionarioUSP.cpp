#include "FuncionarioUSP.h"

FuncionarioUSP::FuncionarioUSP(int nusp) {
    this->nusp = nusp;
}

FuncionarioUSP::~FuncionarioUSP() {}

int FuncionarioUSP::getNusp() {
    return this->nusp;
}