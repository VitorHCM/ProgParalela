#include <iostream> // Biblioteca padrão para entrada e saída (cin, cout, etc.)
#include <string>
#include <limits>
#include <vector>
#include <memory> 


#ifdef _WIN32
#include <windows.h> // Biblioteca com funções específicas do Windows (API do Windows).
#endif

using namespace std;


/*
Aluno:
Vitor Hugo Campos Moura 2312130182
*/

/*
6. Funções e Passagem por Referência (007.cpp)
a) Implemente uma função int soma(int a, int b) e use-a no main.
*/
int soma(int a, int b);
/*
b) Crie uma função que incremente em 1 um número passado por referência.
*/
    
void incrementa(int num);

/*
9,
b) Crie uma classe ContaBancaria com: depositar(double valor), sacar(double valor),
imprimir(). Teste-a criando uma conta e fazendo operações.
*/
struct Pessoa {
    string nome;
    int idade{};
};

class ContaBancaria {
   
private:
    string titular;
    double saldo{ 0.0 }; // Inicializa��o de membro na classe.

public:
   
    ContaBancaria(const string& t, double s = 0.0) : titular(t), saldo(s) {}

    void depositar(double valor) { saldo += valor; }

    bool sacar(double valor) {
        if (valor <= saldo) { saldo -= valor; return true; }
        return false;
    }

    void imprimir() const {
        cout << "Titular: " << titular << ", Saldo: R$ " << saldo << endl;
    }
};
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
    cout << "Subtração: " << numInt1 << " - " << numInt2 << " = " << subtract << "\n";

    int multipli = numInt1*numInt2;
    cout << "Multiplicação: " << numInt1 << " * " << numInt2 << " = " << multipli << "\n";

    double divInt = numInt1/numInt2;
    cout << "Divisão Inteira: " << numInt1 << " / " << numInt2 << " = " << divInt << "\n";

    
    cout << "Divisão Real (com casting): " << numInt1 << " / " << numInt2 << " = " << (numInt1 / static_cast<double>(numInt2)) << "\n";

/*
b) Use o operador ternário para mostrar qual dos dois números é o maior.
*/
   
    if (numInt1 > numInt2){
      cout << "O numero inteiro " << numInt1 << " é maior que " << numInt2 << "\n";
    }
    else if(numInt2 > numInt1){
      cout << "O numero inteiro " << numInt2 << " é maior que " << numInt1 << "\n";
    }
    else{
        cout << "O numero inteiro " << numInt1 << " é igual a " << numInt2 << "\n";
    }
/*
4. Estruturas de Controle (005.cpp)
a) Leia uma nota (0 a 10) e mostre: 'Aprovado' (nota ≥ 6), 'Prova final' (4 ≤ nota < 6),
'Reprovado' (nota < 4).
*/
    int nota1;
    int nota2;
    cout << "Insira uma nota de 0 a 10: ";
    cin >> nota1;

    cout << "Insira uma segunda nota de 0 a 10: ";
    cin >> nota2;

    if (nota1 > nota2){
      cout << "Nota 1 " << nota1 << " é maior que nota 2 " << nota2 << "\n";
    }
    else if(nota2 > nota1){
      cout << "Nota 2 " << nota2 << " é maior que nota 1 " << nota1 << "\n";
    }
    else{
        cout << "As notas" << nota1 << " e " << nota2 << " sao iguais " << "\n";
    }
/*
b) Crie um menu (switch): 1 – Cadastrar nome, 2 – Listar nomes, 3 – Sair.
*/  

    string newNome;
    int opcao;
    
    cout << "Insira o menu desejado:\n";
    cout << " 1 : Cadastrar nome\n";
    cout << " 2 : Listar nomes\n";
    cout << " 3 : Sair\n";
    
    
    
    cin >> opcao;

    switch (opcao) {
	

	case 1:
		cout << "insira um nome: ";
        cin >> newNome;

		break;
	case 2:
		cout << newNome << endl;
		break;
	case 3:
		cout << "Saindo..." << endl;
		break;
		
	default:
		cout << "Opcaoo invalida" << endl;
		
		break;
	}
/*
5. Laços (for, while, do-while) (006.cpp)
a) Escreva um programa que exiba todos os números ímpares de 1 a 20.
*/

	cout << "numeros impares de 1 a 20: ";
    for (int i = 1; i <= 20; ++i) {
        if (i % 2 != 0){
            //num impar
            cout << i << " ";
        }

    }
    cout << "\n";
	cout << endl;
/*
b) Implemente um contador regressivo de 10 até 0 usando while.
*/  
    cout << "numeros de 10 a 0 em ordem regressiva\n";
    int counter = 10;
    do{
        cout << counter << " ";
        counter --;
    }while(counter > -1);
/*
c) Simule um menu que só termina quando o usuário digitar 0, usando do-while.
*/  
    int menu = 1;
    do
    {
        cout << "insira o menu que voce quer escolher\n1 : Menu 1\n2 : Menu2\n0 : Sair\n";
        cin >> menu; 
    } while (menu > 0);
    
/*
7. Arrays e std::vector (008.cpp)
a) Crie um array de 5 inteiros e calcule a soma dos elementos.
*/
    int array[5] = { 1, 2, 3, 4, 5 };

	int sumArray = 0;
	for (int i = 0; i < 5; ++i) {
		sumArray += array[i];
	}
	cout << "Soma do array de 5 elementos = " << sumArray << endl;
/*
b) Crie um vector<int> com os valores {5, 10, 15} e insira mais dois números usando
push_back. Exiba o tamanho e a soma.
*/
    vector<int> vetor { 5, 10, 15 };
    vetor.push_back(2);
    vetor.push_back(4);
    int sumVetor = 0;
    for (int x : vetor) sumVetor += x;
	cout << "Soma dos valores do vetor: " << sumVetor << endl;
    cout << "Tamanho do vetor = " << vetor.size() << endl;
/*
8. Ponteiros e Referências (009.cpp)
a) Declare uma variável int x = 10. Use um ponteiro para dobrar o valor e uma
referência para triplicá-lo.
*/
    int x = 10;

    int* px = &x;

    *px *= 2;

    x *= 3;
/*
b) Crie um ponteiro dinâmico para armazenar um número e libere a memória com
delete.
*/
int* pHeap = new int(42);
    cout << "*pHeap = " << *pHeap << endl;

    delete pHeap;
/*
9. Struct e Classe (010.cpp)
a) Crie uma struct Aluno com nome e idade. Leia os dados do teclado e exiba-os.
*/
struct Aluno {
    string nome;
    int idade{};
}aluno;

    cout << "insira nome do aluno: ";
    cin >> aluno.nome;
    cout << "insira a idade do aluno: ";
    cin >> aluno.idade;

    cout << "nome aluno: " << aluno.nome << " idade aluno: "<< aluno.idade << endl;
/*
b) Crie uma classe ContaBancaria com: depositar(double valor), sacar(double valor),
imprimir(). Teste-a criando uma conta e fazendo operações.
*/
Pessoa p{ "Rodrigo", 35 };
    // . (ponto): � o "operador de acesso a membro". Usado para acessar os membros p�blicos de um objeto `struct` ou `class`.
    cout << p.nome << ", " << p.idade << " anos" << endl;

    // Cria um objeto `c` da classe `ContaBancaria`. O construtor � chamado aqui com "Maria" e 100.0.
    ContaBancaria c{ "Maria", 100.0 };
    // c.depositar(50);: Chama o m�todo `depositar` no objeto `c`. O estado interno de `c` (seu saldo) � modificado.
    c.depositar(50);
    if (!c.sacar(200)) cout << "Saldo insuficiente" << endl;
    // c.imprimir();: Chama o m�todo `imprimir`, que l� e exibe o estado atual do objeto.
    c.imprimir();
/*

*/

/*

*/

    return 0;
} 
/*
6.
c) Faça sobrecarga de função soma para receber 3 inteiros.
*/
int soma(int a, int b, int c){
    return a + b + c ;
}

void incrementa(int& num){
    num += 1;
}
