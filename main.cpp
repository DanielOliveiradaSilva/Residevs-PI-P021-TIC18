#include "BD.h"

void ListarUsuario(vector<Usuario> usuarios);
void ListarLivros(vector<Livro> livros);




int main()
{
    vector<Usuario> dados_carregados = BD::CarregarDadosDeUsuarios("/home/daniel/Área de Trabalho/Biblioteca/BD/usuarios.txt");
    BD::ListarUsuario(dados_carregados);
   
    vector<Livro> dados_de_livros = BD::CarregarDadosDeLivros("/home/daniel/Área de Trabalho/Biblioteca/BD/livros.txt");
    BD::ListarLivros(dados_de_livros);

    
   vector<Emprestimo> dados_de_emprestimos = BD::CarregarDadosDeEmprestimos("/home/daniel/Área de Trabalho/Biblioteca/BD/emprestimos.txt");
   BD::ListarEmprestimos(dados_de_emprestimos);
   return 0;
 
}