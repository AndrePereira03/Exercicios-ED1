#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaDupla.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1); /// retorna um numero inteiro aleat—rio entre a e b
}

int main()
{
    ListaDupla l; /// cria lista vazia
    int NumNos = 10;

    srand(time(NULL));

    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleat—rio entre 0 e 50
        cout << val << ", ";
        l.insereInicio(val);
    }
    cout << endl;

    bool existe = l.busca(20);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    l.insereFinal(28);
    l.insereFinal(35);
    l.removeFinal();

    cout << "A lista, adicionada 28 e 35, removendo final o final, fica: " << endl;
    l.imprime();
    cout << "Imprimindo reverso (de tras para frente):" << endl;
    l.imprimeReverso();
    ListaDupla* l2 = new ListaDupla();
    for(int i = 0; i < 4; i++)
    {
    l2->insereFinal((i*i));
    }
    cout << "Imprimindo a lista 2:" << endl;
    l2->imprime();
    ListaDupla* l3 = new ListaDupla(); //l e l2 concatenadas
    l3 = l.concatena(l2);
    cout << "Lista 3 formada pela concatenacao das listas 1 e 2(lembrando que o 35 foi removido):" << endl;
    l3->imprime();
    cout << "Imprimindo a lista 2, a partir do elemento 4 (se houver):" << endl;
    l2 = l2->partir(4);
    l2->imprime();
    cout << "Removendo ocorrencias do elemento 4 na lista 3 (concatenada):" << endl;
    l3->removeOcorrencias(4);
    l3->imprime();

























/*    l.removeFinal();
    l.insereFinal(39);
    l.imprime();

    ListaDupla l2;
    for(int i = 0; i < 5; i++)
    {
        l2.insereFinal(3);
    }
    l2.insereFinal(4);
    l.concatena(&l2);
    l.imprime();
    l2.imprime();

    ListaDupla* l3 = l2.partir(2);
    l3->imprime();
    l2.removeOcorrencias(3);
    l2.imprime();
    return 0;
    */
}

