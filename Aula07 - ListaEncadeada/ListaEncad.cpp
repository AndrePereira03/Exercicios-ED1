#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    cout << "Criando objeto ListaEncad" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEncad::~ListaEncad()
{
    cout << "Destruindo objeto ListaEncad" << endl;
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaEncad::busca(int val)
{
    No *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaEncad::get(int k)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaEncad::set(int k, int val)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}


void ListaEncad::insereInicio(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(primeiro);

    primeiro = p;

    n++;
    if(n == 1) ultimo = p;
}

void ListaEncad::insereFinal(int val)
{
    No* p = new No;
    p->setInfo(val);
    p->setProx(NULL);

    if(ultimo != NULL) ultimo->setProx(p);
    ultimo = p;

    n++;
    if(n == 1) primeiro = p;
}

void ListaEncad::removeInicio()
{
    No* p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;

        n--;
        if(n == 0) ultimo = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::removeFinal()
{
    No* p;
    if(ultimo != NULL)
    {
        if(primeiro == ultimo)
        {
            primeiro = NULL;
            p = NULL;
        }
        else
        {
            p = primeiro;
            while(p->getProx() != ultimo)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

bool ListaEncad::vazia()
{
    return n == 0;
}

void ListaEncad::imprime()
{
    if(!vazia())
    {
        No* p = primeiro;
        while(p != NULL)
        {
        cout << p->getInfo() << " ";
        p = p->getProx();
        }
        cout << endl;
    }
    else
    {
        cout << "A lista esta vazia!" << endl;
    }
}

int ListaEncad::numNos()
{
    return n;
}

int ListaEncad::buscaMaior(int val)
{
    No* p = primeiro;
    int indice = 0;
    while(p != NULL)
    {
        if(p->getInfo() > val)
        {
            return indice;
        }
        p = p->getProx();
        indice++;
    }
    return -1;
}

void ListaEncad::limpar()
{
    if(!vazia())
    {
        No* p = primeiro;
        while(p != NULL)
        {
            p = p->getProx();
            removeInicio();
        }
    }
    else
    {
        cout << "A lista ja esta vazia!" << endl;
    }

}

float ListaEncad::calculaMedia()
{
   float soma = 0;
   No* p = primeiro;
   while (p != NULL)
   {
       soma += p->getInfo();
       p = p->getProx();
   }
   return soma/n;
}

void ListaEncad::concatena(ListaEncad *l2)
{
    if(l2->vazia())
    {
        return;
    }
    if(vazia())
    {
        No* p = l2->primeiro;
        while(p != NULL)
        {
            insereFinal(p->getInfo());
            p = p->getProx();
        }
        return;
    }
        No* p = l2->primeiro;
        while(p != NULL)
        {
            insereFinal(p->getInfo());
            p = p->getProx();
        }
}

ListaEncad* ListaEncad::partir(int x)
{
    if(!vazia())
    {
        ListaEncad* novaLista = new ListaEncad();
        if(x < 0 || x > n)
        {
            cout << "O indice dado nao esta contido no intervalo de indices da lista atual." << endl;
            return NULL;
        }
        else if(x == 0)
        {
            return this;
        }
        else if(x == n)
        {
            novaLista->insereFinal(ultimo->getInfo());
            return novaLista;
        }
        else
        {
            No* p = primeiro;
            int i = 0;
            while(p != NULL)
            {
                if(i >= x)
                {
                    novaLista->insereFinal(p->getInfo());
                }
                p = p->getProx();
                i++;
            }
            return novaLista;
        }
    }
    else
    {
        cout << "A lista atual esta vazia!" << endl;
        return NULL;
    }
}

    void ListaEncad::insereOrdenado(int val)
    {
        if(vazia())
        {
            insereFinal(val);
            return;
        }
            insereFinal(val);
            No* atual = primeiro;
            No* proximo = atual->getProx();

            while( atual != NULL)
            {
            while(proximo != NULL)
            {
                if(atual->getInfo() > proximo->getInfo())
                    {
                        int aux = atual->getInfo();
                        atual->setInfo(proximo->getInfo());
                        proximo->setInfo(aux);
                    }
                proximo = proximo->getProx();
            }
                atual = atual->getProx();
                if(atual != NULL)
                {
                    proximo = atual->getProx();
                }
            }
    }




      /*      for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(atual->getInfo() > proximo->getInfo())
                    {
                        int aux = atual->getInfo();
                        atual->setInfo(proximo->getInfo());
                        proximo->setInfo(aux);
                        atual = atual->getProx();
                        proximo = proximo->getProx();
                    }
                atual = atual->getProx();
                proximo = proximo->getProx();
                }
            }*/





































/*void ListaEncad::imprime()
{
    No* p = primeiro;
    cout << "Os valores da lista sao: " << endl;
    while(p != NULL)
    {
    cout << p->getInfo() << " ";
    p = p->getProx();
    }
    cout << endl;
}
int ListaEncad::numNos()
{
    No* p = primeiro;
    n = 0;
    while(p != NULL)
    {
        p = p->getProx();
        n++;
    }
    return n;
}
int ListaEncad::buscaMaior(int val)
{
    No* p = primeiro;
    int contador = 1;
    while(p != NULL)
    {
        if(p->getInfo() > val)
        {
            return contador;
        }
        p = p->getProx();
        contador++;
    }
    return -1;
}
void ListaEncad::limpar()
{

    No* p = primeiro;
    while(p != NULL)
    {
        p = p->getProx();
        removeInicio();
    }
}
float ListaEncad::calculaMedia()
{
    No* p = primeiro;
    float soma = 0;
    float contador = 0;
    while(p != NULL)
    {
        soma += p->getInfo();
        p = p->getProx();
        contador++;
    }
    return soma/12;
}
void ListaEncad::concatena(ListaEncad *l2)
{
if(l2 == NULL || l2->primeiro == NULL)
{
    return;
}
if(primeiro == NULL)
{
    primeiro = l2->primeiro;
    ultimo = l2->ultimo;
    n = l2->n;
}
else
{
    ultimo->setProx(l2->primeiro);
    ultimo = l2->ultimo;
}
    n += l2->n;
    l2->primeiro = NULL;
    l2->ultimo = NULL;
    l2->n = 0;
}

ListaEncad* ListaEncad::partir(int x)
{
    if(x < 0 || x > n)
    {
        cout << "Indice Invalido!" << endl;
        //percebi que exit(1) fazia o programa parar, então, retornei a própria lista inicial.
        return this;
    }

    ListaEncad *novaLista = new ListaEncad();

    if(x == 0)
    {
        novaLista->primeiro = primeiro;
        novaLista->ultimo = ultimo;
        novaLista->n = n;

        primeiro = NULL;
        ultimo = NULL;
        n = 0;
    }

    else if(x == n)
    {
        No* p = primeiro;
        for(int i = 0; i < n - 1; i++)
        {
            p = p->getProx();
        }
        novaLista-> primeiro = p->getProx();
        novaLista-> ultimo = ultimo;
        novaLista->n = n - x;

        p->setProx(NULL);
        ultimo = p;
        n = x;
    }

    else
    {
        No* p = primeiro;
        int i = 0;
        for(i; i < x-1; i++)
        {
            p = p->getProx();
        }
        novaLista->primeiro = p->getProx();
        novaLista->ultimo = ultimo;
        novaLista->n = n - x;

        p->setProx(NULL);
        ultimo = p;
        n = x;
    }

    return novaLista;
}



   /* ListaEncad *segundaLista = new ListaEncad();
    int cont = 0;
    No *p = primeiro;
    while(p != NULL && p->getInfo() != x)
    {
        p=p->getProx();
        cont++;
    }
    se cont = 0, a condição de cima não foi satisfeita
    if(cont > 0)
    {
        segundaLista-> primeiro = p->getProx();
        segundaLista-> primeiro-> p->getProx();
        segundaLista-> primeiro = p->getProx();
        segundaLista-> primeiro = p->getProx();

    }



    if(x > n || x <= 0)
    {
        cout << "Erro! Indice invalido!" << endl;
        exit(1);
    }
    else
    {
        for(int i = 0; i < x-1; i++)
        {
          removeFinal();
        }
    }
    return this;
}
//acaba aqui o outro coment

void ListaEncad::removeVal(int val)
{
    No* atual = primeiro;
    No* anterior = NULL;
    while (atual != NULL)
    {
        if(atual->getInfo() == val)
        {
            if(anterior == NULL)
            {
                primeiro = atual->getProx();
                delete atual;
                atual = primeiro;
            }
            else
            {
                anterior->setProx(atual->getProx());
                delete atual;
                atual = anterior->getProx();
            }
                n--;
        }
            else
            {
                anterior = atual;
                atual = atual->getProx();
            }
    }
}

void ListaEncad::removeNo(int indice)
{
    No* p = primeiro;
    int c = 0;
    while ( p != NULL)
    {
        if(c == indice)
        p = p->getProx();
        c++;
    }
    n--;
}

void ListaEncad::insereOrdenado(int val)
{
    /*No* p = primeiro;
    No* atual = primeiro;
    No* proximo = atual->getProx();
    int c = 0;
    int menor = p->getInfo();
    while(p != NULL)
    {
      p=p->getProx();
      if(p->getInfo() < menor)
      {
          menor = p->getInfo();
      }
      c++;
    }
    for(int i = 0; i < c-1; i++)
    {
        for(int j = 0; j < c-1; j++)
        {
            if(p->getInfo() > (p->getProx())->getInfo())
            {
                int valor = p->getInfo();
                p->setInfo((p->getProx())->getInfo());
                (p->getProx())->setInfo(valor);
            }
        }
    }//acaba aqui o outro coment
    No* p = primeiro;
    int c = 0;
    int menor = p->getInfo();
    while(p != NULL)
    {
      p=p->getProx();
      if(p->getInfo() < menor)
      {
          menor = p->getInfo();
      }
      c++;
    }


    while(p != NULL)
    {

    }
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < c; j++)
        {
            insereFinal(menor);
        }
    }
}

void ListaEncad::insereDepoisMenor(int val)
{
    if(n == 0)
    {
        cout << "A lista esta vazia!";
        return;
    }

    No *menor = primeiro, *prox, *p = primeiro;
    while(p != NULL)
    {
        if(p->getInfo() < menor->getInfo())
        {
            menor = p;
        }
        p =p->getProx();
    }
    prox = menor->getProx();
    No* novo = new No();
    novo->setInfo(val);
    novo->setProx(prox);
    menor->setProx(novo);

    if(prox == NULL)
    {
        ultimo = novo;
    }
    n++;
}
    */




















