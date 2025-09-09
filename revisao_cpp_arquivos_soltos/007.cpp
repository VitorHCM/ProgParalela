/*-------------------------------------------------------------------------------------------------------------------------
Objetivo..: Declara��o/defini��o de fun��es, sobrecarga, passagem por refer�ncia.
Arquivo...: 007.cpp
--------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// ------------------- Prot�tipos de Fun��es (Declara��es) -------------------

// Um "prot�tipo" ou "declara��o de fun��o" informa ao compilador sobre a exist�ncia de uma fun��o ANTES que ela seja usada.
// Ele especifica o tipo de retorno, o nome e os tipos dos par�metros. Isso permite que voc� chame a fun��o
// na `main` e defina (implemente) o corpo da fun��o mais tarde no arquivo, melhorando a organiza��o.

// Assinatura: int soma(int a, int b)
// - `int`: Tipo de retorno. A fun��o `soma` retornar� um valor inteiro.
// - `soma`: Nome da fun��o.
// - `(int a, int b)`: Lista de par�metros. A fun��o espera receber dois inteiros como entrada. Por padr�o,
//   eles s�o passados "por valor", o que significa que a fun��o recebe C�PIAS dos valores originais.
int soma(int a, int b);

// Esta � uma "sobrecarga" (overload) da fun��o `soma`.
// Sobrecarga de fun��o significa ter m�ltiplas fun��es com o MESMO nome, mas com listas de par�metros DIFERENTES
// (seja no n�mero de par�metros ou nos seus tipos). O compilador decide qual vers�o chamar com base nos
// argumentos que voc� fornece na chamada.
int soma(int a, int b, int c);

// Assinatura: void incrementa(int& valor)
// - `void`: Tipo de retorno. Significa que esta fun��o N�O retorna nenhum valor.
// - `incrementa`: Nome da fun��o.
// - `(int& valor)`: Passagem "por refer�ncia".
//   O `&` aqui N�O � o operador "endere�o de". Neste contexto, ele declara que `valor` � uma REFER�NCIA.
//   Uma refer�ncia funciona como um "apelido" para a vari�vel original que foi passada.
//   Qualquer modifica��o feita em `valor` DENTRO da fun��o afetar� DIRETAMENTE a vari�vel original FORA da fun��o.
void incrementa(int& valor);

int main() {
	// O compilador v� que estamos chamando `soma` com dois argumentos inteiros.
	// Ele ent�o procura uma fun��o com a assinatura `soma(int, int)` e a utiliza.
	cout << "soma(2,3) = " << soma(2, 3) << endl;

	// Aqui, a chamada � com tr�s argumentos. O compilador seleciona a vers�o sobrecarregada
	// com a assinatura `soma(int, int, int)`.
	cout << "soma(2,3,4) = " << soma(2, 3, 4) << endl;

	int n = 10;
	// Aqui chamamos `incrementa`. Como ela espera uma refer�ncia, estamos passando um "apelido" para `n`.
	// A fun��o `incrementa` n�o recebe o valor 10, ela recebe o pr�prio `n`.
	incrementa(n);
	// Como a fun��o modificou a vari�vel original atrav�s da refer�ncia, o valor de `n` agora � 11.
	cout << "n apos incrementar = " << n << endl;

	system("pause");
	return 0;
}

// ------------------- Defini��es das Fun��es (Implementa��es) -------------------

// Esta � a "defini��o" ou "implementa��o" da fun��o. Cont�m o corpo real com o c�digo a ser executado.
// A assinatura aqui deve corresponder exatamente � do prot�tipo.
int soma(int a, int b) {
	// A palavra-chave `return` envia o valor da express�o `a + b` de volta para onde a fun��o foi chamada.
	return a + b;
}

// Defini��o da vers�o sobrecarregada.
int soma(int a, int b, int c) {
	return a + b + c;
}

// Defini��o da fun��o que usa passagem por refer�ncia.
void incrementa(int& valor) {
	// += : � um "operador de atribui��o composto". `valor += 1` � uma forma curta e eficiente de escrever `valor = valor + 1`.
	// Como `valor` � uma refer�ncia para `n` (da `main`), esta linha est�, na pr�tica, executando `n = n + 1`.
	valor += 1;
}