#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"

class ListaEncad
{
public:
    ListaEncad();
    ~ListaEncad();
    bool busca(int val);            /// retorna true caso val esteja na lista e false caso contrario
    int  get(int k);                /// retorna o valor do k-ésimo elemento
    void set(int k, int val);       /// altera o valor do k-ésimo elemento
    void insereInicio(int val);     /// insere um novo No contendo val no início da lista
    void insereFinal(int val);      /// insere um novo No contendo val no final da lista
    void removeInicio();            /// remove o primeiro No da lista
    void removeFinal();             /// remove o último No da lista
    bool vazia();                   /// verifica se a lista esta vazia
    void imprime();                 /// imprime os elementos da lista
    int  numNos();                  /// retorna o numero de nos da lista
    int  buscaMaior(int val);       /// retorna a posicao do indice maior que val
    float calculaMedia();           /// calcular a media dos valores da lista
    void concatena(ListaEncad *l2); /// concatena a lista passada, com a lista atual
    ListaEncad* partir(int x);      /// parte a lista atual em duas, retornando a nova
    void insereOrdenado(int val);   /// ordena a lista atual e insere valores ordenados


    void limpar();              /// limpa a lista


private:
    No *primeiro;  /// ponteiro para o primeiro No da lista
    No *ultimo;    /// ponteiro para o ultimo No da lista
    int n;         /// numero de nos na lista
};
#endif
































 /*isso daq eh no publicvoid imprime();
    int numNos();
    int buscaMaior(int val);
    void limpar();
    float calculaMedia();
    void concatena(ListaEncad *l2);
    ListaEncad* partir(int x);
    void removeNo(int indice);
    void removeVal(int val);
    void insereOrdenado(int val);
    void insereDepoisMenor(int val);
*/
