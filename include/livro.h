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
        Livro(long id, string _titulo, string _autor, int _copias);
        Livro(/* args */);
        ~Livro();
        //metodos get
        
        long getId() const;
        string getTitulo() const;
        string getAutor() const;
        int getCopias() const;
        void setCodigo(long id);
        void setTitulo(string _titulo);
        void setAutor(string _autor);
        void setCopias(int _copias);
};

#endif