#include <iostream>

using namespace std;

bool estaNoPrazo(int prazo, int horasAtividade, int horasDiarias) {
    int horasCumpridas = 0;
    int horasDiariasBase = horasDiarias;

    cout << horasAtividade << " Horas para completar em " << prazo << " dias." << endl;

    for (int dia = 0;dia < prazo; dia ++){
        horasDiarias = horasDiariasBase;
        if ((dia+1)%4 == 0) {
            horasDiarias = horasDiarias/2;
        }
        horasCumpridas += horasDiarias;
        cout << "dia " << dia+1 << " - " << horasDiarias << " Horas Diarias - " << horasCumpridas << " Horas Cumpridas" << endl;
        }
    if (horasCumpridas >= horasAtividade) {
        return true;
    } else {
        return false;
    }
}

// A FUNCAO MAIN NAO DEVE SER SUBMETIDA
int main() {
  cout << estaNoPrazo(5, 9, 2) << endl;
}
