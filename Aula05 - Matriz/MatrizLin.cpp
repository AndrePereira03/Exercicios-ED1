#include <iostream>
#include <cstdlib>

#include "MatrizLin.h"

using namespace std;

MatrizLin::MatrizLin(int mm, int nn)
{
    cout << "Criando um objeto MatrizLin" << endl;
    nl = mm;
    nc = nn;
    vet = new float[nl*nc];
}

MatrizLin::~MatrizLin()
{
    cout << "Destruindo um objeto MatrizLin" << endl;
    delete [] vet;
}

int MatrizLin::detInd(int i, int j)//verfica se os indices i, j sao validos, alem de retornar as coordenadas i,j da matriz
{
    if(i >= 0 && i < nl && j >= 0 && j < nc)
        return nc*i + j;
    else
        return -1;
}

float MatrizLin::get(int i, int j)//retorna o valor da variavel de linha i e coluna j. Caso i ou j são invalidos, aparece a mensagem de erro.
{
    int k = detInd(i, j);
    if(k != -1)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void MatrizLin::set(int i, int j, float val)//muda o elemento de endereço i,j por val
{
    int k = detInd(i, j);
    if(k != -1)
        vet[k] = val;
    else
        cout << "ERRO: Indice invalido!" << endl;
}

int MatrizLin::getLinhas()
{
    return this->getLinhas();
}

int MatrizLin::getColunas()
{
    return this->getColunas();
}

void MatrizLin::imprime()
{
    for(int i = 0; i < nl; i++)
    {
        for(int j = 0; j < nc; j++)
        {
            float valor = j+nc*i;
            cout << valor << ", ";
        }
        cout << endl;
    }
}

bool MatrizLin::simetrica(int i, int j)
{
if(nl != nc)
{
    return false;
}
for(int i = 0; i < nl; i++)
{
    for(int i = 0; i < nc; i++)
    {
        float val1 = vet[detInd(i,j)];
        float val2 = vet[detInd(j,i)];
            if(val1 != val2)
            {
                return false;
            }
        }
    }
    return true;
}

float MatrizLin::buscaMaior()
{
    float maior;
    for(int i = 0; i < nl; i++)
    {
        for(int j = 0; j < nc; j++)
        {
            float valor = vet[detInd(i,j)];
            maior = vet[0];
            if(valor > maior)
            {
                maior = valor;
            }
        }
    }
    return maior;
}
MatrizLin* MatrizLin::transposta()
{
 int m, n;
 cout << "Digite o numero de linhas e colunas, respectivamente:" << endl;
 cin >> m >> n;
 MatrizLin* matriz = new MatrizLin(m,n);
    cout << "Matriz original: " << endl;
    for(int i = 0; i < matriz->nl; i++)
    {
        for(int j = 0; j < matriz->nc; j++)
        {
            float valor = matriz->vet[detInd(i,j)];
            matriz->get(i,j);
        }
    }
    cout << "Matriz transposta: " << endl;
    for(int i = 0; i < matriz->nl; i++)
    {
        for(int j = 0; j < matriz->nc; j++)
        {
            float valor = matriz->vet[detInd(j,i)];
            matriz->get(j,i);
        }
    }
    return matriz;
}


















