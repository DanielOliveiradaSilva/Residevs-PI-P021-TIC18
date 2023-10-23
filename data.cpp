#include "data.h"

/* MÉTODOS DA CLASSE */

Data::Data() {
    dia = 1;
    mes = 1;
    ano = 1900;
}

Data::Data(int _dia, int _mes, int _ano) {
    this->dia = _dia;
    this->mes = _mes;
    this->ano = _ano;
}

int Data::setData(int _dia, int _mes, int _ano) 
{
    if ( Data::isDataValida(_dia, _mes, _ano) ) 
    {
        this->dia = _dia;
        this->mes = _mes;
        this->ano = _ano;

        return 1;
    }

    return 0;
}

int Data::setData(std::string _data) 
{
    int dia, mes, ano;

    Data::separarNumeros(_data, dia, mes, ano);

    return setData(dia, mes, ano);
}

int Data::getDia() {
    return dia;
}

int Data::getMes() {
    return mes;
}

int Data::getAno() {
    return ano;
}

int Data::operator-(const Data& outro) 
{
    
    int diff_anos = (this->ano - outro.ano) * 365;
    float diff_meses = (this->mes - outro.mes) * ( (isBissexto(this->ano) ? 366.0 : 365.0) / 12.0 );
    int diff_dias = this->dia - outro.dia;

    return round(diff_dias + diff_meses + diff_anos);
}

int Data::calcularDiferencaDias(Data data1, Data data2)
{
    return data1 - data2;
}

Data Data::pegarDataAtual() 
{
    // obter a data e hora atual
    std::time_t tempo_atual = std::time(nullptr);

    // converter o tempo atual para uma estrutura de tm (tempo)
    std::tm *data_hora = std::localtime(&tempo_atual);

    // acessar os componentes de data e hora
    int ano = data_hora->tm_year + 1900;        // Ano atual
    int mes = data_hora->tm_mon + 1;            // Mês atual (0-11)
    int dia = data_hora->tm_mday;               // Dia atual

    Data data = {dia, mes, ano};

    return data;
}

void Data::separarNumeros(std::string data, int &dia, int &mes, int &ano)
{
    std::istringstream iss(data);
    std::string numeros_data[3] = {"01", 
                              "01", 
                               std::to_string(pegarDataAtual().getAno())};
    std::string substring;
    int i = 0;
    
    while (getline(iss, substring, '/')) {
        numeros_data[i] = substring;
        i++;
    }

    dia = stoi(numeros_data[0]);
    mes = stoi(numeros_data[1]);
    ano = stoi(numeros_data[2]);
} 
    
bool Data::isDataValida(int dia, int mes, int ano)
{    
    // pegar diferença de dias da data atual do sistema para a fornecida. se menor que 0, data não existe
    int diferenca_dias = calcularDiferencaDias(pegarDataAtual(), {dia, mes, ano});

    // validações
    if ( ano >= 0 && diferenca_dias >= 0 && mes >= 1 && mes <= 12) {
        switch (mes) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return dia >= 1 && dia <= 31;
            case 4: case 6: case 9: case 11:
                return dia >= 1 && dia <= 30;
            case 2:
                if (isBissexto(ano)) {
                    return dia >= 1 && dia <= 29;
                } else {
                    return dia >= 1 && dia <= 28;
                }
        }
    }

    return false;
}

bool Data::isDataValida(std::string data) 
{
    int dia, mes, ano;

    Data::separarNumeros(data, dia, mes, ano);

    return isDataValida(dia, mes, ano);
}

bool Data::isBissexto(int ano) 
{
    return ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0);
}