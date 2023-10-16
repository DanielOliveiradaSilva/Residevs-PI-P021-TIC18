#pragma once

#include <iostream>
#include <vector>
#include <string>
//
using namespace std;

class Emprestimo
{
private:
    int id;
    long matricula;
    string data_emprestimo;
    vector<int> codigo_livros_emprestado;

public:
    Emprestimo(/* args */);
    ~Emprestimo();
    Emprestimo(long matricula, const string &data_emprestimo, const std::vector<int> &codigo_livros_emprestado);
    int getID() const;
    long getMatricula() const;
    string getDataEmprestimo() const;
    vector<int> getCodigoLivrosEmprestado() const;

    void setID(int id);
    void setMatricula(long matricula);
    void setDataEmprestimo(const string &data_emprestimo);
    void setCodigoLivrosEmprestado(const vector<int>codigo_livros_emprestado);
};
