#include "usuario.h"

Usuario::Usuario(long matricula, const string &nome, const string &email, const vector<int> &registro_de_emprestimo)
{
    this->matricula = matricula;
    this->nome = nome;
    this->email = email;
    this->registro_de_emprestimo = registro_de_emprestimo;
}

long Usuario::getMatricula() const
{
    return matricula;
}

void Usuario::setMatricula(long matricula)
{
    this->matricula = matricula;
}

string Usuario::getNome() const
{
    return nome;
}

void Usuario::setNome(const string &nome)
{
    this->nome = nome;
}

vector<int> Usuario::getRegistroDeEmprestimo() const
{
    return registro_de_emprestimo;
}

void Usuario::setRegistroDeEmprestimo(int registro_de_emprestimo)
{
    this->registro_de_emprestimo.push_back(registro_de_emprestimo);
}

string Usuario::getEmail() const
{
    return email;
}

void Usuario::setEmail(const string &email)
{
    this->email = email;
}
