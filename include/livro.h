#pragma once
#include <iostream>

using namespace std;

class Livro
{
private:
    long id;
    string titulo;
    string autor;
    int copias;

public:
    Livro(/* args */);
    ~Livro();
    // Construtor
    Livro(long id, const string &titulo, const string &autor, int _copias);

    // Métodos Get
    long getId() const;
    string getTitulo() const;
    string getAutor() const;
    int getCopias() const;

    // Métodos Set
    void setId(long _id);
    void setTitulo(const string &titulo);
    void setAutor(const string &autor);
    void setCopias(int copias);
    bool emprestarLivro(); //decrementa copias
    void devolverLivro(); //incrementa copias
};