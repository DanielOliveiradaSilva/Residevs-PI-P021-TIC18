#pragma once

#include "usuario.h"
#include "livro.h"
#include "emprestimo.h"
#include <iostream>
#include <vector>

#include <fstream>
#include <sstream>

using namespace std;
class BD
{
private:
    static vector<Usuario> dados_dos_usuarios;

public:
    BD() {} // Inicializar o vetor de dados de usuários, se necessário.

    ~BD() {} // Limpar os recursos, se necessário.
    static vector<Usuario> CarregarDadosDeUsuarios(const string &url);
    static void SalvarDadosDeUsuarios(const string &url, const vector<Usuario> &dados);

    static vector<Livro> CarregarDadosDeLivros(const string &url);
    static void SalvarDadosDeLivros(const string &url, const vector<Usuario> &dados);

    static vector<Emprestimo> CarregarDadosDeEmprestimos(const string &url);

    static void ListarUsuario(vector<Usuario> usuarios);
    static void ListarLivros(vector<Livro> livros);
    static void ListarEmprestimos(vector<Emprestimo> emprestimos);
};

