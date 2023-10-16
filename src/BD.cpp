#include "BD.h"
//
vector<Usuario> BD::CarregarDadosDeUsuarios(const string &url)
{
    ifstream arquivo_entrada(url);
    vector<Usuario> alunos;

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

            alunos.push_back(aluno);
        }
        arquivo_entrada.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }
    return alunos;
}

void BD::SalvarDadosDeUsuarios(const string &url, const vector<Usuario> &dados)
{
    ofstream arquivo_saida(url);
    if (arquivo_saida.is_open())
    {
        for (const Usuario &usuario : dados)
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

vector<Livro> BD::CarregarDadosDeLivros(const string &url)
{
    ifstream arquivo_entrada(url);
    vector<Livro> livros;

    if (arquivo_entrada.is_open())
    {
        string linha;
        while (getline(arquivo_entrada, linha))
        {
            Livro livro;
            string codigo;
            string titulo;
            string autor;
            string copias;
            istringstream iss(linha);
            getline(iss, codigo, ',');
            livro.setCodigo(stoi(codigo));

            getline(iss, titulo, ',');
            livro.setTitulo(titulo);

            getline(iss, autor, ',');
            livro.setAutor(autor);

            getline(iss, copias, ',');
            livro.setCopias(stoi(copias));
            livros.push_back(livro);
        }
        arquivo_entrada.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }
    return livros;
}

vector<Emprestimo> BD::CarregarDadosDeEmprestimos(const string &url)
{
    ifstream arquivo_entrada(url);
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
            vector<int> codigosLivros; // Vetor para armazenar os códigos dos livros

            while (getline(iss, codigo_do_livro, ','))
            {
                try
                {
                    int codigo = stoi(codigo_do_livro);
                    codigosLivros.push_back(codigo); // Adicione o código ao vetor
                }
                catch (const std::invalid_argument &e)
                {
                    cerr << "Erro de conversão para int: " << e.what() << endl;
                    // Trate a conversão de string para int que falhou, se necessário
                }
            }

            // Defina os códigos dos livros no objeto "emprestimo" após o loop
            emprestimo.setCodigoLivrosEmprestado(codigosLivros);
            dados_de_emprestimos.push_back(emprestimo);
        }
        arquivo_entrada.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }
    return dados_de_emprestimos;
}

void BD::ListarUsuario(vector<Usuario> usuarios)
{

    for (Usuario &usuario : usuarios)
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

void BD::ListarLivros(vector<Livro> livros)
{

    for (Livro &livro : livros)
    {
        cout << "Codigo: " << livro.getId() << endl;
        cout << "Titulo " << livro.getTitulo() << endl;
        cout << "Autor: " << livro.getAutor() << endl;
        cout << "Copias Disponiveis: " << livro.getCopias() << endl;
        cout << endl;
        cout << "---------------------------------" << endl;
    }
}

void BD::ListarEmprestimos(vector<Emprestimo> emprestimos)
{

    for (Emprestimo &emprestimo : emprestimos)
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
