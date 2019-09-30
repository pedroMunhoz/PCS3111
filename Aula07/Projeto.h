#ifndef PROJETO_H
#define PROJETO_H

#include <string>
#include "Atividade.h"
#include "AtividadeComSupervisor.h"
#include "Pessoa.h"

using namespace std;

class Projeto {
public:
    Projeto(string nome, int maximoValor);
    ~Projeto();

    int getDuracao();
    int getQuantidadeAtividades();
    int getQuantidadePessoas();
    Atividade** getAtividades();
    Pessoa** getPessoas();
    Atividade** getAtividadesSemSupervisor(int& quantidade);

    bool adicionar(Atividade* a);
    bool adicionar(Pessoa* p);

private:
    string nome;
    int maximoValor;

    int quantidadeAtividades;
    Atividade** atividades;

    int quantidadePessoas;
    Pessoa** pessoas;
};

#endif // PROJETO_H
