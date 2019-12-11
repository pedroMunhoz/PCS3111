#include "Competicao.h"

#include <iostream>

Competicao::Competicao(string nome, Equipe **equipes, int quantidade, int maximoDeModalidades) {
    this->nome = nome;
    this->equipes = equipes;
    this->quantidadeDeEquipes = quantidade;
    this->maximoDeModalidades = maximoDeModalidades;

    this->quantidadeDeModalidades = 0;

    this->tabela = new Tabela(this->equipes, quantidade);

    this->modalidades = new Modalidade*[maximoDeModalidades];
    this->pontos = new int[quantidade];
}

Competicao::~Competicao() {
    for ( int i = 0; i < this->maximoDeModalidades; i++) {
        delete this->modalidades[i];
    }
    delete[] modalidades;
    delete tabela;
    delete[] pontos;
}

string Competicao::getNome() {
    return this->nome;
}

int Competicao::getQuantidadeDeEquipes() {
    return this->quantidadeDeEquipes;
}

Equipe** Competicao::getEquipes() {
    return this->equipes;
}

bool Competicao::adicionar(Modalidade *m) {
    if (this->quantidadeDeModalidades >= this->maximoDeModalidades) {
        return false;
    }
    this->modalidades[quantidadeDeModalidades] = m;
    this->quantidadeDeModalidades++;
    return true;
}

Modalidade** Competicao::getModalidades() {
    return this->modalidades;
}

int Competicao::getQuantidadeDeModalidades() {
return this->quantidadeDeModalidades;
}

Tabela* Competicao::getTabela() {
    this->tabela = new Tabela(this->equipes, this->quantidadeDeEquipes);    //Cria nova Tabela


    for (int i = 0; i < this->quantidadeDeModalidades; i++) {               //Para cada Modalidade na tabela
        for (int j = 0; j < this->modalidades[i]->getQuantidadeDeEquipes(); j++) {  //Verifica cada Equipe

            if (this->modalidades[i]->getPosicao(this->modalidades[i]->getEquipes()[j]) == 1){          //Se equipe j da modalidade i for 1o lugar
                this->tabela->pontuar(this->modalidades[i]->getEquipes()[j], 13);                       //Adiciona 13 pontos
            } else if (this->modalidades[i]->getPosicao(this->modalidades[i]->getEquipes()[j]) == 2){   //Se equipe j da modalidade i for 2o lugar
                this->tabela->pontuar(this->modalidades[i]->getEquipes()[j], 10);                       //Adiciona 10 pontos
            } else if (this->modalidades[i]->getPosicao(this->modalidades[i]->getEquipes()[j]) == 3){   //Se equipe j da modalidade i for 3o lugar
                this->tabela->pontuar(this->modalidades[i]->getEquipes()[j], 8);                        //...
            } else if (this->modalidades[i]->getPosicao(this->modalidades[i]->getEquipes()[j]) == 4){
                this->tabela->pontuar(this->modalidades[i]->getEquipes()[j], 7);
            } else if (this->modalidades[i]->getPosicao(this->modalidades[i]->getEquipes()[j]) == 5){
                this->tabela->pontuar(this->modalidades[i]->getEquipes()[j], 5);
            } else if (this->modalidades[i]->getPosicao(this->modalidades[i]->getEquipes()[j]) == 6){
                this->tabela->pontuar(this->modalidades[i]->getEquipes()[j], 4);
            } else if (this->modalidades[i]->getPosicao(this->modalidades[i]->getEquipes()[j]) == 7){
                this->tabela->pontuar(this->modalidades[i]->getEquipes()[j], 3);
            } else if (this->modalidades[i]->getPosicao(this->modalidades[i]->getEquipes()[j]) == 8){
                this->tabela->pontuar(this->modalidades[i]->getEquipes()[j], 2);                        //...
            } else if (this->modalidades[i]->getPosicao(this->modalidades[i]->getEquipes()[j]) == 9){   //Se equipe j da modalidade i for 9o lugar
                this->tabela->pontuar(this->modalidades[i]->getEquipes()[j], 1);                        //Adiciona 1 ponto
            } else if (this->modalidades[i]->getPosicao(this->modalidades[i]->getEquipes()[j]) >= 10){  //Se equipe j da modalidade i for 10o lugar ou acima
                this->tabela->pontuar(this->modalidades[i]->getEquipes()[j], 0);                        //Adiciona 0 pontos
            }

        }
    }
    return this->tabela;
}

void Competicao::imprimir() {
    cout << this->nome << endl;
    this->getTabela()->imprimir();
}
