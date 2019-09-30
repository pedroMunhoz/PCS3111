#include <iostream>

using namespace std;

int calculaSalarioMensal(int tipo, int horasDiarias) {
    int salario;
    if (tipo == 1){
        salario = 15*horasDiarias*20;
    } else if (tipo == 2){
        salario = (600 + 20*horasDiarias)*4;
    } else if (tipo == 3) {
        salario = (24000*horasDiarias)/24;
    }

    return salario;
}

// A FUNCAO MAIN NAO DEVE SER SUBMETIDA
/*
int main() {
  // FACA OUTROS TESTES
  cout << calculaSalarioMensal (3, 7) << endl;
  return 0;
}
*/
