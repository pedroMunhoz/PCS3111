#include "Pessoa.h"
#include "PersistenciaPessoa.h"
#include <iostream>

using namespace std;

int main() {
    Pessoa *p1 = new Pessoa("Pedro", 20, 4);
    Pessoa *p2 = new Pessoa("Carlinhos", 20, 1);
    PersistenciaPessoa *pers = new PersistenciaPessoa("Persistencia.txt");
    pers->inserir(p1);
    pers->inserir(p2);

    int quantidade = 0;
    Pessoa** pessoas = pers->obter(quantidade);
    cout << pessoas[0]->getNome();

    for (int i = 0; i < 2; i++) {
            if (pessoas[i] != NULL) {
                    cout << pessoas[i]->getNome() << " - " << pessoas[i]->getHorasDiarias() << " - " << pessoas[i]->getValorPorHora() << endl;
            }
    }
    return 0;
}
