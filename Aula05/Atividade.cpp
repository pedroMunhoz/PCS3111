#include "Atividade.h"

Atividade::Atividade(string nome, int horasNecessarias, int maxValores) {
    this->nome = nome;
    this->horasNecessarias = horasNecessarias;
    this->quantidade = 0;
    this->maxValores = maxValores;

    this->pessoas = new Pessoa*[maxValores];
}

Atividade::~Atividade() {
    cout << "Atividade " << this->nome << " de tamanho " << this->maxValores << " com " << this->quantidade << " pessoa(s) destruuida" << endl;

    for (int i = 0; i < this->quantidade; i++) {
        delete this->pessoas[i];
    }

    delete[] pessoas;
}

string Atividade::getNome() {
    return this->nome;
}

int Atividade::getHorasNecessarias() {
    return this->horasNecessarias;
}

int Atividade::getQuantidade() {
    return this->quantidade;
}

int Atividade::getDuracao() {
    double totalHoras = 0;

    if (this->quantidade == 0) {
        return -1;
    }

    for (int i = 0; i < this->quantidade; i++) {
        totalHoras += this->pessoas[i]->getHorasDiarias();
    }
    return ceil(this->horasNecessarias/totalHoras);
}

Pessoa* Atividade::getLider() const {
    if (this->quantidade == 0) return NULL;

    Pessoa* lider = pessoas[0];

    for (int i = 0; i < this->quantidade; i++) {
        if (this->pessoas[i]->getHorasDiarias() > lider->getHorasDiarias()) {
            lider = this->pessoas[i];
        }
    }
    return lider;
}

bool Atividade::adicionar(Pessoa* p) {
    if (this->quantidade >= this->maxValores){
        return false;
    }

    this->pessoas[this->quantidade] = p;
    this->quantidade++;
    return true;
}

void Atividade::imprimir() {
    cout << this->nome << " - " << this->getDuracao() << " dia(s) estimado(s)" << endl;
    for (int i = 0; i < this->quantidade; i++)
        this->pessoas[i]->imprimir();
}
