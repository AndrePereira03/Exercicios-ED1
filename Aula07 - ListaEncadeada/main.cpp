#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaEncad.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1) ; /// retorna um numero inteiro aleatório entre a e b
}

/*int ordenadaIntervalo(int a, int b)
{
    int tam = b - a;
    int vet[tam] = { };
    for(int i = 0; i < tam; i++)
    {
        vet[i] = b;
        b--;
    }

    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
        {
            if(vet[j] > vet[j+1])
            {
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
    cout << "O vetor ordenado eh: " << endl;
    for(int i = 0; i < tam; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;

}
*/

int main()
{
    ListaEncad l; /// cria lista vazia
    int NumNos = 12;

    srand(time(NULL));
    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val = numAleatorio(0, 50); /// cria um valor aleatório entre 0 e 50
        cout << val << ", ";
        l.insereFinal(val);
    }
    cout << endl;

    bool existe = l.busca(40);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    cout << endl << endl << "Imprimindo a lista: " << endl;
    l.imprime();
    cout << "A lista tem " << l.numNos() << " nohs." << endl;
    int val = 43;
    cout << "O elemento de indice " << l.buscaMaior(val) << " eh o primeiro elemento maior que " << val << endl;
    cout << "A media dos valores da lista eh " << l.calculaMedia() << endl;

    ListaEncad l2;
    for(int i = 0; i < 5; i++)
    {
        l2.insereFinal(i*i);
    }
    cout << "Os valores de l2 sao: " << endl;
    l2.imprime();
    cout << "concatenando l1 com l2: " << endl;
    l.concatena(&l2);
    l.imprime();
    ListaEncad* novaLista = new ListaEncad();
    novaLista = l.partir(8);
    cout << "Imprimindo a novaLista (lista antiga a partir (inclusive) do elemento de indice 8): " << endl;
    novaLista->imprime();
    l.insereOrdenado(23);
    cout << "Lista l1 com 23 inserido ordenado: " << endl;
    l.imprime();



    cout << "Limpando a lista: " << endl;
    l.limpar();


























      /*  l.imprime();
        cout << "O numero de nos eh: " << l.numNos() << endl;
        if(l.buscaMaior(25) == -1)
        {
            cout << "Não existe um valor na lista que seja maior do que o digitado." << endl;
        }
        else
        {
            cout << "O " << l.buscaMaior(20) << "o elemento da lista eh maior que o valor digitado." << endl;
        }
    cout << "A media dos valores da lista eh: " << l.calculaMedia() << endl;
    ListaEncad l2;
     cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val = numAleatorio(0, 50); /// cria um valor aleatório entre 0 e 50
        cout << val << ", ";
        l2.insereFinal(val);
    }
    cout << endl;
    l.concatena(&l2);
    cout << "Lista concatenada:" << endl;
    l.imprime();
    cout << "Lista partida no elemento 5:" << endl;
    ListaEncad* novaLista = new ListaEncad();
    novaLista = l.partir(50);
    novaLista->imprime();
    l.imprime();
    l.removeVal(30);
    //l.insereOrdenado(35);
    l.imprime();
    l.insereDepoisMenor(23);
    l.imprime();
    l.limpar();
    l.imprime();

*/
    return 0;
};


















































