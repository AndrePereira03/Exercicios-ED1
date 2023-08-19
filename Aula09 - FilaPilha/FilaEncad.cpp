#include <iostream>
#include <cstdlib>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    cout << "Criando FilaEncad" << endl;
    inicio = NULL;
    fim = NULL;
}

FilaEncad::~FilaEncad()
{
    cout << "Destruindo FilaEncad" << endl;
    No* p = inicio;
    while(inicio != NULL)
    {
        inicio = p->getProx();
        delete p;
        p = inicio;
    }
    fim = NULL;
}

bool FilaEncad::vazia()
{
    if(inicio == NULL)
        return true;
    else
        return false;
}

void FilaEncad::enfileira(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(fim == NULL)
        inicio = p;
    else
        fim->setProx(p);
    fim = p;
}

int FilaEncad::getInicio()
{
    if(inicio != NULL)
        return inicio->getInfo();
    else
    {
        cout << "Fila vazia!" << endl;
        exit(1);
    }
}

int FilaEncad::desenfileira()
{
    No* p;
    if(inicio != NULL)
    {
        p = inicio;
        inicio = p->getProx();
        if(inicio == NULL)
            fim = NULL;
        int val = p->getInfo();
        delete p;
        return val;
    }
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
}

void FilaEncad::imprime()
{
    if(vazia())
    {
        cout << "A fila esta vazia!" << endl;
    }
    else
    {
        No* f = inicio;
        while(f != NULL)
        {
            cout << f->getInfo() << " ";
            f = f->getProx();
        }
        cout << endl;
    }
}


















































/*void FilaEncad::imprime()
{
    No* f = inicio;
    while(f != NULL)
    {
        cout << f->getInfo() << " ";
        f = f->getProx();
    }
    cout << endl;
}

 void FilaEncad::removeIgual()
{
    No* atual = inicio;
    No* aux = NULL;

    while (atual != NULL)
    {
        No* proximo = atual->getProx();
        No* anterior = atual;

        while (proximo != NULL)
        {
            if (atual->getInfo() == proximo->getInfo())
            {
                anterior->setProx(proximo->getProx());
                No* temp = proximo;
                proximo = proximo->getProx();
                delete temp;
            }
            else
            {
                anterior = proximo;
                proximo = proximo->getProx();
            }
        }
        atual = atual->getProx();
    }
}



      /*  No* proximo = atual->getProx();
        while(proximo != NULL)
        {
            if(atual->getInfo() == proximo->getInfo())
            {
                if(aux == NULL)
                {
                    inicio = proximo;
                }
                else
                {
                    aux->setProx(proximo);
                }
                proximo = proximo->getProx();
            }
            else
            {
                aux = proximo;
                proximo = proximo->getProx();
            }
        }
        atual  = atual->getProx();*/


/*    while(!fAux.vazia()) f->enfileira(fAux.desenfileira());

    for(int i = 0; i < cont; i++)
    {
            aux = atual;
        for(int j = 0; j < cont; j++)
        {
            atual = atual->getProx();
            if(aux->getInfo() == atual->getInfo())
            {
                aux = aux->getProx();
            }
        }
    }
}*/














