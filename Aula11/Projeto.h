#ifndef PROJETO_H
#define PROJETO_H

#include <string>
#include "Atividade.h"
#include "Pessoa.h"
#include <vector>
#include <list>

using namespace std;

class Projeto {
public:
    Projeto(string nome);
    ~Projeto();

    int getDuracao();
    vector<Atividade*>* getAtividades();
    list<Pessoa*>* getPessoas();

    void adicionar(Atividade* a);
    void adicionar(Pessoa* p);
private:
    string nome;
    list<Pessoa*>* pessoas = new list<Pessoa*>();
    vector<Atividade*>* atividades = new vector<Atividade*>();
};

#endif // PROJETO_H
