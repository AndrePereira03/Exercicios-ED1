#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"

using namespace std;

   /* int* inverte(int *vet, int n)
    {
        PilhaEncad p;

        for(int i = 0; i < n; i++) p.empilha(vet[i]);
        for(int i = 0; i < n; i++) vet[i] = p.desempilha();

        return vet;
    }

    void inverteFila(FilaEncad *f)
    {
        PilhaEncad pAux;

        while(f->vazia() == false) pAux.empilha(f->desenfileira());
        while(pAux.vazia() == false) f->enfileira(pAux.desempilha());
    }

    FilaEncad* concatena(FilaEncad *f1, FilaEncad *f2)
    {
        FilaEncad* f3 = new FilaEncad();
        while(f1->vazia() == false) f3->enfileira(f1->desenfileira());
        while(f2->vazia() == false) f3->enfileira(f2->desenfileira());

       f3->removeIgual();

        return f3;
    }

    void removeDaPilha(PilhaEncad *p, int x)
    {
        PilhaEncad pAux;

        while(!p->vazia())
        {
            if(p->getTopo() == x) p->desempilha();
            else pAux.empilha(p->desempilha());
        }

        while(!pAux.vazia()) p->empilha(pAux.desempilha());
    }

    FilaEncad* intercala(FilaEncad* f1, FilaEncad* f2)
{
    FilaEncad* f3;
    while(!f1->vazia() || !f2->vazia())
    {
        if(!f1->vazia())
            f3->enfileira(f1->desenfileira());
        if(!f2->vazia())
        f3->enfileira(f2->desenfileira());
    }
    return f3;
}
*/









void imprimeVet(int* vet, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
}

int* inverte(int *vet, int n)
{
    PilhaEncad p;

    for(int i = 0; i < n; i++)
    {
        p.empilha(vet[i]);
    }
    for(int i = 0; i < n; i++)
    {
        vet[i] = p.desempilha();
    }
    return vet;
}

void inverteFila(FilaEncad *f)
{
    PilhaEncad pAux;
    while(!(f->vazia()))
    {
        pAux.empilha(f->desenfileira());
    }
    while((!pAux.vazia()))
    {
        f->enfileira(pAux.desempilha());
    }
}

FilaEncad* concatena(FilaEncad *f1, FilaEncad *f2)
{
    if(f1->vazia() && f2->vazia())
    {
        cout << "Ambas as filas estao vazias." << endl;
        return NULL;
    }
    else if(f1->vazia())
    {
        return f2;
    }
    else if(f2->vazia())
    {
        return f1;
    }
    else
    {
        FilaEncad* f3 = new FilaEncad();
        while(!f1->vazia())
        {
            f3->enfileira(f1->desenfileira());
        }
        while(!f2->vazia())
        {
            f3->enfileira(f2->desenfileira());
        }
        return f3;
    }
}

void removeDaPilha(PilhaEncad *p, int x)
{
    if(p->vazia())
    {
        cout << "A pilha dada esta vazia!" << endl;
    }
    else
    {
        PilhaEncad pAux;
        bool existeX = false;
        while(!p->vazia() && existeX == false)
        {
            if(p->getTopo() == x)
            {
                p->desempilha();
                existeX = true;
            }
            else
            {
                pAux.empilha(p->desempilha());
            }
        }
        if(!existeX)
        {
            cout << "O valor dado nao existe na Pilha." << endl;
        }
            while(!pAux.vazia())
            {
                p->empilha(pAux.desempilha());
            }
    }
}



int main()
{
    /// TESTE COM PILHA
    PilhaEncad p;

    for(int i = 0; i < 5; i++) p.empilha(i);
    cout << "Pilha apos inserir 5 valores" << endl;
    p.imprime();

    for(int i = 20; i < 25; i++) p.empilha(i);
    cout << "Pilha apos inserir mais 5 valores" << endl;
    p.imprime();

    cout << "A Pilha tem " << p.tamanho() << " elementos!" << endl;

    /// TESTE COM FILA

    FilaEncad f;
    for(int i=0; i<5; i++) f.enfileira(i);
    cout << "Fila apos inserir 5 valores" << endl;
    f.imprime();

    for(int i = 20; i < 25; i++) f.enfileira(i);
    cout << "Fila apos inserir mais 5 valores" << endl;
    f.imprime();


    ///QUESTAO 3

    int n = 6;
    int* vet = new int[n];

    for(int i = 0; i < n; i++)
    {
        vet[i] = (i*i) + 1;
    }

    cout << "Vetor antes da inversao: " << endl;
    imprimeVet(vet, n);
    inverte(vet, n);
    cout << "Vetor apos a inversao: " << endl;
    imprimeVet(vet, n);

    ///QUESTAO 4
    cout << "Invertendo a fila: " << endl;
    inverteFila(&f);
    cout << "Invertendo a fila: " << endl;
    f.imprime();

    ///QUESTAO 5
    FilaEncad f2;
    for(int i = 0; i < 5; i++)
    {
        f2.enfileira(i);
    }

    FilaEncad* f3 = new FilaEncad();
    f3 = concatena(&f, &f2);
    cout << "Imprimindo f1, f2, f3 apos a concatenacao (f1 e f2 vazias, f3 = f1 + f2)." << endl;
    f.imprime();
    f2.imprime();
    f3->imprime();

    ///QUESTAO 6
    PilhaEncad p2;
    for(int i = 0; i < 9; i++)
    {
        p2.empilha(i);
    }
    cout << "Imprimindo uma nova pilha p2: " << endl;
    p2.imprime();

    removeDaPilha(&p2, 8);
    cout << "Removendo o valor 8 da pilha: " << endl;
    p2.imprime();





































    // QUESTÃO 2
/*
    cout << "A pilha tem " << p.tamanho() << " elementos." << endl;

    //QUESTÃO 3

    int n;
    cout << "Digite quantos elementos tera seu vetor:" << endl;
    cin >> n;
    int* vetor = new int [n];
    cout << "Vetor antes de ser invertido:" << endl;
    for(int i = 0; i < n; i++)
    {
        vetor[i] = i + 1;
        cout << vetor[i] << " ";
    }
    cout << endl;
    inverte(vetor, n);
    cout << "Vetor apos ser invertido:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    //QUESTAO 4

    cout << "Fila invertida:" << endl;
    inverteFila(&f);
    f.imprime();

    //QUESTAO 5

    FilaEncad f2;
    for(int i = 0; i < 10; i++)
    {
        f2.enfileira(i*i);
    }
    cout << "Fila 1:" << endl;
    f.imprime();
    cout << "Fila 2:" << endl;
    f2.imprime();
    cout << "Filas concatenadas:" << endl;
    FilaEncad* f3;
    f3 = concatena(&f, &f2);
    f3->imprime();
    cout << "Como ficou f1 e f2 depois da concatenacao:" << endl;
    f.imprime();
    f2.imprime();
    cout << endl;

    //QUESTAO 6

    cout << "Removendo o elemento 24 da pilha:" << endl;
    removeDaPilha(&p, 24);
    p.imprime();

    FilaEncad* f4;
    f4 = intercala(&f, &f2);
    f4->imprime();*/
    return 0;
}

















