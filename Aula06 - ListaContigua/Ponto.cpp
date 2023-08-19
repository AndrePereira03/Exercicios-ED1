#include <iostream>
#include <cstdlib>
#include "Ponto.h"
#include "ListaCont.h"
#include "listamodified.h"

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

Ponto ListaCont::get(int k)
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
        n = n - 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereInicio(Ponto val)
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
    for(int i=0; i < n; i++)
    {
        cout << get(i) << " ";
    }
    cout << endl;
}

Ponto ListaCont::numNos()
{
    int no = 0;
    for(int i = 0; i < n; i++)
    {
        no++;
    }
    return no;
}

int ListaCont::buscaMaior(Ponto val)
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

void ListaCont::insereValores(int tam, Ponto vetor[])
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
