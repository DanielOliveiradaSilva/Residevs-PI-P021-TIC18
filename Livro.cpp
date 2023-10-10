#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livro
{
    private:
        string titulo;
        string autor;
        int copias;

    public:
        Livro(string _titulo, string _autor, int _copias);
        Livro(/* args */);
        ~Livro();
        string getTitulo();
        void setTitulo(string _titulo);
        string getAutor();
        void setAutor(string _autor);
        int getCopias();
        void setCopias(int _copias);
};

Livro::Livro(string _titulo, string _autor, int _copias) {
    titulo = _titulo;
    autor = _autor;
    copias = _copias;
}

Livro::Livro(/* args */)
{
}

Livro::~Livro()
{
}

string Livro::getTitulo() {
    return titulo;
}

void Livro::setTitulo(string _titulo) {
    titulo = _titulo;
}

string Livro::getAutor() {
    return autor;
}

void Livro::setAutor(string _autor) {
    autor = _autor;
}

int Livro::getCopias() {
    return copias;
}

void Livro::setCopias(int _copias) {
    copias = _copias;
}
