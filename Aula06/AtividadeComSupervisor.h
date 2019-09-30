#ifndef ATIVIDADECOMSUPERVISOR_H
#define ATIVIDADECOMSUPERVISOR_H

#include "Atividade.h"
#include "Pessoa.h"

class AtividadeComSupervisor: public Atividade {
  public:
    AtividadeComSupervisor(string nome, int horasNecessarias, int maximoPessoas, Pessoa* supervisor);
    ~AtividadeComSupervisor();

    Pessoa* getSupervisor();
  
  private:
    Pessoa* supervisor;
};

#endif // ATIVIDADECOMSUPERVISOR_H
