#include "livro.h"

Livro::Livro(long _id, const string &_titulo, const string &_autor, int _copias) {
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

long Livro::getId() const{
    return id;
}

string Livro::getTitulo() const {
    return titulo;
}

string Livro::getAutor() const{
    return autor;   
}
int Livro::getCopias() const{
    return copias;
}

void Livro:: setId(long _id){
    id = _id;
}
void Livro::setTitulo(const string &_titulo) {
    titulo = _titulo;
}

void Livro::setAutor(const string &_autor) {
    autor = _autor;
}

void Livro::setCopias(int _copias) {
    copias = _copias;
}
bool Livro::emprestarLivro() {
    if (copias > 0) {
        copias--;
        return true;
    }
    return false;
}

void Livro::devolverLivro() {
    copias++;
}
