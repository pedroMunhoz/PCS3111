#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "Competicao.h"

#include <string>
#include <iostream>
using namespace std;

int main() {
    string nomeCompeticao;
    int quantidadeDeEquipes, quantidadeDeModalidades;
    Equipe** equipes;
    Modalidade** modalidades;


    cout << "Informe o nome de competicao: " ;
    cin >> nomeCompeticao;


    cout << endl << "Informe a quantidade de Equipes: ";    //------### Comeca a obter as equipes do usuario ###------
    cin >> quantidadeDeEquipes;

    equipes = new Equipe*[quantidadeDeEquipes];         //Redefine o vetor equipes para o tamanho quantidadeDeEquipes

    for (int i = 0; i < quantidadeDeEquipes; i++) {     //Para cada equipe
        string nome;
        cout << "Informe o nome da equipe " << i+1 << ": " ;
        cin >> nome;

        equipes[i] = new Equipe(nome);                      //adiciona uma nova equipe no vetor de equipes
    }                                                   //FIM para



    cout << endl << "Informe a quantidade de modalidades: " ;   //------### Comeca a obter informacoes das modalidades do usuario ###------
    cin >> quantidadeDeModalidades;

    Competicao* competicao = new Competicao(nomeCompeticao, equipes, quantidadeDeEquipes, quantidadeDeModalidades); //Cria a competicao com todos os parametros necessarios

    modalidades = new Modalidade*[quantidadeDeModalidades]; //Redefine o vetor de modalidades para que tenha o tamanho de quantidadeDeModalidades

    for (int i = 0; i < quantidadeDeModalidades; i++) {                 //para cada modalidade
        Equipe** resultado = new Equipe*[quantidadeDeEquipes];              //Cria o vetor quee armazena o resultado da respectiva modalidade com tamanho quantidadeDeEquipes
        string nome;

        cout << endl << "Informe o nome da Modalidade " << i+1 << ": " ;
        cin >> nome;

        modalidades[i] = new Modalidade(nome, equipes, quantidadeDeEquipes);//Adiciona a Modalidade ao vetor de modalidades

        for (int j = 0; j < quantidadeDeEquipes; j++) {                     //para cada equipe
            int index;;
            cout << "Informe a equipe " << j+1 << "a colocada: ";
            cin >> index;
            resultado[j] = equipes[index-1];                                    //Adiciona a equipe ao vetor de resultados
        }                                                                   //FIM para
        modalidades[i]->setResultado(resultado);                            //define o resultado da modalidade igual ao vetor de resultados forneciso pelo usuario
        competicao->adicionar(modalidades[i]);                              //Adiciona a modalidade a competicao
    }                                                                   //FIM para

    cout << endl;
    competicao->imprimir();
}

