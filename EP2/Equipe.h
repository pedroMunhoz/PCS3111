#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>

using namespace std;

class Equipe {
public:
    Equipe(string nome);
    virtual ~Equipe();

    virtual string getNome();
    virtual void imprimir();
private:
    string nome;
};

#endif