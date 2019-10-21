#ifndef ERRO_RECURSOS_REPETIDOS_H
#define ERRO_RECURSOS_REPETIDOS_H

#include <stdexcept>
#include <string>
using namespace std;

class ErroRecursosRepetidos : public invalid_argument {
public:
    ErroRecursosRepetidos(string msg);
    virtual ~ErroRecursosRepetidos();
};

#endif