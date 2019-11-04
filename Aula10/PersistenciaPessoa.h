#ifndef PERSISTENCIAPESSOA_H
#define PERSISTENCIAPESSOA_H

#include <string>
#include "Pessoa.h"
#include <iostream>

using namespace std;

class PersistenciaPessoa {
public:
    PersistenciaPessoa(string arquivo);
    virtual ~PersistenciaPessoa();

    void inserir(Pessoa* p);

    Pessoa** obter(int& quantidade);
private:
    string arquivo;
};
#endif // PERSISTENCIAPESSOA_H