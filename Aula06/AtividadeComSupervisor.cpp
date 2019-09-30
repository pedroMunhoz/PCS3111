#include "AtividadeComSupervisor.h"

AtividadeComSupervisor::AtividadeComSupervisor(string nome, int horasNecessarias, int maximoPessoas, Pessoa* supervisor) : Atividade(nome, horasNecessarias, maximoPessoas) {
    this->nome = nome;
    this->horasNecessarias = horasNecessarias + 1 + horasNecessarias/4;
    this->maximoPessoas = maximoPessoas;
    this->supervisor = supervisor;

    this->pessoas = new Pessoa*[maximoPessoas];
}

AtividadeComSupervisor::~AtividadeComSupervisor() {
    for (int i = 0; i < this->quantidade; i++) {
        delete pessoas[i];
    }
    delete this->supervisor;
}

Pessoa *AtividadeComSupervisor::getSupervisor() {
    return this->supervisor;
}