#include "Prova.h"

Prova::Prova(int nq)
{
    cout << "Criando uma prova" << endl;
    n = nq;
    notasQuestoes =  new double [nq];
}

// exercicio 7
Prova::~Prova()
{
    delete[] notasQuestoes;
    cout << "Destruindo Prova" << endl;
}

void Prova::leNotas()
{
    cout << "Digite suas notas: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> notasQuestoes[i];
    }
}

void Prova::calculaNotaFinal()
{
    double menor = notasQuestoes[0];
    double soma = 0;
    for(int i = 0; i < n; i++)
    {
        if(notasQuestoes[i] < menor)
        {
            menor = notasQuestoes[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        soma+= notasQuestoes[i];
    }
    notaFinal = soma - menor;
}
double Prova::obtemNotaFinal()
{
    return notaFinal;
}





