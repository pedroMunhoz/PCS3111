#include <iostream>

using namespace std;

double calculaCusto(int horasGastas[], double custoHora[], int quantidade) {
  double custo = 0;

  if (quantidade == 0) {
    return -1;
  } else {
    for (int i = 0; i < quantidade; i++) {
        custo += horasGastas[i]*custoHora[i];
    }
  return custo;
  }
}
 /*
// A FUNCAO MAIN NAO DEVE SER SUBMETIDA
int main() {
  int horasGastas[] = {4, 2, 3};
  double custoHora[] = {25.5, 50, 30};

  // FACA OUTROS TESTES
  cout << calculaCusto(horasGastas, custoHora, 1) << endl;
}
*/
