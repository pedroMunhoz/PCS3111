#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include "Pessoa.h"
#include <cmath>

class Atividade {
private:
    string nome;
    int horasNecessarias;
    int quantidade;

    int maxValores;

    Pessoa** pessoas;

public:
    Atividade(string nome, int horasNecessarias, int maxValores);
    ~Atividade();

    string getNome();
    int getHorasNecessarias();
    int getQuantidade();
    int getDuracao();

    Pessoa* getLider() const; 

    bool adicionar(Pessoa* p);
    void imprimir();
};

#endif // ATIVIDADE_H
