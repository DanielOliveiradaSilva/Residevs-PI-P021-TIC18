#include "livro.h"
//
Livro::Livro(long _id, string _titulo, string _autor, int _copias) {
    id = _id;
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

long Livro::getId() const {
    return id;
}

string Livro::getAutor() const{
    return autor;
}

string Livro::getTitulo() const{
    return titulo;
}

int Livro::getCopias() const{
    return copias;
}

void Livro::setCodigo(long _id){
    id = _id;
}
void Livro::setTitulo(string _titulo) {
    titulo = _titulo;
}

void Livro::setAutor(string _autor) {
    autor = _autor;
}

void Livro::setCopias(int _copias) {
    copias = _copias;
}
