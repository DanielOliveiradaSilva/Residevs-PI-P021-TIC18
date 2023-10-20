#include "BD.h"

void BD::CarregarDadosDeUsuarios()
{
    ifstream arquivo_entrada("../BD/usuarios.txt");

    if (arquivo_entrada.is_open())
    {
        string linha;
        while (getline(arquivo_entrada, linha))
        {
            Usuario aluno;
            string matricula;
            string nome;
            string email;
            string codigo_de_emprestimo;

            istringstream iss(linha);
            getline(iss, matricula, ',');
            aluno.setMatricula(stoi(matricula));

            getline(iss, nome, ',');
            aluno.setNome(nome);

            getline(iss, email, ',');
            aluno.setEmail(email);
            while (getline(iss, codigo_de_emprestimo, ','))
            {
                aluno.setRegistroDeEmprestimo(stoi(codigo_de_emprestimo));
            }

            dados_dos_usuarios.push_back(aluno);
        }
        arquivo_entrada.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

void BD::SalvarDadosDeUsuarios()
{
    ofstream arquivo_saida("../BD/usuarios.txt");
    if (arquivo_saida.is_open())
    {
        for (const Usuario &usuario : dados_dos_usuarios)
        {
            arquivo_saida << usuario.getMatricula() << ","
                          << usuario.getNome() << ","
                          << usuario.getEmail() << ",";
            const vector<int> registros = usuario.getRegistroDeEmprestimo();
            for (size_t i = 0; i < registros.size(); i++)
            {
                arquivo_saida << registros[i];
                if (i < registros.size() - 1)
                {
                    arquivo_saida << ",";
                }
            }
            arquivo_saida << endl;
        }
        arquivo_saida.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo de saída" << endl;
    }
}

void BD::CarregarDadosDeLivros()
{
    ifstream arquivo_entrada("../BD/livros.txt");

    if (arquivo_entrada.is_open())
    {
        string linha;
        while (getline(arquivo_entrada, linha))
        {
            Livro livro;
            string id;
            string titulo;
            string autor;
            string copias;
            istringstream iss(linha);
            getline(iss, id, ',');
            livro.setId(stol(id));

            getline(iss, titulo, ',');
            livro.setTitulo(titulo);

            getline(iss, autor, ',');
            livro.setAutor(autor);

            getline(iss, copias, ',');
            livro.setCopias(stoi(copias));
            dados_de_livros.push_back(livro);
        }
        arquivo_entrada.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

void BD::CarregarDadosDeEmprestimos()
{
    ifstream arquivo_entrada("../BD/emprestimos.txt");
    vector<Emprestimo> dados_de_emprestimos;

    if (arquivo_entrada.is_open())
    {
        string linha;
        while (getline(arquivo_entrada, linha))
        {
            Emprestimo emprestimo;

            // Use um stringstream para dividir a linha em partes separadas por vírgula
            istringstream iss(linha);

            string id;
            if (getline(iss, id, ','))
            {
                try
                {
                    emprestimo.setID(stoi(id));
                }
                catch (const std::invalid_argument &e)
                {
                    // Trate a conversão de string para int que falhou
                    cerr << "Erro de conversão para int: " << e.what() << endl;
                }
            }

            string matricula;
            if (getline(iss, matricula, ','))
            {
                emprestimo.setMatricula(stol(matricula)); // Use stol para converter para long
            }

            string data_de_emprestimo;
            if (getline(iss, data_de_emprestimo, ','))
            {
                emprestimo.setDataEmprestimo(data_de_emprestimo);
            }

            string codigo_do_livro;
            vector<long> codigosLivros; // Vetor para armazenar os códigos dos livros

            while (getline(iss, codigo_do_livro, ','))
            {
                try
                {
                    long codigo = stoul(codigo_do_livro);
                    emprestimo.setCodigoLivrosEmprestado(codigo);
                }
                catch (const std::invalid_argument &e)
                {
                    cerr << "Erro de conversão para int: " << e.what() << endl;
                    // Trate a conversão de string para int que falhou, se necessário
                }
            }

            // Defina os códigos dos livros no objeto "emprestimo" após o loop
            dados_de_emprestimos.push_back(emprestimo);
        }
        arquivo_entrada.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

 void BD::SalvarDadosDeEmprestimo()
{
    ofstream arquivo_saida("../BD/emprestimos.txt");
    
    if (arquivo_saida.is_open())
    {
        for (const Emprestimo& emprestimo : dados_de_emprestimos)
        {
            arquivo_saida << emprestimo.getID() << ','
                         << emprestimo.getMatricula() << ','
                         << emprestimo.getDataEmprestimo() << ',';

            const vector<long>& codigosLivros = emprestimo.getCodigoLivrosEmprestado();
            for (size_t i = 0; i < codigosLivros.size(); i++)
            {
                arquivo_saida << codigosLivros[i];
                if (i < codigosLivros.size() - 1)
                {
                    arquivo_saida << ',';
                }
            }

            arquivo_saida << '\n'; // Pule para a próxima linha para o próximo empréstimo
        }
        arquivo_saida.close();
        cout << "Dados de empréstimos salvos com sucesso." << endl;
    }
    else
    {
        cerr << "Erro ao abrir o arquivo para escrita" << endl;
    }
}

void BD::ListarUsuario()
{

    for (Usuario &usuario : dados_dos_usuarios)
    {
        cout << "Matrícula: " << usuario.getMatricula() << endl;
        cout << "Nome: " << usuario.getNome() << endl;
        cout << "Email: " << usuario.getEmail() << endl;

        cout << "Registros de empréstimo: ";
        for (int registro : usuario.getRegistroDeEmprestimo())
        {
            cout << registro << " ";
        }
        cout << endl;
        cout << "---------------------------------" << endl;
    }
}

void BD::ListarLivros()
{

    for (Livro &livro : dados_de_livros)
    {
        cout << "Codigo: " << livro.getId() << endl;
        cout << "Titulo " << livro.getTitulo() << endl;
        cout << "Autor: " << livro.getAutor() << endl;
        cout << "Copias Disponiveis: " << livro.getCopias() << endl;
        cout << endl;
        cout << "---------------------------------" << endl;
    }
}

void BD::ListarEmprestimos()
{

    for (Emprestimo &emprestimo : dados_de_emprestimos)
    {
        cout << "Codigo: " << emprestimo.getID() << endl;
        cout << "Matricula " << emprestimo.getMatricula() << endl;
        cout << "Data de Registro: " << emprestimo.getDataEmprestimo() << endl;

        cout << "Registros de Livros: ";

        for (int registro : emprestimo.getCodigoLivrosEmprestado())
        {
            cout << registro << " ";
        }
        cout << endl;
        cout << "---------------------------------" << endl;
    }
}

void BD :: RegistrarEmprestimo(Usuario& usuario, vector<Livro>& livros, const string& data_emprestimo) {
   for (auto& livro : livros)
   {
        Emprestimo emprestimo;
        emprestimo.setMatricula(usuario.getMatricula());
        emprestimo.setDataEmprestimo(data_emprestimo);
        emprestimo.setCodigoLivrosEmprestado(livro.getId());
            
        livro.emprestarLivro();
        usuario.setRegistroDeEmprestimo(emprestimo.getID());
        dados_de_emprestimos.push_back(emprestimo);
   }
    BD :: SalvarDadosDeEmprestimo();
    
}
// Função para localizar um usuário por matrícula
Usuario* BD :: localizarUsuarioPorMatricula(long matricula)
{
    for (Usuario& usuario : dados_dos_usuarios)
    {
        if (usuario.getMatricula() == matricula)
        {
            return &usuario;
        }
    }
    return nullptr; // Retorna nullptr se o usuário não for encontrado
}
// Função para localizar um livro por título
Livro BD :: localizarLivroPorID(long id)
{
    for (Livro& livro : dados_de_livros)
    {
        if (livro.getId() == id)
        {
            return livro;
        }
    }
    return {}; // Retorna nullptr se o livro não for encontrado
}