/*-------------------------------------------------------------------------------------------------------------------------
Disciplina: Programa��o Paralela.
Autor.....: Prof. Rodrigo Gon�alves
Objetivo..: Revis�o de vari�veis, tipos b�sicos, const e auto.
Bimestre..: 1�/2025
Solucao...: RevisaoCpp
Arquivo...: 002.cpp
--------------------------------------------------------------------------------------------------------------------------
Data Cria��o.................: 20/08/2025
Data Altera��o...............: 20/08/2025
Altera��o Feita..............: Arquivo inicial
--------------------------------------------------------------------------------------------------------------------------
Vers�o 1.0
*/
#include <iostream>
#include <string>
using namespace std;


int main() {
	// Tipos b�sicos
	int idade = 20; // inteiro
	double altura = 1.82; // ponto flutuante de dupla precis�o
	char inicial = 'R'; // caractere
	bool aprovado = true; // booleano


	// const e auto
	const double PI = 3.14159; // constante
	auto soma = idade + 10; // dedu��o de tipo (int)

    cout << "Idade: " << idade << '\n'
		 << "Altura: " << altura << '\n'
		 << "Inicial: " << inicial << '\n'
		 << boolalpha << "Aprovado: " << aprovado << '\n'
		 << "PI: " << PI << '\n'
		 << "Soma: " << soma << endl;
	


	// sizeof
	cout << "sizeof(int) = " << sizeof(int) << " bytes" << endl;
	cout << "sizeof(double) = " << sizeof(double) << " bytes" << endl;


	system("pause");
	return 0;
}