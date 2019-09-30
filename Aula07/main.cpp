#include "Pessoa.h"
#include "Atividade.h"
#include "AtividadeComSupervisor.h"
#include "Projeto.h"

#include <iostream>

using namespace std;

int main() {
    Pessoa* p1 = new Pessoa("Pedro", 4);
    Pessoa* p2 = new Pessoa("Caique",3);
    Pessoa* p3 = new Pessoa("Jorge", 6);
    Pessoa* p4 = new Pessoa("Pessoa", 2);

    Atividade* a1 = new Atividade("EP1", 18, 3);

    a1->adicionar(p1);
    a1->adicionar(p2);
    a1->adicionar(p3);

    Projeto* proj = new Projeto("PCS3111", 3);

    proj->adicionar(p1);
    proj->adicionar(p2);
    
    proj->adicionar(a1);

    return 0;
}
