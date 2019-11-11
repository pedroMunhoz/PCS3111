#include "Projeto.h"
#include <stdexcept>

Projeto::Projeto(string nome) : nome(nome) {}

Projeto::~Projeto() {
    for (unsigned int i = 0; i < atividades->size(); i++) {
        delete atividades->at(i);
    }
    delete[] atividades;
    delete[] pessoas;
}

int Projeto::getDuracao() {
    int duracao = 0;
    for (int i = 0; i < atividades->size(); i++) {
        duracao += atividades->at(i)->getDuracao();
    }
    return duracao;
}

vector<Atividade*>* Projeto::getAtividades() {
    return this->atividades;
}

void Projeto::adicionar(Atividade* a) {
    // Atividade ja previamente adicionada
    for (int i = 0; i < atividades->size(); i++) {
        if (atividades->at(i) == a)
            throw invalid_argument("Atividade ja adicionada");
    }

    // Pode ser adicionada
    atividades->push_back(a);
}

list<Pessoa*>* Projeto::getPessoas() {
    return this->pessoas;
}

void Projeto::adicionar(Pessoa* p) {
    // Pessoa ja previamente adicionada    
    list<Pessoa*>::iterator i = pessoas->begin();
    while (i != pessoas->end()) {
        if ( (*i) == p ) {
            throw invalid_argument("Pessoa ja adicionada");
        }
        i++;
    }

    // Pode ser adicionada
    pessoas->push_back(p);
}
