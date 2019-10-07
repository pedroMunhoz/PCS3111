#ifndef PESSOA_H
#define PESSOA_H

#include "Recurso.h"
#include "FuncionarioUSP.h"

// Faca os includes necessarios
#include<string>
using namespace std;

class Pessoa :public Recurso, public FuncionarioUSP {
public:
    Pessoa(string nome, double valorPorHora, int horasDiarias, int nusp);
    Pessoa(string nome, int horasDiarias, int nusp);
    virtual ~Pessoa();

    virtual double getValorPorHora();
    virtual int getHorasDiarias();

    double getCusto(int dias);

    virtual bool recebeValorPadrao();
    static void setValorPorHoraPadrao(double valor);
    static double getValorPorHoraPadrao();
private:
    double valorPorHora;
    int horasDiarias;

    static double valorPorHoraPadrao;
    bool recebePadrao;
};

#endif // PESSOA_H
