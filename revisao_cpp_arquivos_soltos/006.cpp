/*-------------------------------------------------------------------------------------------------------------------------
Objetivo..: Revis�o de la�os e controle de fluxo (break/continue).
Arquivo...: 006.cpp
--------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

int main() {
		cout << "for de 1 a 5: ";
	// ------------------- La�o de Repeti��o: for -------------------

	// for: Inicia um la�o de repeti��o comumente usado quando o n�mero de itera��es � conhecido.
	// A estrutura dentro dos par�nteses tem tr�s partes, separadas por ponto e v�rgula:
	// 1. Inicializa��o (int i = 1;): Executada uma �nica vez no in�cio do la�o. Aqui, declaramos e inicializamos um contador `i`.
	//    O escopo da vari�vel `i` � limitado a este la�o `for`.
	// 2. Condi��o (i <= 5;): Verificada ANTES de cada itera��o. Enquanto for verdadeira, o la�o continua.
	// 3. Incremento/Atualiza��o (++i;): Executado AO FINAL de cada itera��o. Aqui, incrementamos o contador.
	// ++i: Operador de pr�-incremento. Ele incrementa o valor de `i` e ent�o retorna o novo valor. Em um la�o `for` simples,
	//      seu comportamento � efetivamente o mesmo que o p�s-incremento (`i++`).
	for (int i = 1; i <= 5; ++i) cout << i << ' '; // Como h� apenas uma instru��o, as chaves {} s�o opcionais.
	cout << endl;

	cout << "while (contagem regressiva): ";
	int c = 5;
	// ------------------- La�o de Repeti��o: while -------------------

	// while: Inicia um la�o que executa enquanto uma condi��o for verdadeira. � um "la�o de pr�-teste",
	// pois a condi��o � verificada ANTES de cada itera��o. Se a condi��o for falsa na primeira vez, o corpo do la�o nunca executa.
	while (c > 0) {
		// c--: Operador de p�s-decremento. O valor ATUAL de `c` � usado na express�o (enviado para o `cout`),
		//      e S� DEPOIS o valor � decrementado. Por isso, a sa�da come�a em 5 e vai at� 1.
		cout << c-- << ' ';
	}
	cout << endl;

	cout << "do-while (executa ao menos uma vez): ";
	int x = 0;
	// ------------------- La�o de Repeti��o: do-while -------------------

	// do: Inicia um la�o "do-while", que � um "la�o de p�s-teste".
	// A principal caracter�stica � que o corpo do la�o � GARANTIDO a executar pelo menos uma vez,
	// pois a condi��o s� � verificada no final.
	do {
		// x++: Operador de p�s-incremento. Similar ao `c--`, o valor atual de `x` (come�ando em 0) � usado,
		//      e depois `x` � incrementado.
		cout << x++ << ' ';
	} while (x < 3); // A condi��o � verificada aqui, no final da itera��o. Note o ponto e v�rgula obrigat�rio.
	cout << endl;

	cout << "continue/break exemplo: ";
	for (int i = 0; i < 10; ++i) {
		// % : Operador M�dulo (ou resto da divis�o). `i % 2` retorna o resto da divis�o de `i` por 2.
		// Se o resto � 0, o n�mero � par.
		if (i % 2 == 0)
			// continue: � uma instru��o de controle de fluxo que interrompe a itera��o ATUAL
			// e "pula" imediatamente para o in�cio da pr�xima itera��o (no caso do `for`, para a parte de incremento `++i`).
			// Neste c�digo, se `i` for par, o `cout` abaixo ser� ignorado.
			continue;

		if (i > 7)
			// break: Esta instru��o (j� vista no `switch`) interrompe e sai IMEDIATAMENTE do la�o
			// em que est� contida (`for`, `while` ou `do-while`). A execu��o continua na primeira linha ap�s o la�o.
			// Aqui, assim que `i` for maior que 7, o la�o `for` termina prematuramente.
			break;

		cout << i << ' '; // Esta linha s� ser� executada se `i` for �mpar E `i` n�o for maior que 7.
	}
	cout << endl; // Sa�da esperada: 1 3 5 7

	system("pause");
	return 0;
}