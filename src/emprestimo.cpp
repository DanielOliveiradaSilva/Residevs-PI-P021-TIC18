#include "emprestimo.h"
Emprestimo::Emprestimo(/* args */) {}

// Construtor//
Emprestimo::Emprestimo(long matricula, const std::string &data_emprestimo, const std::vector<int> &codigo_livros_emprestado)
{
    this->matricula = matricula;
    this->data_emprestimo = data_emprestimo;
    this->codigo_livros_emprestado = codigo_livros_emprestado;
    
}

// Getters
int Emprestimo::getID() const{
    return id;
}

long Emprestimo:: getMatricula() const
{
    return matricula;
}

string Emprestimo::getDataEmprestimo() const
{
    return data_emprestimo;
}

vector<int> Emprestimo::getCodigoLivrosEmprestado() const
{
    return codigo_livros_emprestado;
}

// Setters
void Emprestimo::setID(int id){
    this->id = id;
}

void Emprestimo::setMatricula(long matricula)
{
    this->matricula = matricula;
}

void Emprestimo::setDataEmprestimo(const string &data_emprestimo)
{
    this->data_emprestimo = data_emprestimo;
}

void Emprestimo::setCodigoLivrosEmprestado(const vector<int>codigo_livros_emprestado)
{
    this->codigo_livros_emprestado =codigo_livros_emprestado;
}

Emprestimo::~Emprestimo() {}