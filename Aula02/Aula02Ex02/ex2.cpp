#include <iostream>
#include <cmath>
using namespace std;

void calculaAtividade(double horasDiarias[], double valoresPorHora[], int horasNecessarias, double *custo, int &duracao, int quantidade) {

    if (quantidade == 0) {
        duracao = -1;
        *custo = -1;
    } else {
        double somaHorasDia = 0, somaCustoDia = 0;

        for (int i = 0; i < quantidade; i++ ) {
            somaHorasDia += horasDiarias[i];

            somaCustoDia += horasDiarias[i] * valoresPorHora[i];
        }

        duracao = ceil(horasNecessarias/somaHorasDia);

        *custo = duracao * somaCustoDia;
    }
}

int main() {
    
    double valoresPorHora[] = {10.0, 9.0};
    double horasDiarias[] = {8.0, 11.0};
    int quantidade = 0;
    int horasNecessarias = 35;
    double custo;
    int duracao;

    cout << "Aula02ex01" << endl;
    calculaAtividade(horasDiarias, valoresPorHora, horasNecessarias, &custo, duracao, quantidade);
    cout << duracao << endl;
    cout << custo << endl;

    return 0;
}