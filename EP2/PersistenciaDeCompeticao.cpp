#include "PersistenciaDeCompeticao.h"

#include<fstream>
#include<iostream>
#include<stdexcept>
#include<list>

using namespace std;

PersistenciaDeCompeticao::PersistenciaDeCompeticao()
{}

PersistenciaDeCompeticao::~PersistenciaDeCompeticao()
{}

Competicao* PersistenciaDeCompeticao::carregar(string arquivo){
    string nomeEquipe, nomeModalidade, nomeCompeticao, equipePosicao;
    int quantidadeDeEquipes, quantidadeModalidades, quantidadePart;
    bool ehMulti, temResultado;
    string varDescarte;

    ifstream input;
    input.open(arquivo, ios_base::in);

    if(input){
        input >> quantidadeDeEquipes;
        Equipe** participantes = new Equipe*[quantidadeDeEquipes];

        for(int i = 0; i < quantidadeDeEquipes; i++){
            input >> nomeEquipe;
            participantes[i] = new Equipe(nomeEquipe);
        }

        input >> nomeCompeticao;

        input >> ehMulti;

        if(ehMulti){
            input >> quantidadeModalidades;

            Modalidade** modalidades = new Modalidade*[quantidadeModalidades];

            CompeticaoMultimodalidades* competicao = new CompeticaoMultimodalidades(nomeCompeticao, participantes, quantidadeDeEquipes);
            
            for(int i = 0; i < quantidadeModalidades; i++){
                input >> nomeModalidade;

                input >> temResultado;

                input >> quantidadePart;

                modalidades [i] = new Modalidade(nomeModalidade, participantes, quantidadePart);
                
                if(temResultado){
                    Equipe** ordemResultado = new Equipe*[quantidadePart];
                    
                    for(int j = 0; j < quantidadePart; j++){
                        input >> equipePosicao;
                        for(int k = 0; k < quantidadePart; k++){
                            if(equipePosicao == participantes[k]->getNome()){
                                ordemResultado [j] = participantes [k];
                            }
                        }
                    }
                    modalidades [i]->setResultado(ordemResultado);
                } else {
                    for(int m = 0; m < quantidadePart; m++){
                        input >> varDescarte;
                    }
                }
            competicao->adicionar(modalidades[i]);
            }
            return competicao;

        } else {
            input >> nomeModalidade;

            input >> temResultado;

            input >> quantidadePart;

            Modalidade* modalidade = new Modalidade(nomeModalidade, participantes, quantidadePart);
            
            CompeticaoSimples* competicao = new CompeticaoSimples(nomeCompeticao, participantes, quantidadePart, modalidade);
            
            if(temResultado){
                Equipe** ordemResultado = new Equipe*[quantidadePart];

                for(int i = 0; i < quantidadePart; i++){
                        input >> equipePosicao;

                        for(int j = 0; j < quantidadePart; j++){
                            if(equipePosicao == participantes [j]->getNome()){
                                ordemResultado [i] = participantes [j];
                            }
                        }
                }
                modalidade->setResultado(ordemResultado);
            }
            else {
                for(int m = 0; m < quantidadePart; m++){
                    input >> varDescarte;
                }
            }
            return competicao;
        }
    } else {
        throw new invalid_argument("Arquivo nao encontrado");
    }
}


void PersistenciaDeCompeticao::salvar(string arquivo, Competicao *c){
    ofstream output;
    output.open(arquivo);

    if(output) {
        output << c->getQuantidadeDeEquipes() << endl;

        for(int i = 0; i < c->getQuantidadeDeEquipes(); i++) {
            output << c->getEquipes()[i]->getNome() << endl;
        }

        output << c->getNome() << endl;

        CompeticaoSimples* compSimp = dynamic_cast<CompeticaoSimples*>(c);
        bool ehMulti;
        if(compSimp != NULL) {
            ehMulti = false;
        } else {
            ehMulti = true;
        }
        output << ehMulti << endl;

        if(!ehMulti) {
            output << compSimp->getModalidade()->getNome() << endl 
                << compSimp->getModalidade()->temResultado() << endl
                << compSimp->getQuantidadeDeEquipes() << endl;
            if(compSimp->getModalidade()->temResultado()) {
                for(int i = 0; i < compSimp->getQuantidadeDeEquipes(); i++) {
                    output << compSimp->getTabela()->getEquipesEmOrdem()[i]->getNome() << endl;
                }
            } else {
                for(int i = 0; i < compSimp->getQuantidadeDeEquipes(); i++) {
                    output << compSimp->getEquipes()[i]->getNome();
                }
            }
        } else {
            CompeticaoMultimodalidades* compMulti = dynamic_cast<CompeticaoMultimodalidades*>(c);
            output << compMulti->getModalidades()->size() << endl;
            list<Modalidade*>::iterator m = compMulti->getModalidades()->begin();
            while(m != compMulti->getModalidades()->end()) {
                output <<(*m)->getNome() << endl
                    <<(*m)->temResultado() << endl
                    <<(*m)->getQuantidadeDeEquipes() << endl;
                if((*m)->temResultado()) {
                    for(int i = 0; i <(*m)->getQuantidadeDeEquipes(); i++) {
                        output <<(*m)->getTabela()->getEquipesEmOrdem()[i]->getNome() << endl;
                    }
                } else {
                    for(int i = 0; i <(*m)->getQuantidadeDeEquipes(); i++) {
                        output <<(*m)->getEquipes()[i]->getNome() << endl;
                    }
                }
                m++;
            }
        }
    } else {
        throw new invalid_argument("Impossivel escrever");
    }
    output.close();
}




