#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>

using namespace std;

class Aluno
{
    public:
        Aluno(string n, string m);
        ~Aluno();

        // operacoes
        void setNome(string n);
        string getNome();

        // exercicio 1
        void leNotas();
        double calculaMedia();

        // exercicio 2
        int getIdade();
        void setIdade(int i);
        string getMatricula();
        void setMatricula(string m);
        void frequente();
        void relatorio();
        bool aprovado(double n);

        // exercicio 5
        // implemente aqui

    private:
        int idade;
        string nome, matricula;
        double notas[7];
        bool frequencia[7];

        // exercicio 3
        // implemente aqui

        // exercicio 4
        // implemente aqui
};

#endif // ALUNO_H
