#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
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

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
	NoDuplo *p = new NoDuplo();
	p->setInfo(val);
	p->setProx(primeiro);
	p->setAnt(NULL);

	if(n == 0) ultimo = p;
	else primeiro->setAnt(p);

	primeiro = p;
	n = n + 1;
}

bool ListaDupla::vazia()
{
    NoDuplo* p = primeiro;
    if(p == NULL)
    return true;
    else
    return false;
}

void ListaDupla::removeInicio()
{
	NoDuplo *p;
	if(primeiro != NULL)
	{
		p = primeiro;
		primeiro = p->getProx();
		delete p;
		n = n - 1;

		if(n == 0) 	ultimo = NULL;
		else primeiro->setAnt(NULL);
	}
	else
        cout << "ERRO: lista vazia" << endl;
}

int ListaDupla::tamanho()
{
    return n;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo* p = new NoDuplo();
    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);

    if(vazia())
    {
        primeiro = p;
        ultimo = p;
    }
    else
    {
        p->setAnt(ultimo);
        ultimo->setProx(p);
        ultimo = p;
    }
    n++;
}

void ListaDupla::removeFinal()
{
    if(vazia())
    {
        cout << "A lista esta vazia!" << endl;
    }
    else if(n == 1)
    {
        removeInicio();
    }
    else
    {
        NoDuplo* p = ultimo;
        (p->getAnt())->setProx(NULL);
        ultimo = p->getAnt();
        delete p;
        n--;
    }
}

void ListaDupla::imprime()
{
    if(vazia())
    {
        cout << "A lista esta vazia!" << endl;
    }
    else
    {
        NoDuplo* p = primeiro;
        while(p != NULL)
        {
            cout << p->getInfo() << " ";
            p = p->getProx();
        }
        cout << endl;
    }
}

void ListaDupla::imprimeReverso()
{
  if(vazia())
    {
        cout << "A lista esta vazia!" << endl;
    }
    else
    {
        NoDuplo* p = ultimo;
        while(p != NULL)
        {
            cout << p->getInfo() << " ";
            p = p->getAnt();
        }
        cout << endl;
    }
}

ListaDupla* ListaDupla::concatena(ListaDupla *l2)
{
    if(vazia() && l2->vazia())
    {
        cout << "Ambas as listas estao vazias!" << endl;
    }
    else if(vazia())
    {
        return l2;
    }
    else if(l2->vazia())
    {
        return this;
    }
    else
    {
        ultimo->setProx(l2->primeiro);
        l2->primeiro->setAnt(ultimo);
        ultimo = l2->ultimo;
        n += l2->n;
        return this;
    }
}

//como o exercicio não especificou muita coisa em relação
//ao particionamento, interpretei que devemos pegar uma lis-
//ta e retorná-la a partir de quando o valor x foi encontrado
//(incluindo x).
ListaDupla* ListaDupla::partir(int x)
{
    if(vazia())
    {
        cout << "A lista esta vazia!" << endl;
        return NULL;
    }

    NoDuplo* p = primeiro;
    bool aux = false;
    int cont = 0;
    while(p != NULL && aux == false)
    {
        if(p->getInfo() == x)
        {
            aux = true;
            break;
        }
        p = p->getProx();
        cont++;
    }
    if(aux == false)
    {
        cout << "O elemento " << x << " nao faz parte da lista!" << endl;
        return this;
    }
    else
    {
        p->setAnt(NULL);
        primeiro = p;
        n -= cont;
        return this;
    }
}

void ListaDupla::removeOcorrencias(int val)
{
    if (vazia())
    {
        cout << "A lista está vazia!" << endl;
        return;
    }

    NoDuplo* p = primeiro;
    while (p != NULL)
    {
        NoDuplo* proximo = p->getProx();

        if (p->getInfo() == val)
        {
            if (p == primeiro)
                primeiro = proximo;

            if (p == ultimo)
                ultimo = p->getAnt();

            if (p->getAnt() != NULL)
                p->getAnt()->setProx(proximo);

            if (proximo != NULL)
                proximo->setAnt(p->getAnt());

            delete p;
            n--;
        }

        p = proximo;
    }
}











































/*
void ListaDupla::insereFinal(int val)
{

    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);

    if(vazia())
    {
        primeiro = p;
        ultimo = p;
    }
    else
    {
        p->setAnt(ultimo);
        ultimo->setProx(p);
        ultimo = p;
    }
    n++;
}

void ListaDupla::removeFinal()
{
    if(primeiro == NULL)//Lista vazia, não há nada a ser feito
    {
        cout << "A lista dada eh vazia." << endl;
        return;
    }
    if(primeiro->getProx() == NULL) //a lista só tem um elemento
    {
        delete primeiro;
        primeiro = NULL;
        ultimo = NULL;
        n--;
        return;
    }

    NoDuplo* p = primeiro;
    NoDuplo* anterior = NULL;
    while(p->getProx() != NULL)
    {
        anterior = p;
        p = p->getProx();
    }

    delete p;

    anterior->setProx(NULL);
    ultimo = anterior;
    n--;
}


void ListaDupla::imprime()
{
    if(vazia())
    {
        cout << "A lista esta vazia!" << endl;
        return;
    }

    NoDuplo* p = primeiro;
    while(p != NULL)
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
    cout << endl;
}

void ListaDupla::imprimeReverso()
{
    if(vazia())
    {
        cout << "A lista está vazia!" << endl;
        return;
    }
    cout << "Imprimindo reverso:" << endl;
    NoDuplo *p = ultimo;
    while(p != NULL)
    {
        cout << p->getInfo() << " ";
        p = p->getAnt();
    }
    cout << endl;
}

ListaDupla* ListaDupla::concatena(ListaDupla *l2)
{
    if(vazia())//verifica se a lista atual esta vazia
    {
        if(!l2->vazia()) return l2;
        else
        {
            cout << "Ambas as listas estao vazias!" << endl;
            exit(1);
        }
    }
    else if(l2->vazia())
        return this;
    else
    {
    NoDuplo* p = l2->primeiro;
    while(p != NULL)
    {
        insereFinal(p->getInfo());
        p = p->getProx();
    }
    ultimo = l2->ultimo;
    n += l2->n;
    }
    return this;
}

ListaDupla* ListaDupla::partir(int x)
{
    if(vazia())
    {
        cout << "Lista vazia!" << endl;
        exit(1);
    }
    //quando encontrar esse valor x, partira a lista
    NoDuplo* p = primeiro;
    while(p != NULL)
    {
        if(p->getInfo() == x)
        {
            ListaDupla* novaLista = new ListaDupla();
            novaLista->primeiro = p->getProx();
            novaLista->ultimo = ultimo;
            novaLista->n = n -novaLista->tamanho();


            ultimo = p;
            p->setProx(NULL);
            n -= novaLista->tamanho();

            return novaLista;
        }
        p = p->getProx();
    }

     cout << "O elemento " << x << " nao pertence a lista" << endl;
        return this;
}

void ListaDupla::removeOcorrencias(int val)
{
    if(vazia())
    {
        cout << "Lista vazia!" << endl;
        return;
    }
    NoDuplo* atual = primeiro;
    NoDuplo* anterior = NULL;
    NoDuplo* proximo = NULL;
    while(atual != NULL)
    {
        anterior = atual->getAnt();
        proximo = atual->getProx();
        if(atual->getInfo() == val)
        {
            if(anterior != NULL)//verifica se o no a ser removido e o primeiro da lista
            {
                anterior->setProx(proximo);//caso contrario, ele aponta o anterior para o proximo
            }
            else//caso seja o primeiro, ele troca o primeiro elemento da lista pelo proximo, que no caso, eh o segundo
            {
                primeiro = proximo;
            }

            if(proximo != NULL)
            {
                proximo->setAnt(anterior);
            }
            else
            {
                ultimo = anterior;
            }

            NoDuplo* aux = atual;
            atual = proximo;
            delete aux;//deleta o no atual, no removido
            n--;
        }
        else
        {
            atual = proximo;
        }
    }
}

void ListaDupla::anexar(ListaDupla* lde)
{
    if(lde->n > 0)
    {
        if(n == 0)
        {
            primeiro = lde->primeiro;
            ultimo = lde->ultimo;
        }
        else
        {
            lde->ultimo->setProx(primeiro);
            primeiro->setAnt(lde->ultimo);
            primeiro = lde->primeiro;
        }

        n += lde->n;

        lde->primeiro = NULL;
        lde->ultimo = NULL;
        lde->n = 0;
    }
}

ListaDupla* ListaDupla::particiona(float val)
{
    if(vazia())
    {
        cout << "Erro! Lista vazia!" << endl;
        return this;//retorna a propria lista vazia, para continuar o programa. Pensei em colocar um exit, mas encerraria todo o programa, o que impactaria nas demais questões
    }

    NoDuplo* p = primeiro;
    while(p != NULL)
    {
        if(p->getInfo() == val)
        {
         ListaDupla* l2 = new ListaDupla();
         if(p->getProx() == NULL)
         {

         }
        }
        else
        {
        p = p->getProx();
        }
    }

}
*/
