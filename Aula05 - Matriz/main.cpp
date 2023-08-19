#include <iostream>
#include "MatrizLin.h"

using namespace std;

float* prodMatVetor(MatrizLin *m, float *v) {
    int numLin = m->getLinhas();
    int numCol = m->getColunas();

    // Aloca o vetor resultado dinamicamente
    float* resultado = new float[numLin];

    // Realiza a multiplicação da matriz pelo vetor
    for (int i = 0; i < numLin; i++) {
        resultado[i] = 0.0;
        for (int j = 0; j < numCol; j++) {
            resultado[i] += m->get(i, j) * v[j];
        }
    }

    return resultado;
}


int main()
{
    int m = 7, n = 8;
    MatrizLin mat(m, n);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            float val = j + n*i; /// sequencia numerica no intervalo 0..(m*n-1)
            mat.set(i, j, val);
        }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            float val = mat.get(i, j);
            cout << val << "\t";
        }
        cout << endl;
    }
    cout << endl << endl << "Exercicio 1:" << endl;
    mat.imprime();
    cout << endl << endl << "Exercicio 2:" << endl;
    if(mat.simetrica(m, n))
    {
        cout << "A matriz dada eh simetrica." << endl;
    }
    else
    {
        cout << "A matriz dada nao eh simetrica." << endl;
    }
    cout << endl << endl << "Exercicio 3:" << endl;
    cout << "O maior valor eh " << mat.buscaMaior() << endl;
    mat.transposta();
    mat.imprime();
    return 0;
}

