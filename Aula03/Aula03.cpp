#include <iostream>
#include <string>

using namespace std;

class Pessoa {
public:
    string nome;
    bool disponivel;
    int horasMensais;

    double getSalarioDiario();
    void imprimir();
};

double Pessoa::getSalarioDiario() {
    if (this->disponivel) return 50+this->horasMensais/22.0;
    else return 0;
}

void Pessoa::imprimir() {
    if (this->disponivel) cout << this->nome << " - disponivel - " << this->horasMensais << "h/mes - R$" << this->getSalarioDiario() << endl;
    else cout << this->nome << " - nao disponivel - 0h/mes - R$" << this->getSalarioDiario() << endl;
}

class Atividade {
public:
    string nome;
    int duracao;
    Pessoa *p1 = NULL;
    Pessoa *p2 = NULL;

    Pessoa* getResponsavel();
    bool adicionar(Pessoa *p);
    double getCusto();
    void imprimir();
};

Pessoa* Atividade::getResponsavel() {
    if (this->p1 == NULL && this->p2 ==NULL) {
        return NULL;
    } else if (this->p1 == NULL && this->p2 != NULL) {
        return p2;
    } else if (this->p1 != NULL && this->p2 == NULL) {
        return p1;
    } else {
        if (this->p1->getSalarioDiario() < this->p2->getSalarioDiario()) return p1;
        else return p2;
    }
}

bool Atividade::adicionar(Pessoa *p) {
    if (!p->disponivel){
        return false;
    } else {
        if (this->p1 == NULL){
            this->p1 = p;
        } else if (this->p2 == NULL) {
            this->p2 = p;
        } else {
            return false;
        }
        return true;
    }
}

double Atividade::getCusto() {
    if (this->getResponsavel() == NULL) {
        return -1;
    } else {
        return this->duracao * this->getResponsavel()->getSalarioDiario();
    }
}

void Atividade::imprimir() {
    cout << this->nome << " - " << this->duracao << " dias - R$" << this->getCusto() << endl;
    this->getResponsavel()->imprimir();
}

int main() {

    Pessoa *pes1 = new Pessoa;
    Pessoa *pes2 = new Pessoa;
    Pessoa *pes3 = new Pessoa;
    Atividade *ativ1 = new Atividade;
    
    pes1->disponivel = true;
    pes1->horasMensais = 120;
    pes1->nome = "Ana";
    pes2->disponivel = true;
    pes2->horasMensais = 180;
    pes2->nome = "Pedro";
    ativ1->nome = "Teste";
    ativ1->duracao = 2;
    pes3->disponivel = true;
    pes3->horasMensais = 80;
    pes3->nome = "Caique";
    

    ativ1->adicionar(pes1);
    ativ1->adicionar(pes3);
    ativ1->adicionar(pes2);

    ativ1->imprimir();

}