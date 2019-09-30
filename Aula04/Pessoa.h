#ifndef PESSOA_H
#define PESSOA_H

#include <string>

using namespace std;

class Pessoa {
private:
  string nome;
  bool disponivel;
  int horasDiarias;

public:
  void setNome(string nome);
  void setDisponivel(bool disponivel);
  void setHorasDiarias (int horasDiarias);

  bool isDisponivel();
  int getHorasDiarias();

  void imprimir();
};

#endif
