#include "Projeto.h"

Projeto::Projeto(string nome, int maximoValor) : nome(nome), maximoValor(maximoValor) {
    this->quantidadeAtividades = 0;
    atividades = new Atividade*[maximoValor];

    this->quantidadePessoas = 0;
    pessoas = new Pessoa*[maximoValor];
}

Projeto::~Projeto() {
    for (int i = 0; i < quantidadeAtividades; i++) {
        delete atividades[i];
    }
    delete[] atividades;
}

int Projeto::getDuracao() {
    int duracao = 0;
    for (int i = 0; i < quantidadeAtividades; i++) {
        duracao += atividades[i]->getDuracao();
    }
    return duracao;
}

int Projeto::getQuantidadeAtividades() {
    return this->quantidadeAtividades;
}

Atividade** Projeto::getAtividades() {
    return this->atividades;
}

bool Projeto::adicionar(Atividade* a) {
    // Limite de atividades atingido
    if (quantidadeAtividades >= maximoValor)
        return false;

    // Atividade ja previamente adicionada
    for (int i = 0; i < quantidadeAtividades; i++) {
        if (atividades[i] == a)
            return false;
    }

    int cont = 0;
    for (int i = 0; i < this->quantidadePessoas; i++) {
        for (int j = 0; j < a->getQuantidade(); j++) {
            if (this->pessoas[i] == a->getPessoas()[j]) {
                cont++;
                cout << cont << endl;
            }
        }
    }
    if (cont != a->getQuantidade()) {
        return false;
    }

    // Atividade pode ser adicionada
    atividades[quantidadeAtividades] = a;
    quantidadeAtividades++;
    return true;
}

bool Projeto::adicionar(Pessoa* p) {
    if (this->quantidadePessoas >= this->maximoValor) {
        return false;
    }
    for (int i = 0; i < this->quantidadePessoas; i++) {
        if (p == this->pessoas[i]) {
            return false;
        }
    }
    this->pessoas[this->quantidadePessoas] = p;
    this->quantidadePessoas++;
    return true;
}

int Projeto::getQuantidadePessoas() {
    return this->quantidadePessoas;
}

Pessoa** Projeto::getPessoas() {
    return this->pessoas;
}

Atividade** Projeto::getAtividadesSemSupervisor(int& quantidade) {
    quantidade = 0;
    Atividade** atividadesSemSupervisor = new Atividade*[this->maximoValor];

    for (int i = 0; i < this->quantidadeAtividades; i++) {
        AtividadeComSupervisor* a1 = dynamic_cast<AtividadeComSupervisor*>(this->atividades[i]);
        if (a1 == NULL) {
            atividadesSemSupervisor[i] = this->atividades[i];
            quantidade++;
        }
    }
    return atividadesSemSupervisor;
}