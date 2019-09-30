 #ifndef ATIVIDADE_H
 #define ATIVIDADE_H

#define NUMERO_MAXIMO_VALORES 10

#include <string>
using namespace std;

#include "Pessoa.h"

class Atividade {
private:
    string nome;
    int horasNecessarias;
    int quantidade;
    Pessoa *pessoas[NUMERO_MAXIMO_VALORES];
public:
  void setNome(string nome);
  void setHorasNecessarias(int horasNecessarias);
  int getHorasNecessarias();
  int getQuantidade();

  bool adicionar(Pessoa* p);
  int getDuracao();
  void imprimir();
};

 #endif
