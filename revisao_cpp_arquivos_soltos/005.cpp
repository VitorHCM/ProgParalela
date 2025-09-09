/*-------------------------------------------------------------------------------------------------------------------------
Objetivo..: Revis�o de if/else, switch e escopo.
Arquivo...: 005.cpp
--------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

int main() {
	int nota;
	cout << "Digite a nota (0 a 10): ";
	cin >> nota;

	// ------------------- Estrutura de Decis�o: if / else if / else -------------------

	// if: � uma palavra-chave que inicia uma "estrutura condicional". O bloco de c�digo seguinte
	// s� ser� executado SE a condi��o dentro dos par�nteses for avaliada como verdadeira (true).
	// >= : Operador relacional "maior ou igual a".
	if (nota >= 6) {
		// { }: As chaves definem um "bloco de c�digo" ou "escopo". Tudo que est� dentro das chaves
		// pertence a este `if`. Se a condi��o for verdadeira, todo o bloco � executado.
		// Se houver apenas uma instru��o, as chaves s�o opcionais, mas � uma boa pr�tica sempre us�-las para evitar erros.
		cout << "Aprovado" << endl;
	}
	// else if: Esta cl�usula � avaliada somente se o `if` anterior (ou `else if` anterior) for falso.
	// Permite criar uma cadeia de condi��es excludentes. A primeira que for verdadeira ser� executada, e o resto da cadeia ser� ignorado.
	else if (nota >= 4) {
		cout << "Prova final" << endl;
	}
	// else: � a cl�usula "pega-tudo". O bloco de c�digo do `else` � executado se NENHUMA das condi��es
	// anteriores (`if` ou `else if`) for verdadeira. N�o possui uma condi��o pr�pria.
	else {
		cout << "Reprovado" << endl;
	}

	int opcao;
	cout << "\nMenu: 1-Listar 2-Inserir 3-Sair -> ";
	cin >> opcao;

	// ------------------- Estrutura de Sele��o: switch / case -------------------

	// switch: � uma estrutura de controle que permite a uma vari�vel ser testada contra uma lista de valores (cases).
	// � frequentemente uma alternativa mais limpa a uma longa cadeia de `if-else if` quando se compara uma �nica vari�vel
	// com valores constantes e integrais (int, char, etc.).
	// A vari�vel `opcao` ser� o valor de controle.
	switch (opcao) {
		// case: � um "r�tulo" que marca um ponto de entrada no bloco `switch`. Se o valor de `opcao` for igual
		// ao valor do `case` (neste caso, 1), a execu��o do programa "salta" para esta linha.
	case 1:
		cout << "Listando..." << endl;
		// break: � uma instru��o crucial que finaliza a execu��o do `switch`. Sem o `break`,
		// o c�digo continuaria a executar as instru��es do pr�ximo `case` ("fall-through"),
		// o que geralmente � um comportamento indesejado.
		break;
	case 2:
		cout << "Inserindo..." << endl;
		break;
	case 3:
		cout << "Saindo..." << endl;
		break;
		// default: Este r�tulo � opcional e funciona como o `else`. O c�digo dentro do `default`
		// � executado se o valor da vari�vel (`opcao`) n�o corresponder a nenhum dos r�tulos `case` anteriores.
	default:
		cout << "Op��o inv�lida" << endl;
		// O `break` no final do `default` n�o � estritamente necess�rio (pois j� � o fim do `switch`),
		// mas � considerado uma boa pr�tica de programa��o para manter a consist�ncia.
		break;
	}


	system("pause");
	return 0;
}