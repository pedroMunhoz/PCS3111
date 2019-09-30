#include <iostream>
#include <cmath>

using namespace std;

bool ehProximo(double a, double b){
    return abs(a - b) < 0.001;
}

double *encontrarPessoa(double valoresPorHora[], double horasDiarias[], int quantidade, double valorPorHora, double horaDiaria){

    for (int i = 0; i < quantidade; i++) {
        if ( ehProximo(valoresPorHora[i], valorPorHora) && ehProximo(horasDiarias[i], horaDiaria) ) {
            return &valoresPorHora[i];
        }
    }
    return NULL;
}

int main(){

    double valoresPorHora[] = {10.0, 9.0, 3};
    double horasDiarias[] = {8.0, 11.0, 5};
    int quantidade = 3;

    cout << "Aula02ex01" << endl;

    cout << encontrarPessoa(valoresPorHora, horasDiarias, quantidade, 10, 8) << endl;
    cout << encontrarPessoa(valoresPorHora, horasDiarias, quantidade, 9, 11) << endl;
    cout << encontrarPessoa(valoresPorHora, horasDiarias, quantidade, 3, 5) << endl;
    // cout << *encontrarPessoa(valoresPorHora, horasDiarias, quantidade, 7, 11) << endl;
    cout << encontrarPessoa(valoresPorHora, horasDiarias, quantidade, 9, 11) << endl;

    return 0;
}
