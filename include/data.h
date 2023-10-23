#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <cmath>

class Data 
{
    private:
        int dia, 
            mes, 
            ano;
        std::string formato;

    public:
        /* MÉTODOS CONSTRUTORES */

        Data();
        Data(int = 1, int = 1, int = pegarDataAtual().getAno());

        /* PROTÓTIPOS DOS MÉTODOS */
        
        int setData(int, int, int);                                     // Setar o objeto de Data, validando os dados passados
        int setData(std::string);                                       // Sobrecarga da função de set, recebendo como parâmetro uma string
        int getDia();
        int getMes();
        int getAno();                                               
        int operator-(const Data&);                                     // Sobrecarga do operador - para criar diferença entre datas
        static Data pegarDataAtual();                                   // Pegar a data atual do sistema
        static void separarNumeros(std::string, int &, int &, int &);   // Receber data como string e devolver cada número a uma variável inteira
        static bool isDataValida(int, int, int);                        // Verificar se a data fornecida é válida
        static bool isDataValida(std::string);                          // Sobrecarga da função, recebendo como parâmetro uma string e convertendo para inteiro
        static bool isBissexto(int);                                    // Verificar se certo ano é bissexto
        static int calcularDiferencaDias(Data, Data);                   // Calcular a diferença de dias entre datas                
};