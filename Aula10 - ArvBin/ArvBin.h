#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    int contaNos();
    bool ehFolha(NoArv* p);
    int contaNosFolhas();
    int altura();
    int contaImpar();
    int contaFolhaImpar();
    void imprimeNivel(int k);
    float mediaNivel(int k);
    int minimo();
    int maximo();
    void inverteFilhos(NoArv* p);
    int noMaisEsquerda();
    int noMaisDireita();
    bool ehABB();

  private:
    NoArv *raiz; // ponteiro para o No raiz da árvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxInverte(NoArv * p);
    NoArv* auxInsere(NoArv *p, int x);
    int auxContaNos(NoArv* p);
    int auxContaNosFolhas(NoArv* p);
    int auxAltura(NoArv* p);
    int auxContaImpar(NoArv* p);
    int auxContaFolhaImpar(NoArv* p);
    void auxImprimeNivel(NoArv* p, int nivelAtual, int k);
    float auxMediaNivel(NoArv* p, int nivelAtual, int k, float* soma, int* cont);
    int auxMinimo(NoArv* p);
    int auxMaximo(NoArv* p);
    void auxInverteFilhos(NoArv* p);
    int auxNoMaisEsquerda(NoArv* p);
    int auxNoMaisDireita(NoArv* p);
    bool auxEhABB(NoArv *p);
};



























 /*int contaNos();
    int contaNosFolhas();
    int altura();
    int contaImpar();
    int contaFolhaImpar();
    void imprimeNivel(int k);
    float mediaNivel(int k);
    int minimo();
    int maximo();
    void inverte();
    int noMaisEsquerda();
    int noMaisDireita();
    int minSubArvore(NoArv *p);
    int maxSubArvore(NoArv *p);
    bool ehABB();
    int* criaVetFolhas(int k, int* n);
    bool ehFolha(NoArv* p);
*/




 /*int auxContaNos(NoArv *p);
    int auxContaNosFolhas(NoArv* p);
    int auxAltura(NoArv* p);
    int auxContaImpar(NoArv* p);
    int auxContaFolhaImpar(NoArv* p);
    void auxImprimeNivel(NoArv* p, int nivelAtual, int k);
    float auxMediaNivel(NoArv* p, int nivelAtual, int k, int* soma, int* cont);
    int auxMinimo(NoArv* p);
    int auxMaximo(NoArv* p);
    void inverteAux(NoArv* p);
    int auxNoMaisEsquerda(NoArv* p);
    int auxNoMaisDireita(NoArv* p);
    bool auxEhABB(NoArv *p);
    int* auxCriaVetFolhas(NoArv* p,int* vet,int k,int* n,int nivelAtual, int* indice);*/

#endif // ARVBIN_H_INCLUDED
