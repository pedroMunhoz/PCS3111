#include "Atividade.h"
#include "ErroRecursosRepetidos.h"


Atividade::Atividade(string nome, int horasNecessarias, int maximoPessoas) : nome(nome), horasNecessarias(horasNecessarias), maximoPessoas(maximoPessoas) {
    if (horasNecessarias <= 0 || maximoPessoas <= 0) {
        throw new invalid_argument ("horasNecessarias ou maximoPessoas menor ou igual a zero");
    }
    this->pessoas = new Pessoa*[maximoPessoas];
    this->quantidade = 0;
}

Atividade::~Atividade() {
    for (int i = 0; i < quantidade; i++) {
        delete pessoas[i];
    }
    delete[] pessoas;
}

int Atividade::getHorasNecessarias() {
    return horasNecessarias;
}

void Atividade::adicionar(Pessoa* p) {
    if (p == NULL) {
        throw new invalid_argument("Pessoa eh NULL");
    }
    for (int i = 0; i < this->quantidade; i++) {
        if (p == this->pessoas[i]) {
            throw new ErroRecursosRepetidos("Pessoa ja adicionada");
        }
    }

    if (quantidade < maximoPessoas) {
        pessoas[quantidade++] = p;
    } else {
        throw new overflow_error ("vetor pessoas cheio");
    }
}

int Atividade::getDuracao() {
    double horas = 0;

    if (quantidade == 0)
        throw new logic_error ("nao ha pessoas na Atividade");

    for (int i = 0; i < quantidade; i++)
        horas += pessoas[i]->getHorasDiarias();

    return ceil(horasNecessarias/horas);
}

void Atividade::imprimir() {
    cout << nome << " - " << getDuracao() << " dias estimados" << endl;
    for (int i = 0; i < quantidade; i++)
        pessoas[i]->imprimir();
    cout << endl;
}

