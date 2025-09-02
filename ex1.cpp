#include <iostream> // Biblioteca padrão para entrada e saída (cin, cout, etc.)
#include <string>
#include <limits>
#ifdef _WIN32
#include <windows.h> // Biblioteca com funções específicas do Windows (API do Windows).
#endif

using namespace std;


/*
Aluno:
Vitor Hugo Campos Moura 2312130182
*/


int main(){

/*
1. Variáveis, Constantes e auto (002.cpp)
a) Declare variáveis para armazenar: nome do aluno (string), idade (int), altura
(double), aprovado (bool). Exiba-as no console.
*/

    string nomeAluno = "Vitor";
    int idade = 23;
    double altura = 1.80;
    bool aprovado = true;
    cout << "Nome do aluno: " << nomeAluno << "\n"
         << "Idade do aluno: " << idade << "\n"
         << "Altura do aluno: " << altura << "\n"
         << boolalpha << "Se " << nomeAluno << " esta aprovado: " << aprovado << "\n" ;
         
/*
b) Crie uma constante para representar o valor de π e calcule a área de um círculo
de raio 5.
*/

    const double PI = 3.14159;
    double raio = 5.0;
    double areaCirculo = (raio*raio) * PI ;
    cout << "Area do circulo de raio " << raio << ": " << areaCirculo << "\n";  

/*
2. Entrada e Saída (cin, getline) (003.cpp)
a) Peça ao usuário que digite o primeiro nome e a idade. Depois, mostre uma
mensagem: Olá, João! Você tem 20 anos.
*/

    string novoNome;
    cout << "Insira seu nome: ";
    cin >> novoNome;

    int novaIdade;
    cout << "Digite a sua idade: ";
    cin >> novaIdade;

    cout << "Olá, " << novoNome << "! Você tem " << novaIdade << " anos" << "\n";

/*
b) Agora, peça o nome completo usando getline e exiba-o no formato: Nome
completo: João da Silva.
*/

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string fullName;
    cout << "Digite seu nome completo agora: ";
    getline(cin, fullName);
    cout << "Nome completo: " << fullName << "\n";

/*
3. Operadores e Casting (004.cpp)
a) Leia dois números inteiros do usuário. Exiba: soma, subtração, multiplicação,
divisão inteira e divisão real (com casting).
*/
    int numInt1;
    int numInt2;
    cout << "Insira um numero inteiro: ";
    cin >> numInt1;

    cout << "Insira mais um numero inteiro: ";
    cin >> numInt2;
    int soma1plus2 = numInt1 + numInt2;
    cout << "Soma: " << numInt1 << " + " << numInt2 << " = " << soma1plus2 << "\n";

    int subtract = numInt1 - numInt2;
    cout << "Subtração: " << numInt1 << " + " << numInt2 << " = " << subtract << "\n";

    int multipli = numInt1*numInt2;
    cout << "Multiplicação: " << numInt1 << " + " << numInt2 << " = " << multipli << "\n";

    double divInt = numInt1/numInt2;
    cout << "Divisão Inteira: " << numInt1 << " + " << numInt2 << " = " << soma1plus2 << "\n";

    
    cout << "Divisão Real (com casting): " << numInt1 << " + " << numInt2 << " = " << soma1plus2 << "\n";




    return 0;
} 
