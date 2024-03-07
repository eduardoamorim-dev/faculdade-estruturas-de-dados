/*Criar uma struct para armazenar um cliente, contendo os seguintes dados: nome, data de nascimento, idade e sexo. O sexo é apenas uma letra (M ou F) e a data de nascimento deve ser armazenada numa struct de data, com 3 inteiros (dia, mês e ano). A idade deve ser calculada quando a data de nascimento for lida, e não solicitada ao usuário. Guarde a data atual numa variável da struct de data e crie uma função para calcular a idade.

Após isso, criar um menu com 2 opções: cadastrar cliente e listar clientes. Na primeira, um cliente deve ser lido e na segunda exibidos todos os clientes em ordem de cadastro.
Trate para que seu aplicativo armazene no máximo 50 clientes ao mesmo tempo.*/



#include <iostream>

using namespace std;

    struct dataDeNascimento{
        
        int dia, mes, ano;
        
        const diaAtual = 07;
        const mesAtual = 03;
        const anoAtual = 2024;
    };


    struct cliente{
        string nome;
        int idade;
        char sexo;
        dataDeNascimento dataDeNascimento;

        void lerCliente(){
            cout << "Digite o nome do cliente: ";
            cin >> nome;

            cout << "Digite o dia de nascimento (utilize numeral): ";
            cin >> dataDeNascimento.dia;
            cout << "Digite o mes de nascimento (utilize numeral): ";
            cin >> dataDeNascimento.mes;
            cout << "Digite o ano de nascimento (utilize numeral): ";
            cin >> dataDeNascimento.ano;

            cout << "Digite o sexo cliente: ";
            cin >> sexo;
        };
    };




int main(){

    cliente cadastrar;

    cadastrar.lerCliente();

    return 0;
}
