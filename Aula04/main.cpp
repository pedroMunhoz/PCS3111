#include "Pessoa.h"
#include "Atividade.h"

int main() {
    Pessoa *p1 = new Pessoa;
    Pessoa *p2 = new Pessoa;
    Pessoa *p3 = new Pessoa;

    p1->setNome("Pedro");
    p1->setDisponivel(true);
    p1->setHorasDiarias(2);
    p2->setNome("Caique");
    p2->setDisponivel(true);
    p2->setHorasDiarias(1);
    p3->setNome("Jorge");
    p3->setDisponivel(true);
    p3->setHorasDiarias(4);

    Atividade *ativ1 = new Atividade;

    ativ1->setHorasNecessarias(10);
    ativ1->adicionar(p1);
    ativ1->adicionar(p2);
    ativ1->adicionar(p3);
    ativ1->setNome("EP1");

    ativ1->imprimir();

    return 0;
}
