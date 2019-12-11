#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "TabelaComOrdem.h"
#include "TabelaComPontos.h"
#include "Competicao.h"
#include "CompeticaoMultimodalidades.h"
#include "CompeticaoSimples.h"
#include "PersistenciaDeCompeticao.h"
#include <vector>

#include <string>
#include <iostream>
using namespace std;

void final(Competicao* competicao);

int main() {
    char carregar;
    int quantidadeEquipes;

    cout << "Deseja carregar uma competicao     (s/n)?  ";
    cin >> carregar;

    if (carregar == 'n') {          //Caso nao carregando uma competicao
        cout << "\nInforme a quantidade de equipes:  ";
        cin >> quantidadeEquipes;
        Equipe** equipes = new Equipe*[quantidadeEquipes];      //Coleta quantidade de equipes e cria o vetor de equipes

        for (int i = 0; i < quantidadeEquipes; i++) {
            string nome;
            cout << "Informe o nome da equipe " << i + 1 << ": ";
            cin >> nome;
            equipes[i] = new Equipe(nome);                      //Coleta os nomes e gera as equipes do vetor
        }

        string nomeComp;
        cout << "\nInforme o nome da competicao:  ";
        cin >> nomeComp;

        char tipoCompeticao;
        cout << "Competicao simples (s) ou multimodalidades (m): ";
        cin >> tipoCompeticao;

        if (tipoCompeticao == 's') {                //Competicao Simples
            string nome;
            cout << "\nInforme o nome da modalidade: ";
            cin >> nome;

            Modalidade* modalidade = new Modalidade(nome, equipes, quantidadeEquipes);
            CompeticaoSimples* competicao = new CompeticaoSimples(nomeComp, equipes, quantidadeEquipes, modalidade);

            char temResultado;
            cout << "Tem resultado (s/n): ";
            cin >> temResultado;

            if (temResultado =='s') {
                Equipe* colocacao[quantidadeEquipes];

                for (int i = 0; i < quantidadeEquipes; i++) {
                    int numEquipe;
                    
                    cout << "Informe a equipe " << i+1 << " colocada: ";
                    cin >> numEquipe;
                    colocacao[i] = equipes[numEquipe-1];
                }
                modalidade->setResultado(colocacao);

                char salvarCompeticao;
                cout << "\nDeseja salvar a competicao (s/n)? ";
                cin >> salvarCompeticao;
                if (salvarCompeticao == 's') {
                    PersistenciaDeCompeticao* persist = new PersistenciaDeCompeticao();
                    string namefile;
                    cout << "Digite o nome do arquivo: ";
                    cin >> namefile;
                    persist->salvar(namefile, competicao);
                    cout << endl;
                    competicao->imprimir();
                } else if (salvarCompeticao == 'n') {
                    competicao->imprimir();
                }
            } else if (temResultado == 'n') {
                char salvarCompeticao;
                cout << "\nDeseja salvar a competicao (s/n)? ";
                cin >> salvarCompeticao;
                if (salvarCompeticao == 's') {
                    PersistenciaDeCompeticao* persist = new PersistenciaDeCompeticao();
                    string namefile;
                    cout << "Digite o nome do arquivo: ";
                    cin >> namefile;
                    persist->salvar(namefile, competicao);
                    cout << endl;
                    competicao->imprimir();
                } else if (salvarCompeticao == 'n') {
                    competicao->imprimir();
                }
            }
        } else if (tipoCompeticao == 'm') {     
            CompeticaoMultimodalidades* competicao = new CompeticaoMultimodalidades(nomeComp, equipes, quantidadeEquipes);

            int quantidadeModalidades;            
            cout << "\nInforme a quantidade de modalidades: ";
            cin >> quantidadeModalidades;

            Modalidade* modalidades[quantidadeModalidades];

            for (int i = 0; i < quantidadeModalidades; i++) {
                string nome;
                cout << "\nInforme o nome da modalidade " << i+1 << ": ";
                cin >> nome;

                modalidades[i] = new Modalidade(nome, equipes, quantidadeEquipes);

                competicao->adicionar(modalidades[i]);

                char temResultado;
                cout << "Tem resultado (s/n): ";
                cin >> temResultado;
                Equipe** colocacao = new Equipe*[quantidadeEquipes];

                if (temResultado == 's') {     
                    for (int j = 0; j < quantidadeEquipes; j++) {
                        int numEquipe;
                        cout << "Informe a equipe " << j+1 << " colocada: ";
                        cin >> numEquipe;
                        colocacao[j] = equipes[numEquipe - 1];
                    }               
                    modalidades[i]->setResultado(colocacao);
                }
            }
            final(competicao);
        }
    } else if (carregar == 's') {
        PersistenciaDeCompeticao* persist = new PersistenciaDeCompeticao();
        string arquivo;
        cout << "Digite o nome do arquivo: " << endl;
        cin >> arquivo;
        cout << endl;
        persist->carregar(arquivo)->imprimir();
    }
}

void final(Competicao* competicao) {
    char salvarCompeticao;
    cout << "\nDeseja salvar a competicao (s/n)? ";
    cin >> salvarCompeticao;
    if (salvarCompeticao == 's') {
        PersistenciaDeCompeticao* persist = new PersistenciaDeCompeticao();
        string namefile;
        cout << "Digite o nome do arquivo: ";
        cin >> namefile;
        persist->salvar(namefile, competicao);
        cout << endl;
        competicao->imprimir();
    } else if (salvarCompeticao == 'n') {
        cout << endl;
        competicao->imprimir();
    }
}

