/*-------------------------------------------------------------------------------------------------------------------------
Objetivo..: Uso de arrays est�ticos e std::vector.
Arquivo...: 008.cpp
--------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
// #include <vector>: Inclui a biblioteca da STL (Standard Template Library) que define a classe de template `std::vector`.
// � necess�rio para usar vetores din�micos em seu c�digo.
#include <vector>
using namespace std;

int main() {
	// ------------------- Array Est�tico (estilo C) -------------------

	// int arr[5]: Declara um "array" (arranjo) est�tico.
	// - Um array � uma cole��o de elementos do mesmo tipo, armazenados em posi��es cont�guas de mem�ria.
	// - "Est�tico" aqui significa que seu tamanho (5) � fixo e definido em tempo de compila��o. Ele n�o pode ser alterado durante a execu��o.
	// = { 1,2,3,4,5 };: Esta � uma "lista inicializadora" que preenche o array com os valores fornecidos no momento da sua cria��o.
	int arr[5] = { 1, 2, 3, 4, 5 };

	int somaArr = 0;
	// A itera��o sobre um array est�tico geralmente requer saber seu tamanho exato (o "n�mero m�gico" 5 aqui).
	for (int i = 0; i < 5; ++i) {
		// arr[i]: Acessa um elemento do array usando o "operador de subscrito" [].
		// Os �ndices em C++ s�o baseados em zero, ent�o `arr[0]` � o primeiro elemento (1), `arr[1]` � o segundo (2), e assim por diante, at� `arr[4]`.
		somaArr += arr[i];
	}
	cout << "Soma (array) = " << somaArr << endl;

	// ------------------- Vector Din�mico (estilo C++) -------------------

	// vector<int> v: Declara uma vari�vel `v` do tipo `vector`.
	// - `vector`: � uma classe da STL que implementa um array din�mico. Seu tamanho pode crescer ou diminuir durante a execu��o do programa.
	// - `<int>`: `vector` � um "template de classe", o que significa que voc� deve especificar o tipo de dado que ele ir� armazenar dentro dos colchetes angulares (`<>`).
	// = { 10,20,30 };: Assim como no array, podemos usar uma lista inicializadora. `v` come�a com 3 elementos.
	vector<int> v = { 10, 20, 30 };

	// v.push_back(40): `push_back()` � um "m�todo" (uma fun��o que pertence a um objeto) da classe `vector`.
	// Ele adiciona um novo elemento (neste caso, 40) ao FINAL do vetor, aumentando seu tamanho automaticamente.
	// Este � o principal exemplo de sua natureza "din�mica".
	v.push_back(40);

	int somaVec = 0;
	// for (int x : v): Este � um "range-based for loop" (ou la�o "for-each"), introduzido no C++11.
	// � uma forma muito mais simples e segura de iterar sobre todos os elementos de um cont�iner (como um `vector` ou array).
	// - `v`: O cont�iner sobre o qual vamos iterar.
	// - `int x`: A cada itera��o, `x` receber� uma C�PIA do pr�ximo elemento de `v`.
	// O la�o executa uma vez para cada elemento em `v`, sem a necessidade de gerenciar �ndices manualmente.
	for (int x : v) somaVec += x;
	cout << "Soma (vector) = " << somaVec << endl;

	// v.size(): Outro m�todo �til de `vector`. Ele retorna o n�mero atual de elementos no vetor.
	// Usar `.size()` torna o c�digo mais robusto, pois n�o dependemos de um tamanho fixo codificado manualmente.
	cout << "Tamanho do vector = " << v.size() << endl;

	system("pause");
	return 0;
}