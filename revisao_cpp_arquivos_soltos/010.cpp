/*-----------------------------------------------------------------------------------------------------------------
Objetivo..: Definir struct e class com construtor e m�todos.
Arquivo...: 010.cpp
-----------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

// ------------------- Agrega��o de Dados com `struct` -------------------

// struct: Palavra-chave que define uma "estrutura", um tipo de dado composto que agrupa diferentes vari�veis sob um �nico nome.
// � uma das maneiras de criar seus pr�prios tipos de dados.
// Por padr�o, todos os membros de uma `struct` s�o P�BLICOS (`public`).
struct Pessoa {
    // Estes s�o os "membros" da struct. Cada objeto do tipo `Pessoa` ter� sua pr�pria `nome` e `idade`.
    string nome;
    // int idade{};: A inicializa��o com chaves `{}` aqui � chamada de "inicializa��o de membro na classe" (in-class member initialization).
    // Se um objeto `Pessoa` for criado sem especificar uma idade, ela ser� inicializada com zero por padr�o.
    int idade{};
};

// ------------------- Encapsulamento de Dados com `class` -------------------

// class: Palavra-chave que define uma "classe", o bloco de constru��o fundamental da Programa��o Orientada a Objetos em C++.
// Assim como a `struct`, agrupa dados (membros) e fun��es (m�todos).
// A principal diferen�a � que, por padr�o, todos os membros de uma `class` s�o PRIVADOS (`private`).
class ContaBancaria {
    // private: � um "especificador de acesso". Membros declarados como `private` s� podem ser acessados
    // por fun��es-membro (m�todos) da pr�pria classe. Isso � chamado de ENCAPSULAMENTO, pois protege os dados de modifica��es externas indesejadas.
private:
    string titular;
    double saldo{ 0.0 }; // Inicializa��o de membro na classe.

    // public: Outro especificador de acesso. Membros declarados como `public` formam a "interface" da classe.
    // Eles podem ser acessados de qualquer lugar fora da classe, permitindo a intera��o com o objeto.
public:
    // Este � um "Construtor". � um m�todo especial que � chamado automaticamente quando um objeto da classe � criado.
    // Seu prop�sito � inicializar os membros do objeto. Ele tem o mesmo nome da classe e n�o tem tipo de retorno.
    // - `const string &t`: Par�metro passado por "refer�ncia constante". � eficiente (evita copiar a string) e seguro (o `const` impede a modifica��o do original).
    // - `double s = 0.0`: Par�metro com "valor padr�o". Se o segundo argumento n�o for fornecido na cria��o do objeto, `s` ser� 0.0.
    // - `: titular(t), saldo(s)`: Esta � a "lista de inicializa��o de membros". � a forma preferida e mais eficiente de inicializar membros
    //   em um construtor, em vez de usar atribui��es no corpo `{}`.
    ContaBancaria(const string& t, double s = 0.0) : titular(t), saldo(s) {}

    // `depositar` � uma "fun��o-membro" ou "m�todo". � uma fun��o que pertence � classe e pode operar em seus membros.
    void depositar(double valor) { saldo += valor; }

    bool sacar(double valor) {
        if (valor <= saldo) { saldo -= valor; return true; }
        return false;
    }

    // `const` no final de um m�todo: Isso declara que o m�todo � "constante".
    // � uma promessa de que este m�todo N�O modificar� nenhum membro da classe (como `titular` ou `saldo`).
    // Ele apenas l� os dados. Isso melhora a seguran�a e permite que o m�todo seja chamado em objetos constantes.
    void imprimir() const {
        cout << "Titular: " << titular << ", Saldo: R$ " << saldo << endl;
    }
};

int main() {
    // Pessoa p{"Rodrigo", 35};: Cria uma "inst�ncia" (ou "objeto") da struct `Pessoa`.
    // A sintaxe com `{}` � chamada de "inicializa��o uniforme" (uniform initialization).
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

    system("pause");
    return 0;
}