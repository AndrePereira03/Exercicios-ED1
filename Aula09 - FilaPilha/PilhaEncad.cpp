#include <iostream>
#include <cstdlib>
#include "PilhaEncad.h"

using namespace std;

// construtor
PilhaEncad::PilhaEncad()
{
    cout << "Criando PilhaEncad" << endl;
    topo = NULL;
    n = 0;
}

// destrutor
PilhaEncad::~PilhaEncad()
{
    cout << "Destruindo PilhaEncad" << endl;
    No* p = topo;
    while(topo != NULL)
    {
        topo = p->getProx();
        delete p;
        p = topo;
    }
}

void PilhaEncad::empilha(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(topo);
    topo = p;
    n++;
}

int PilhaEncad::desempilha()
{
    No* p;
    if(topo != NULL)
    {
        p = topo;
        topo = p->getProx();
        int val = p->getInfo();
        delete p;
        return val;
        n--;
    }
    else
    {
        cout << "ERRO: Pilha vazia!" << endl;
        exit(1);
    }
}

int PilhaEncad::getTopo()
{
    if(topo != NULL)
        return topo->getInfo();
    else
    {
        cout << "Pilha vazia!" << endl;
        exit(1);
    }
}

bool PilhaEncad::vazia()
{
    if(topo == NULL)
        return(true);
    else
        return(false);
}

void PilhaEncad::imprime()
{
    if(vazia())
    {
        cout << "A pilha esta vazia!" << endl;
    }
    else
    {
        No* p = topo;
        while(p != NULL)
        {
            cout << p->getInfo() << " " ;
            p = p->getProx();
        }
        cout << endl;
    }
}

int PilhaEncad::tamanho()
{
    return n;
}















































/*void PilhaEncad::imprime()
{
    No* p = topo;
    while(p != NULL)
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
    cout << endl;
}

int PilhaEncad::tamanho()
{
    return n;
}
*/














