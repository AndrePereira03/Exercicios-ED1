#include <iostream>
#include <stdlib.h>
#include "Ponto.h"
#include "ListaCont.h"
#include "listamodified.h"

using namespace std;

int main()
{
    cout << "Exercicios 1 e 2:" << endl << endl;
    //int busca_maior;
    ListaCont l(10);

    l.insereFinal(24);
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(-1);
    l.insereFinal(99);
    cout << "Imprimindo L:" << endl;
    l.imprime();
    cout << "O numero de nohs eh: " << l.numNos() << endl;
    cout << "O " << l.buscaMaior(20) + 1 << " elemento da lista eh maior do que 20." << endl;
    l.limpar();
    cout << "Imprimindo lista vazia: " << endl;
    l.imprime();
    cout << "Reinserindo os elementos anteriores: " << endl;
    l.insereFinal(24);
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(-1);
    l.insereFinal(99);
    cout << "Lista com os valores reinseridos: " << endl;
    l.imprime();
    int vet[6];
    for(int i = 0; i < 6; i++)
    {
        vet[i] = i*i;
    }
    l.insereValores(6, vet);
    cout << "Imprimindo lista com valores novos adicionados." << endl;
    l.imprime();
    cout << endl << endl;

   //exercicio 3
   cout << "Exercicio 3:" << endl << endl;

    ListaCont l1(50), l2(25), l3(25);

    for(int i = 0; i < 50; i++)
    {
        l1.insereFinal(rand() % 99 + 1);
    }
    cout << "Imprimindo l1: " << endl;
    l1.imprime();

    for(int i = 0; i < 25; i++)
    {
        l2.insereFinal(l1.get(0));
        l1.removeInicio();
    }

    for(int i = 0; i < 25; i++)
    {
        l3.insereFinal(l1.get(0));
        l1.removeInicio();
    }

    cout << "Imprimindo l2: " << endl;
    l2.imprime();

    cout << endl << "Imprimindo l3:" << endl;
    l3.imprime();


























     /* int tam_vet = 3;
    int vetor[tam_vet] = {};
    l.insereValores(tam_vet, vetor);
    l.imprime();
    cout << endl << "O numero de nos eh: " << l.numNos() << endl;
    busca_maior = l.buscaMaior(54); //Digite o valor que deseja testar dentro da funcao l.buscaMaior
    if(busca_maior != -1)
    {
        cout << "O " << busca_maior + 1 << "o valor da lista eh maior que val" << endl;
    }
    else
    {
        cout  << "Nao existe numero maior que val na lista." << endl;
    }

    int tam_l1 = 50;
    int tam_l2_l3 = tam_l1/2;
    cout << endl << "Exercicio 3:" << endl << endl;

    ListaCont l1(tam_l1);
    ListaCont l2(tam_l2_l3);
    ListaCont l3(tam_l2_l3);

    for(int i = 0; i < tam_l1; i++)
    {
        l1.insereFinal(i*i);
    }
    cout << "Impimindo L1 antes da modificacao:" << endl;
    l1.imprime();
    cout << endl << "Imprimindo L2, ao tirar de L1:" << endl;
    for(int i = 0; i < tam_l2_l3; i++)
    {
        int valor_inicial = l1.get(0);
        l2.insereFinal(valor_inicial);
        l1.removeInicio();
    }
    l2.imprime();
    cout << endl << "L1 apos a modificacao:" << endl;
    l1.imprime();
    for(int i = 0; i < tam_l2_l3; i++)
    {
        int init_value = l1.get(0);
        l3.insereFinal(init_value);
        l1.removeInicio();
    }
    cout << endl << "Imprimindo L3, ao tirar de L1:" << endl;
    l3.imprime();
    ListaCont* l32 = new ListaCont(tam_l1);
    l32 = l3.moveParesInvertidos();
    l3.imprime();
    l32->imprime();

    cout << endl << "Como ficou L1, apos todas as retiradas: " << endl;
    l1.imprime();
    cout << endl << "Exercicio 4:" << endl << endl;
    l1.moveParesInvertidos();
    l1.imprime();

    l.limpar();
    l.imprime();
*/
    return 0;
}
