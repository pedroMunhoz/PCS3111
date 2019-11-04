#include "PersistenciaPessoa.h"
#include <fstream>
#include <stdexcept>

PersistenciaPessoa::PersistenciaPessoa(string arquivo) {
    this->arquivo = arquivo;
}

PersistenciaPessoa::~PersistenciaPessoa() {}

void PersistenciaPessoa::inserir(Pessoa *p) {
    ofstream output;
    output.open (this->arquivo, ios_base::app);

    if (output.fail()) {
        cout << "Arquivo nao encontrado" << endl;
        output.close();
    }

    output << p->getNome() << "\n";
    output << p->getValorPorHora() << "\n";
    output << p->getHorasDiarias() << "\n";

    output.close();
}

Pessoa** PersistenciaPessoa::obter(int& quantidade){
    quantidade = 0;
    string nome;
    int valorPorHora, horasDiarias;
    Pessoa** pessoas = new Pessoa*[10];

    ifstream input;
    input.open(this->arquivo);

    if (input.fail()) {
        throw new invalid_argument ("Argumento inválido");
        input.close();
        return NULL;
    }

    while(input) {

        input >> nome;
        input >> valorPorHora;
        input >> horasDiarias;

        pessoas[quantidade] = new Pessoa(nome, valorPorHora, horasDiarias);

        quantidade++;
    }

    if (!input.eof()) throw new logic_error ("Erro lógico");

    if (quantidade == 0) return NULL;

    return pessoas;
}
