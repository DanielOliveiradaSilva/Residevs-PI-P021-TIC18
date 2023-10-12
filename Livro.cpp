#include "lib/Livro.h"

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

long Livro::getId() {
    return id;
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
