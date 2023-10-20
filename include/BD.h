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
public:
     vector<Usuario> dados_dos_usuarios;
     vector<Livro> dados_de_livros;
     vector<Emprestimo> dados_de_emprestimos;

    BD() {} // Inicializar o vetor de dados de usuários, se necessário.

    ~BD() {} // Limpar os recursos, se necessário.
    
     void CarregarDadosDeUsuarios();
     void SalvarDadosDeUsuarios();

     void CarregarDadosDeLivros();
     void SalvarDadosDeLivros();

     void CarregarDadosDeEmprestimos();
     void SalvarDadosDeEmprestimo();

     void ListarUsuario();
     void ListarLivros();
     void ListarEmprestimos();
     void RegistrarEmprestimo(Usuario& usuario,  vector<Livro>& livros, const string& data_emprestimo);
     Usuario* localizarUsuarioPorMatricula(long matricula);
     Livro* localizarLivroPorTitulo(const string& titulo)
};

