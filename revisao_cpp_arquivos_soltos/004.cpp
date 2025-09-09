/*-------------------------------------------------------------------------------------------------------------------------
Objetivo..: Operadores aritm�ticos, relacionais, l�gicos e casting.
Arquivo...: 004.cpp
--------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

int main() {
	// = : Este � o operador de ATRIBUI��O. Ele pega o valor � direita e o armazena na vari�vel � esquerda.
	// A v�rgula (,) aqui � usada para declarar m�ltiplas vari�veis do mesmo tipo (`int`) em uma �nica linha.
	int a = 7, b = 3;

	// ------------------- Operadores Aritm�ticos -------------------

	// + : Operador de Adi��o.
	cout << "a + b = " << (a + b) << endl;
	// - : Operador de Subtra��o.
	cout << "a - b = " << (a - b) << endl;
	// * : Operador de Multiplica��o.
	cout << "a * b = " << (a * b) << endl;

	// / : Operador de Divis�o.
	// IMPORTANTE: Quando ambos os operandos (`a` e `b`) s�o inteiros, o C++ realiza uma "divis�o inteira".
	// Isso significa que qualquer parte fracion�ria do resultado � descartada (truncada), n�o arredondada.
	// Ex: 7 dividido por 3 � 2.333..., mas o resultado aqui ser� apenas 2.
	cout << "a / b = " << (a / b) << " (divis�o inteira)" << endl;

	// ------------------- Convers�o de Tipo (Casting) -------------------

	// static_cast<double>(b): Esta � uma opera��o de "casting" (convers�o de tipo) expl�cita e segura.
	// - `static_cast`: � um operador do C++ que converte um tipo de dado em outro em tempo de compila��o.
	// - `<double>`: � o tipo de destino. `double` � um tipo para n�meros de ponto flutuante (com casas decimais).
	// Ao converter `b` para `double`, a express�o `a / (um double)` for�a o compilador a promover `a` para `double` tamb�m
	// antes de realizar a opera��o. O resultado � uma "divis�o real", que preserva as casas decimais.
	cout << "a / (double)b = " << (a / static_cast<double>(b)) << " (divis�o real)" << endl;

	// ------------------- Manipulador de Fluxo e Operadores L�gicos/Relacionais -------------------

	// boolalpha: � um "manipulador de fluxo" (como o `endl`). Uma vez usado no `cout`, ele faz com que
	// valores booleanos (true/false) sejam impressos como texto ("true" ou "false") em vez de n�meros (1 ou 0).
	cout << boolalpha;

	// == : Operador relacional de IGUALDADE. Compara se os dois valores s�o iguais. Retorna `true` ou `false`.
	cout << "a == b? " << (a == b) << endl;
	// != : Operador relacional de DIFEREN�A. Compara se os dois valores s�o diferentes.
	cout << "a != b? " << (a != b) << endl;

	// && : Operador l�gico "E" (AND). A express�o inteira s� � `true` se AMBAS as condi��es (`a > b` e `b > 0`) forem `true`.
	// > : Operador relacional "MAIOR QUE".
	cout << "a > b && b > 0? " << (a > b && b > 0) << endl;

	// ! : Operador l�gico "N�O" (NOT). Ele inverte o valor booleano da express�o � sua frente.
	// < : Operador relacional "MENOR QUE".
	// A express�o `(a < b)` resulta em `false` (pois 7 n�o � menor que 3). O `!` inverte `false` para `true`.
	cout << "!(a < b) ? " << !(a < b) << endl;

	// ------------------- Operador Condicional (Tern�rio) -------------------

	// (condi��o) ? valor_se_true : valor_se_false
	// Este � o operador tern�rio, uma forma compacta de escrever uma instru��o `if-else`.
	// 1. `(a > b)`: A condi��o � avaliada. Como 7 > 3, o resultado � `true`.
	// 2. `? a`: Como a condi��o foi `true`, o valor antes dos dois pontos (`:`) � escolhido, que � o valor de `a` (7).
	// 3. `: b`: Se a condi��o fosse `false`, o valor de `b` seria escolhido.
	// O valor resultante (7) � ent�o atribu�do � vari�vel `maior`.
	int maior = (a > b) ? a : b;
	cout << "Maior = " << maior << endl;


	system("pause");
	return 0;
}