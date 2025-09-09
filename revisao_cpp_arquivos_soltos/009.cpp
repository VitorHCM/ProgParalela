/*---------------------------------------------------------------------------------------------------------------
Objetivo..: Endere�o (&), desrefer�ncia (*), ponteiros e refer�ncias.
Arquivo...: 009.cpp
---------------------------------------------------------------------------------------------------------------*/
#include <iostream>
// #include <memory>: Inclui a biblioteca necess�ria para usar "ponteiros inteligentes" (smart pointers),
// como o `std::unique_ptr`.
#include <memory> 
using namespace std;

// ------------------- Fun��es com Ponteiros e Refer�ncias -------------------

// void dobra(int *p): Esta fun��o recebe um "ponteiro para um inteiro" como par�metro.
// - `int *p`: `p` n�o � um inteiro, mas sim uma vari�vel que armazena o ENDERE�O de mem�ria de um inteiro.
void dobra(int* p) {
    // if (p): � uma pr�tica de seguran�a crucial verificar se um ponteiro n�o � nulo (`nullptr`) antes de us�-lo.
    // Tentar acessar um endere�o nulo causa uma falha de segmenta��o (crash).
    if (p)
        // *p *= 2: O `*` aqui � o "operador de desrefer�ncia". Ele diz: "acesse o valor que est� no endere�o
        // de mem�ria para o qual `p` aponta". A linha modifica o valor ORIGINAL que est� sendo apontado.
        *p *= 2;
}
// void triplica(int &r): Esta fun��o recebe uma "refer�ncia para um inteiro". (Revis�o do c�digo 007)
// A sintaxe � mais limpa e a refer�ncia n�o pode ser nula, tornando-a geralmente mais segura que ponteiros para este fim.
void triplica(int& r) { r *= 3; }


int main() {
    // ------------------- Ponteiros: O B�sico -------------------
    int x = 5;

    // int *px = &x;: Esta � a linha mais importante. Vamos quebr�-la:
    // - `int *px;`: Declara uma vari�vel chamada `px`. O `*` na declara��o significa que `px` � um PONTEIRO. Seu tipo � "ponteiro para int".
    // - `&x`: O `&` aqui � o "operador de endere�o". Ele obt�m o endere�o de mem�ria da vari�vel `x`.
    // - A linha completa significa: "Crie um ponteiro `px` e armazene nele o endere�o de mem�ria de `x`."
    int* px = &x;

    cout << "x = " << x << ", &x = " << &x << endl; // Imprime o valor de x e seu endere�o de mem�ria.

    // - `px`: Imprime o valor contido em `px`, que � o endere�o de `x`. O resultado ser� igual ao de `&x`.
    // - `*px`: Usa o operador de desrefer�ncia para acessar o VALOR no endere�o para o qual `px` aponta. O resultado ser� igual ao de `x`.
    cout << "px = " << px << ", *px = " << *px << endl;

    // Passamos o ponteiro `px` para a fun��o. A fun��o `dobra` usar� o endere�o para modificar o valor original de `x`.
    dobra(px);
    cout << "x ap�s dobra = " << x << endl;

    // Passamos a pr�pria vari�vel `x` para uma fun��o que espera uma refer�ncia. A sintaxe da chamada � mais simples.
    triplica(x);
    cout << "x ap�s triplica = " << x << endl;

    // ------------------- Aloca��o Din�mica de Mem�ria (Heap) -------------------

    // new: � um operador que aloca mem�ria no "heap" (ou "free store"), uma �rea de mem�ria dispon�vel para o programa durante sua execu��o.
    // A mem�ria alocada no heap N�O � liberada automaticamente no fim do escopo, como as vari�veis `x` e `px`.
    // `new int(42)` aloca espa�o para um inteiro, inicializa-o com 42 e retorna o endere�o dessa mem�ria.
    int* pHeap = new int(42);
    cout << "*pHeap = " << *pHeap << endl;

    // delete: � o operador que libera a mem�ria alocada com `new`.
    // � RESPONSABILIDADE do programador chamar `delete` para cada `new`.
    // Se voc� esquecer, ocorre um "vazamento de mem�ria" (memory leak).
    delete pHeap;

    // ------------------- Ponteiros Inteligentes (Modern C++) -------------------

    // `unique_ptr` � um "ponteiro inteligente" que encapsula um ponteiro bruto.
    // Ele implementa o princ�pio RAII ("Resource Acquisition Is Initialization"):
    // A posse do recurso (mem�ria) est� ligada ao tempo de vida do objeto (`up`).

    // `make_unique<int>(99)`: � a forma moderna e segura de criar um `unique_ptr`.
    // Ele aloca um `int` no heap com o valor 99 e o entrega para o `unique_ptr` gerenciar.
    unique_ptr<int> up = make_unique<int>(99);

    // Ele pode ser desreferenciado com `*` como um ponteiro normal.
    cout << "*up = " << *up << endl;

    // A M�GICA: Quando `up` sai do escopo (no final de `main`), seu destrutor � chamado automaticamente,
    // e esse destrutor chama `delete` no ponteiro que ele gerencia.
    // N�o h� necessidade de `delete` manual, eliminando o risco de vazamentos de mem�ria.

    system("pause");
    return 0;
}