#include <iostream>
#include <cstdlib>
#include "Ponto.h"
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    cout << "Criando objeto ListaCont" << endl;
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont()
{
    cout << "Destruindo objeto ListaCont" << endl;
    delete [] vet;
}

int ListaCont::get(int k)
{
    if(k >= 0 && k < n)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::set(int k, int val)
{
    if(k >= 0 && k < n)
        vet[k] = val;
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereFinal(int val)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaCont::removeFinal()
{
    if(n == 0)
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    n = n - 1;
}

void ListaCont::insereK(int k, int val)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    if(k >= 0 && k < n)
    {
        for(int i = n-1; i >= k; i--)
            vet[i+1] = vet[i];
        vet[k] = val;
        n = n + 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::removeK(int k)
{
    if(k >= 0 && k < n)
    {
        for(int i = k; i < n-1; i++)
            vet[i] = vet[i+1];
        n--;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereInicio(int val)
{
    if(n == 0)
    {   //lista vazia. Sera o unico no da lista
        vet[n] = val;
        n = n + 1;
    }
    else
        insereK(0, val);
}

void ListaCont::removeInicio()
{
    removeK(0);
}

void ListaCont::imprime()
{
    for(int i = 0; i < n; i++)
    {
        cout << get(i) << " ";
    }
    cout << endl;
}

int ListaCont::numNos()
{
    return n;
}

int ListaCont::buscaMaior(int val)
{
    for(int i = 0; i < n; i++)
    {
        if(get(i) > val)
        {
            return i;
        }
    }
    return -1;
}

void ListaCont::limpar()
{
    n = 0;
}

void ListaCont::insereValores(int tam, int vet[])
{
    int i = 0;
    for(int i = 0; i < tam; i++)
    {
        if(max - n > 0)
        {
            insereFinal(vet[i]);
        }
        else
        {
            cout << "Nao houve espaco para adicionar os demais elementos no vetor abaixo, " << endl;
            cout << "pois tam + n > max. Segue a lista com os elementos que couberam no vetor:" << endl;
            return;
        }
    }
}









































/*void ListaCont::imprime()
{
    for(int i=0; i < n; i++)
    {
        cout << get(i) << " ";
    }
    cout << endl;
}

int ListaCont::numNos()
{
    int no = 0;
    for(int i = 0; i < n; i++)
    {
        no++;
    }
    return no;
}

int ListaCont::buscaMaior(int val)
{
    for(int i = 0; i < n; i++)
    {
        if(get(i) > val)
        {
            return i;
        }
    }
    return -1;
}

void ListaCont::limpar()
{
    n = 0;
}

void ListaCont::insereValores(int tam, int vetor[])
{
    int nos_restantes;
    nos_restantes = max - n;
    if(nos_restantes >= tam)
    {
        for(int i = 0; i < tam; i++)
        {
            insereFinal(vetor[i]);
        }
    }
    else
    {
        cout << "Nao ha espaco disponivel para inserir o vetor." << endl;
    }
}

ListaCont* ListaCont::moveParesInvertidos()
{
    ListaCont* l5 = new ListaCont(max);
    for(int i = 0; i < n; i++)
    {
        if(vet[i] % 2 == 0)
        {
            l5->insereInicio(vet[i]);
            removeK(i);
        }
    }
    return l5;
}
*/



