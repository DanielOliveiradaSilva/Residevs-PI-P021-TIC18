#include "BD.h"
#include <filesystem>
void ListarUsuario(vector<Usuario> usuarios);
void ListarLivros(vector<Livro> livros);

int main()
{



    vector<Usuario> dados_carregados = BD::CarregarDadosDeUsuarios("../BD/usuarios.txt");
    BD::ListarUsuario(dados_carregados);

    vector<Livro> dados_de_livros = BD::CarregarDadosDeLivros("../BD/livros.txt");
    BD::ListarLivros(dados_de_livros);

    vector<Emprestimo> dados_de_emprestimos = BD::CarregarDadosDeEmprestimos("../BD/emprestimos.txt");
    BD::ListarEmprestimos(dados_de_emprestimos);
    return 0;
}