#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    float mediaCaminho(int ch);
    int maior();
    int menor();
    void removeMaior();
    void removeMenor();
    int contaParesCaminho(int x);
    void TrocaSubArvore(NoArv* p);
    int classificaFilhos(NoArv* pai);
    int contaNosFilhos(int val);
    NoArv* removeMen(int val);

private:
    NoArv* raiz; // ponteiro para o No raiz da árvore
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* menorSubArvDireita(NoArv *p);
    NoArv* removeFolha(NoArv *p);
    NoArv* remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv* p, int nivel);
    NoArv* libera(NoArv *p);
    int auxMaior(NoArv* p);
    int auxMenor(NoArv* p);
    int auxContaParesCaminho(NoArv* p, int valor, int* cont);
    void auxTrocaSubArvore(NoArv* p, NoArv* atual, NoArv* maiorEsq);
    int auxContaNosFilhos(NoArv* p,int *cont, int val);
    NoArv* auxRemoveMenor(NoArv* p, int val);
};

#endif // ARVBINBUSCA_H_INCLUDED
