#ifndef LIVRO_H

#include <iostream>
#include <string>
//
using namespace std;

#define LIVRO_H

class Livro
{
    private:
        long id;
        string titulo;
        string autor;
        int copias;

    public:
        Livro(string _titulo, string _autor, int _copias);
        Livro(/* args */);
        ~Livro();
        long getId();
        string getTitulo();
        void setTitulo(string _titulo);
        string getAutor();
        void setAutor(string _autor);
        int getCopias();
        void setCopias(int _copias);
};

#endif