#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"
#include <climits>
#include <math.h>

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Árvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

int ArvBin::contaNos()
{
    return auxContaNos(raiz);
}

int ArvBin::auxContaNos(NoArv* p)
{
    if(p == NULL)
    {
        return 0;
    }
    return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
}

int ArvBin::contaNosFolhas()
{
    return auxContaNosFolhas(raiz);
}

bool ArvBin::ehFolha(NoArv* p)
{
    return p->getEsq() == NULL && p->getDir() == NULL;
}

int ArvBin::auxContaNosFolhas(NoArv* p)
{
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        if(ehFolha(p))
        {
            return 1 + auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());
        }
        else
        {
            return 0 + auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());
        }
    }
}

int ArvBin::altura()
{
    return auxAltura(raiz);
}

int ArvBin::auxAltura(NoArv* p)
{
    if(p == NULL)
    {
        return 0;
    }
    int he = auxAltura(p->getEsq());
    int hd = auxAltura(p->getDir());
    if(he > hd)
    {
        return 1 + he;
    }
    else
    {
        return 1 + hd;
    }
}

int ArvBin::contaImpar()
{
    return auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(NoArv* p)
{
    if(p == NULL)
    {
        return 0;
    }
    if(p->getInfo() % 2 == 0)
    {
        return 0 + auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
    }
    else
    {
    return 1 + auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
    }
}

int ArvBin::contaFolhaImpar()
{
    return auxContaFolhaImpar(raiz);
}

int ArvBin::auxContaFolhaImpar(NoArv* p)
{
    if(p == NULL)
    {
        return 0;
    }
    if(ehFolha(p) && (p->getInfo() % 2 != 0))
    {
        return 1 + auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
    }

    return auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
}

void ArvBin::imprimeNivel(int k)
{
    auxImprimeNivel(raiz, 0, k);
}

void ArvBin::auxImprimeNivel(NoArv* p, int nivelAtual, int k)
{
    if(p == NULL)
    {
        return;
    }
    if(nivelAtual == k)
    {
        cout << p->getInfo() << " ";
    }

    auxImprimeNivel(p->getEsq(), nivelAtual+ 1, k);
    auxImprimeNivel(p->getDir(), nivelAtual+ 1, k);
}

float ArvBin::mediaNivel(int k)
{
    float soma = 0;
    int cont = 0;
    auxMediaNivel(raiz, 0, k, &soma, &cont);
    if(cont > 0)
    {
        return soma/cont;
    }
    else
    {
        return 0;
    }
}

float ArvBin::auxMediaNivel(NoArv* p, int nivelAtual, int k, float* soma, int* cont)
{
    if(p == NULL)
    {
        return 0;
    }
    if(nivelAtual == k)
    {
        (*soma) += p->getInfo();
        (*cont)++;
    }

    auxMediaNivel(p->getEsq(), nivelAtual + 1, k, soma, cont);
    auxMediaNivel(p->getDir(), nivelAtual + 1, k, soma, cont);
}

int ArvBin::minimo()
{
    return auxMinimo(raiz);
}

int ArvBin::auxMinimo(NoArv* p)
{
    if(p == NULL)
    {
        return 999;
    }

    int menor = p->getInfo();
    int menorEsquerda = auxMinimo(p->getEsq());
    int menorDireita = auxMinimo(p->getDir());

    if(menorEsquerda < menor)
    {
        menor = menorEsquerda;
    }
    if(menorDireita < menor)
    {
        menor = menorDireita;
    }
    return menor;
}


int ArvBin::maximo()
{
    return auxMaximo(raiz);
}

int ArvBin::auxMaximo(NoArv* p)
{
    if(p == NULL)
    {
        return -999;
    }

    int maior = p->getInfo();
    int maiorEsq = auxMaximo(p->getEsq());
    int maiorDir = auxMaximo(p->getDir());

    if(maiorEsq > maior)
    {
        maior = maiorEsq;
    }
    if(maiorDir > maior)
    {
        maior = maiorDir;
    }

    return maior;
}

void ArvBin::inverteFilhos(NoArv *p)
{
    auxInverteFilhos(raiz);
}

void ArvBin::auxInverteFilhos(NoArv *p)
{
    if(p == NULL)
    {
        return;
    }
    if(p->getEsq() != NULL && p->getDir() != NULL)
    {
        int aux = p->getEsq()->getInfo();
        p->getEsq()->setInfo(p->getDir()->getInfo());
        p->getDir()->setInfo(aux);
    }

    auxInverteFilhos(p->getEsq());
    auxInverteFilhos(p->getDir());
}

int ArvBin::noMaisEsquerda()
{
    return auxNoMaisEsquerda(raiz);
}

int ArvBin::auxNoMaisEsquerda(NoArv* p)
{
    if(p == NULL)
    {
        return NULL;
    }
    while(p->getEsq() != NULL)
    {
        p = p->getEsq();
    }
    return p->getInfo();
}

int ArvBin::noMaisDireita()
{
    return auxNoMaisDireita(raiz);
}

int ArvBin::auxNoMaisDireita(NoArv* p)
{
    if(p == NULL)
    {
        return NULL;
    }
    while(p->getDir() != NULL)
    {
        p = p->getDir();
    }
    return p->getInfo();
}

bool ArvBin::ehABB()
{
    return auxEhABB(raiz);
}


bool ArvBin::auxEhABB(NoArv *p)
{
    if(p == NULL)
    {
        return true;
    }

    int maxEsq = auxMaximo(p->getEsq());
    int minDir = auxMinimo(p->getDir());

    if(p->getInfo() < maxEsq || p->getInfo() > minDir)///pense em maxEsq e minDir como os filhos
    {                                                 ///a esquerda e direita de p->getInfo();
        return false;
    }

    return auxEhABB(p->getEsq()) && auxEhABB(p->getDir());
}







































/*int ArvBin::contaNos()
{
    return auxContaNos(raiz);
}

int ArvBin::auxContaNos(NoArv *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int cont = auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
    return 1 + cont;
}

int ArvBin::contaNosFolhas()
{
    return auxContaNosFolhas(raiz);
}

int ArvBin::auxContaNosFolhas(NoArv* p)
{
    if(p == NULL)
    {
        return 0;
    }
    int cont = auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());
    if(p->getEsq() == NULL && p->getDir() == NULL)
    {
        return 1;
    }
    else
    {
        return cont;
    }
}

int ArvBin::altura()
{
    return auxAltura(raiz);
}

int ArvBin::auxAltura(NoArv* p)
{
    if(p == NULL)
    {
        return -1;
    }
    int he, hd;
    he = auxAltura(p->getEsq());
    hd = auxAltura(p->getDir());
    return 1 + (he > hd ? he : hd);
}

int ArvBin::contaImpar()
{
    return auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(NoArv* p)
{
    if (p == NULL)
    {
        return 0;
    }
    int cont = auxContaImpar((p->getEsq()) + auxContaImpar(p->getDir()));
    if(p->getInfo() % 2 != 0)
    {
        return 1 + cont;
    }
    else
    {
        return 0 + cont;
    }
}

int ArvBin::contaFolhaImpar()
{
    return auxContaFolhaImpar(raiz);
}

int ArvBin::auxContaFolhaImpar(NoArv* p)
{
    if(p == NULL)
    {
        return 0;
    }
    int cont = 0;
    cont = auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
    if(p->getDir() == NULL && p->getEsq() == NULL)
    {
        if(p->getInfo() % 2 != 0)
        {
            return 1 + cont;
        }
    }
    return cont;
}

void ArvBin::imprimeNivel(int k)
{
    auxImprimeNivel(raiz, 0, k);
}

void ArvBin::auxImprimeNivel(NoArv* p, int nivelAtual, int k)
{
    if ( p == NULL)
    {
        return;
    }

    if(nivelAtual == k)
    {
        cout << p->getInfo() << " ";
    }
    auxImprimeNivel(p->getEsq(), nivelAtual + 1, k);
    auxImprimeNivel(p->getDir(), nivelAtual + 1, k);
}

float ArvBin::mediaNivel(int k)
{
    int soma = 0;
    int cont = 0;
    auxMediaNivel(raiz, 0, k, &soma, &cont);
    if(cont > 0)
    {
        return (float)soma/cont;
    }
    else
    {
        return 0;
    }
}

float ArvBin::auxMediaNivel(NoArv* p, int nivelAtual, int k, int* soma, int* cont)
{
    if (p == NULL)
    {
        return 0;
    }
    if(nivelAtual == k)
    {
        (*soma) += p->getInfo();
        (*cont)++;
    }
    auxMediaNivel(p->getEsq(), nivelAtual + 1, k, soma, cont);
    auxMediaNivel(p->getDir(), nivelAtual + 1, k, soma, cont);
}

int ArvBin::minimo()
{
    return auxMinimo(raiz);
}

int ArvBin::auxMinimo(NoArv* p)
{
    if(p == NULL)
    {
        return 9999;
    }

    int menor = p->getInfo();

    int menorEsquerda = auxMinimo(p->getEsq());
    int menorDireita = auxMinimo(p->getDir());

    if(menorEsquerda < menor)
    {
        menor = menorEsquerda;
    }
    if(menorDireita < menor)
    {
        menor = menorDireita;
    }

    return menor;
}

int ArvBin::maximo()
{
    return auxMaximo(raiz);
}

int ArvBin::auxMaximo(NoArv* p)
{
    if (p == NULL)
    {
        return -999;
    }

    int maior = p->getInfo();

    int maiorEsq = auxMaximo(p->getEsq());
    int maiorDir = auxMaximo(p->getDir());

    if(maiorEsq > maior)
    {
        maior = maiorEsq;
    }

    if(maiorDir > maior)
    {
        maior = maiorDir;
    }

    return maior;
}

void ArvBin::inverte()
{
    inverteAux(raiz);
}

void ArvBin::inverteAux(NoArv* p)
{
    if (p != NULL)
    {
    if(p->getDir() != NULL && p->getEsq() != NULL)
    {
    int auxEsq = p->getEsq()->getInfo();
    int auxDir = p->getDir()->getInfo();

    p->getEsq()->setInfo(auxDir);
    p->getDir()->setInfo(auxEsq);
    }
    inverteAux(p->getEsq());
    inverteAux(p->getDir());
    }
}

int ArvBin::noMaisEsquerda()
{
    return auxNoMaisEsquerda(raiz);
}

int ArvBin::auxNoMaisEsquerda(NoArv* p)
{
    if(p == NULL)
    {
        return -1;
    }

    if(p->getEsq() != NULL)
    {
        auxNoMaisEsquerda(p->getEsq());
    }
    else
    {
        return p->getInfo();
    }
}

int ArvBin::noMaisDireita()
{
    return auxNoMaisDireita(raiz);
}

int ArvBin::auxNoMaisDireita(NoArv* p)
{
    if(p == NULL)
    {
        return 0;
    }
    if(p->getDir() != NULL)
    {
        auxNoMaisDireita(p->getDir());
    }
    else
    {
        return p->getInfo();
    }
}

int ArvBin::minSubArvore(NoArv* p)
{
    if(p == NULL)
    {
        return INT_MAX;
    }

    int minimo = p->getInfo();

    if(p->getEsq() != NULL)
    {
        int minEsq = minSubArvore(p->getEsq());
        if(minEsq < minimo)
        {
            minimo = minEsq;
        }
    }

    if(p->getDir() != NULL)
    {
        int minDir = minSubArvore(p->getDir());
        if(minDir < minimo)
        {
            minimo = minDir;
        }
    }

    return minimo;
}

int ArvBin::maxSubArvore(NoArv* p)
{
    if (p == NULL)
    {
        return INT_MIN;
    }

    int maximo = p->getInfo();

    if(p->getEsq()!= NULL)
    {
        int maxEsq = maxSubArvore(p->getEsq());
        if(maxEsq > maximo)
        {
            maximo = maxEsq;
        }
    }

    if(p->getDir() != NULL)
    {
        int maxDir = maxSubArvore(p->getDir());
        if(maxDir > maximo)
        {
            maximo = maxDir;
        }
    }
    return maximo;
}

bool ArvBin::ehABB()
{
    return auxEhABB(raiz);
}

bool ArvBin::auxEhABB(NoArv *p)
{
    if(p == NULL)
    {
        return true;
    }

    int maxEsq = maxSubArvore(p->getEsq());
    int minDir = minSubArvore(p->getDir());

    if(p->getInfo() < maxEsq || p->getInfo() > minDir)
    {
        return false;
    }

    return auxEhABB(p->getEsq()) && auxEhABB(p->getDir());
}

bool ArvBin::ehFolha(NoArv* p)
{
    return (p->getDir() == NULL && p->getEsq() == NULL);
}

int* ArvBin::criaVetFolhas(int k, int* n)
{
    *n = pow(2, k);
    int* vet = new int[*n];

    int indice = 0;
    int* pIndice = &indice;

    return auxCriaVetFolhas(raiz, vet, k, n, 0, pIndice);
}

int* ArvBin::auxCriaVetFolhas(NoArv* p,int* vet,int k,int* n,int nivelAtual, int* indice)
{
    if(p == NULL)
    {
        return NULL;
    }
    if(ehFolha(p) && nivelAtual <= k)
    {
        vet[*indice] = p->getInfo();
        (*indice)++;
    }

    auxCriaVetFolhas(p->getEsq(),vet,k, n,nivelAtual+1,indice);
    auxCriaVetFolhas(p->getDir(),vet,k,n,nivelAtual+1,indice);

    return vet;
}
*/
