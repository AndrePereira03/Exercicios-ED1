#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin arv;
    arv.montaArvore();
    arv.insere(15);
    arv.insere(25);
    arv.insere(10);
    arv.preOrdem();
    cout << endl << "A arvore tem " << arv.contaNos() << " nohs." << endl;

    cout << "A arvore tem " << arv.contaNosFolhas() << " folhas." << endl;

    cout << "A altura da arvore eh " << arv.altura() << endl;

    cout << "A arvore tem " << arv.contaImpar() << " numeros impares." << endl;

    cout << "A arvore tem " << arv.contaFolhaImpar() << " folhas impares" << endl;

    int k = 2;
    cout << "O nivel " << k << " possui os elementos: ";
    arv.imprimeNivel(k);
    cout << endl;

    cout << "A media dos valores no nivel " << k << " eh: " << arv.mediaNivel(k) << endl;

    cout << "O menor valor da arvore eh: " << arv.minimo() << endl;
    cout << "O maior valor da arvore eh: " << arv.maximo() << endl;

    cout << "O noh mais a esquerda da arvore eh: " << arv.noMaisEsquerda() << endl;
    cout << "O noh mais a direita da arvore eh: " << arv.noMaisDireita() << endl;

    cout << "A arvore eh ou nao uma ABB:  " << arv.ehABB() << endl;


    return 0;
}







































/*  cout << endl << "Numero de Nos: " << arv.contaNos() << endl;
    cout << "Numero de folhas: " << arv.contaNosFolhas() << endl;
    cout << "A altura da arvore eh: " << arv.altura() << endl;
    cout << "Existem " << arv.contaImpar() << " numeros impares" << endl;
    cout << "Existem " << arv.contaFolhaImpar() << " folhas impares" << endl;
    int k = 2;
    cout << "O nivel " << k << " possui os elementos: ";
    arv.imprimeNivel(k);
    cout << endl;
    cout << "A media dos nohs do nivel " << k << " eh igual a: " << arv.mediaNivel(k) << endl;
    cout << "O menor valor da arvore eh: " << arv.minimo() << endl;
    cout << "O maior valor da arvore eh: " << arv.maximo() << endl;
    cout << "O valor mais a esquerda da arvore eh: " << arv.noMaisEsquerda() << endl;
    cout << "O valor mais a direita da arvore eh: " << arv.noMaisDireita() << endl;
    cout << "A arvore dada eh (1) ou nao eh (0) ABB: " << arv.ehABB() << endl;
    int* p;
    int* result = arv.criaVetFolhas(3, p);
    for(int i = 0; i < 3; i++)
    {
        cout << "A" << i << "a folha antes do nivel 3 eh: " << result[i];
    }
comente daq ate
/*int* p;
arv.criaVetFolhas(3, p);
aq
    cout << "A arvore invertida fica: " << endl;
    arv.inverte();
    arv.preOrdem();
*/
