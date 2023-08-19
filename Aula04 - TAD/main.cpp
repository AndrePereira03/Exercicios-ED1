#include <iostream>
#include "Aluno.h"
#include "Prova.h"

using namespace std;

int main()
{
    cout << "LABORATORIO DE PROGRAMACAO II - AULA 04\n" << endl << endl << "Exercicio 1:" << endl;

    // ------------------------------------------------------------------------
    // EXERCICIO 1
    // ------------------------------------------------------------------------
    Aluno a("Carlos", "201566123AB");

    // leitura das notas do aluno
    a.leNotas();
    double m = a.calculaMedia();

    cout << "Media do aluno: " << m << endl << endl << "Exercicios 2 e 3:" << endl ;

    // ------------------------------------------------------------------------
    // EXERCICIO 3
    // ------------------------------------------------------------------------
    int novaIdade;
    string novaMatricula;
    cout << "Idade atual: " << a.getIdade() << endl;
    cout << "Digite a nova idade: " << endl;
    cin >> novaIdade;
    a.setIdade(novaIdade);
    cout << "Idade alterada para " << a.getIdade() << endl;
    cout << "Matricula atual: " << a.getMatricula() << endl;
    cout << "Digite a nova matricula: " << endl;
    cin >> novaMatricula;
    a.setMatricula(novaMatricula);
    cout << "Matricula alterada para " << a.getMatricula() << endl << endl << "Exercicios 4 e 5:" << endl;


    // ------------------------------------------------------------------------
    // EXERCICIO 5
    // ------------------------------------------------------------------------

    a.frequente();


    // ------------------------------------------------------------------------
    // EXERCICIO 6
    // ------------------------------------------------------------------------

    a.relatorio();

    // ------------------------------------------------------------------------
    // EXERCICIO 7
    // ------------------------------------------------------------------------

    Prova p(3);
    p.leNotas();
    p.calculaNotaFinal();
    cout << "A nota final eh: "<< p.obtemNotaFinal() << endl;











    return 0;
}
