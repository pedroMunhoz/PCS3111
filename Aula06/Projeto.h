#ifndef PROJETO_H
#define PROJETO_H

#include "Atividade.h"

class Projeto {
  public:
    Projeto(string nome, int maximoAtividades);
    ~Projeto();

    int getDuracao();
    int getQuantidade();
    bool adicionar(Atividade* a);

  private:
    string nome;
    int maximoAtividades;
    int quantidade;

    Atividade** atividades;
};

#endif // PROJETO_H
