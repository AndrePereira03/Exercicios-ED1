#include "Aluno.h"

Aluno::Aluno(string n, string m)
{
    cout << "Criando aluno" << endl;
    nome = n;
    matricula = m;
}

Aluno::~Aluno()
{
    cout << "Destruindo objeto aluno" << endl;
}

// ----------------------------------------------------------------------------
// Exercicio 1
// ----------------------------------------------------------------------------

void Aluno::leNotas()
{
    cout << "Digite as notas:" << endl;
    for(int i = 0; i < 7; i++)
    {
    cin >> notas[i];
    }
}

double Aluno::calculaMedia()
{
    double soma = 0;
    double media;
    for(int i = 0; i < 7; i++)
    {
        soma += notas[i];
    }
    media = soma/7;
    return media;
}

// ----------------------------------------------------------------------------

void Aluno::setNome(string novo)
{
    nome = novo;
}

string Aluno::getNome()
{
    return nome;
}

// ----------------------------------------------------------------------------
// Exercicio 2
// ----------------------------------------------------------------------------

int Aluno::getIdade()
{
    return idade;
}

void Aluno::setIdade(int i)
{
    idade = i;
}

string Aluno::getMatricula()
{
    return matricula;
}

void Aluno::setMatricula(string m)
{
    matricula = m;
}
void Aluno::frequente()
{
    for(int i = 0; i < 7; i++)
    {
        cout << "Para a disciplina " << i + 1 << ", o aluno foi frequente? (Digite 1 para sim, 0 para nao)" << endl;
        cin >> frequencia[i];
    }
}
bool Aluno::aprovado(double n)
{
    if(n >= 60)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Aluno::relatorio()
{
    cout << "Relatorio do aluno:" << endl  << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Idade: " << getIdade() << endl;
    cout << "Matricula: " << getMatricula() << endl;
    for(int i = 0; i < 7; i++)
    {
        if(frequencia[i])
        {
            cout << "O aluno foi frequente na disciplina " << i+1 << "!" << endl;
        }

        else
        {
         cout << "O aluno foi infrequente na disciplina " << i+1 << "!" << endl;
        }
        if(aprovado(notas[i]))
        {
            cout << "O aluno foi aprovado na disciplina " << i+1 << "!" << endl << endl;
        }
        else
        {
            cout << "O aluno foi reprovado na disciplina " << i+1 << "!" << endl << endl;
        }
    }


}

// ----------------------------------------------------------------------------
// Exercicio 3
// ----------------------------------------------------------------------------

// Implemente aqui sua solucao

