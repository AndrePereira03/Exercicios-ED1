#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
}

void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
        return NULL;
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            NoArv *aux = menorSubArvDireita(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
            aux->setInfo(val);
            p->setDir(auxRemove(p->getDir(), val));
        }
    }
    return p;
}

NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv* ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir();
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}

float ArvBinBusca::mediaCaminho(int ch)
{
    int soma = 0, cont = 0;
    NoArv *p = raiz;
    while(p != NULL)
    {
        cont++;
        soma += p->getInfo();
        if(ch == p->getInfo())
            break;
        else if(ch > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return (float)soma/cont;
}

int ArvBinBusca::maior()
{
    return auxMaior(raiz);
}

int ArvBinBusca::auxMaior(NoArv* p)
{
    if(p->getDir() == NULL)
    {
        return p->getInfo();
    }
    else
    {
        auxMaior(p->getDir());
    }
}

int ArvBinBusca::menor()
{
    return auxMenor(raiz);
}

int ArvBinBusca::auxMenor(NoArv* p)
{
    if(p->getEsq() == NULL)
    {
        return p->getInfo();
    }
    else
    {
        auxMenor(p->getEsq());
    }
}

void ArvBinBusca::removeMaior()
{
    cout << "Maior valor da arvore removido." << endl;
    remove(maior());
}

void ArvBinBusca::removeMenor()
{
    cout << "Menor valor da arvore removido." << endl;
    remove(menor());
}

int ArvBinBusca::contaParesCaminho(int x)
{
    int valor = x;
    int cont = 0;
    return auxContaParesCaminho(raiz, valor, &cont);
}

int ArvBinBusca::auxContaParesCaminho(NoArv* p, int valor, int* cont)
{
    if(p == NULL || p->getInfo() == valor)
    {
        return *cont;
    }

    if(p->getInfo() % 2 == 0)
    {
        (*cont)++;
    }

    if(valor > p->getInfo())
    {
        auxContaParesCaminho(p->getDir(), valor, cont);
    }
    if(valor < p->getInfo())
    {
        auxContaParesCaminho(p->getEsq(), valor, cont);
    }

    return *cont;
}




void ArvBinBusca::TrocaSubArvore(NoArv* p)
{
    NoArv* maiorEsq = p->getEsq();
    while(maiorEsq->getDir() != NULL)
    {
        maiorEsq = maiorEsq->getDir();
    }

    return auxTrocaSubArvore(raiz, p, maiorEsq);
}

void ArvBinBusca::auxTrocaSubArvore(NoArv* p, NoArv* atual, NoArv* maiorEsq)
{
    if(p == NULL)
    {
        return;
    }
    if(p== atual && p->getDir() != NULL && p->getEsq() != NULL)
    {
        p->setEsq(NULL);
        p->setDir(NULL);
        p->setInfo(maiorEsq->getInfo());
    }

    auxTrocaSubArvore(p->getEsq(), atual, maiorEsq);
    auxTrocaSubArvore(p->getDir(), atual, maiorEsq);
}

int ArvBinBusca::classificaFilhos(NoArv* pai)
{
    if(pai->getEsq() != NULL && pai->getDir() == NULL)
    {
        return -1;
    }
    else if(pai->getEsq() == NULL && pai->getDir() == NULL)
    {
        return 0;
    }
    else if(pai->getEsq() == NULL && pai->getDir() != NULL)
    {
        return 1;
    }
    else if(pai->getEsq() != NULL&& pai->getDir() != NULL)
    {
        return 2;
    }
}

int ArvBinBusca::contaNosFilhos(int val)
{
    int* cont = new int;
    *cont = 0;
    auxContaNosFilhos(raiz, cont, val);
}

int ArvBinBusca::auxContaNosFilhos(NoArv* p,int *cont,int val)
{
    while(p != NULL)
    {
        if(classificaFilhos(p) == -1 || classificaFilhos(p) == 1)
        {
            (*cont)++;
        }

        if(p->getInfo() == val)
        {
            p = NULL;
        }

        else if(val < p->getInfo())
        {
            p = p->getEsq();
        }

        else
        {
            p = p->getDir();
        }
    }

    return *cont;
}

NoArv* ArvBinBusca::removeMen(int val)
{
    auxRemoveMenor(raiz, val);
}

NoArv* ArvBinBusca::auxRemoveMenor(NoArv* p, int val)//este p no main deve ser a raiz;
{
    if(p == NULL)
    {
        return NULL;
    }

    else if(p->getInfo() == val)
    {
        p->setEsq(libera(p->getEsq()));
    }

    else if(p->getInfo() > val)
    {
        p->setEsq((auxRemoveMenor(p->getEsq(), val)));
    }

    else //p->getInfo() < val
    {
        NoArv* fd = p->getDir();
        p->setEsq(libera(p->getEsq()));
        delete p;
        p = auxRemoveMenor(fd, val);
    }

      return p;
}


//OS NOS QUE TEM DOIS FILHOS DEVEM SER TROCADOS PELO MAIOR NO DA SUBARVORE A ESQUERDA
