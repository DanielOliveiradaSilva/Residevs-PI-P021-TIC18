//usuario.h
#pragma once
//
#include <iostream>
#include <vector>
using namespace std;

class Usuario
{
private:
    long matricula;
    string nome;
    string email;
    vector<int> registro_de_emprestimo;

public:
    // Construtor
    Usuario() {}
    Usuario(long matricula, const string &nome, const string &email, const vector<int> &registro_de_emprestimo);

    // Métodos Get
    long getMatricula() const;
    

    string getNome() const;

    string getEmail() const;

    vector<int> getRegistroDeEmprestimo() const;

    void setRegistroDeEmprestimo(int registro_de_emprestimo);

    // Métodos Set (opcional, se você quiser permitir a modificação dos dados)

    void setMatricula(long matricula);
    void setNome(const string &nome);
    void setEmail(const string &email);
};
