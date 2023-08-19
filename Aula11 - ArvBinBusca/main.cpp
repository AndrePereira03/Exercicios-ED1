#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
    ArvBinBusca arv;

    cout << "Criando Arvore Binaria de Busca (ABB)" << endl;
    arv.insere(15);
    arv.insere(9);
    arv.insere(20);
    arv.insere(7);
    arv.insere(11);
    arv.insere(18);
    arv.insere(24);
    arv.insere(6);
    arv.insere(8);
    arv.insere(10);
    arv.insere(12);
    arv.insere(17);
    arv.insere(19);
    arv.imprime();
    cout << "Existem " << arv.contaParesCaminho(19) << " numeros pares da raiz ate o numero 19." << endl;
    cout << endl;

    cout << "Media do caminho ate o no com valor 18: " << arv.mediaCaminho(18) << endl;

    cout << "Busca o valor 20: " << arv.busca(20) << endl;
    cout << "Busca o valor  5: " << arv.busca(5) << endl;
    cout << endl;
    cout << "O menor valor da arvore eh: " << arv.menor() << endl;
    cout << "O maior valor da arvore eh: " << arv.maior() << endl;

    cout << "Removendo os valores 24, 6, 7, 12, 18, 5." << endl;
    arv.remove(24);
    arv.remove(6);
    arv.remove(7);
    arv.remove(12);
    arv.remove(18);
    arv.remove(5);
    arv.removeMenor();
    arv.removeMaior();
    cout << endl;

    cout << "Arvore Binaria de Busca final:" << endl;
    arv.imprime();
    cout << "O menor valor da arvore eh: " << arv.menor() << endl;
    cout << "O maior valor da arvore eh: " << arv.maior() << endl;
    int v = 17;
    cout << "A arvore tem " << arv.contaNosFilhos(v) << " nohs com apenas um filho ate o noh " << v << endl;
    cout << "Arvore com os valores menores que 15 removidos: " << endl;
    arv.removeMen(15);
    arv.imprime();
    return 0;
}

