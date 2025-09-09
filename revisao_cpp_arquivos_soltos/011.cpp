/*--------------------------------------------------------------------------------------------------------------------
Objetivo..: Leitura e escrita em arquivos de texto com fstream.
Arquivo...: 011.cpp
--------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
// #include <fstream>: Inclui a biblioteca de "file stream" (fluxo de arquivo).
// � necess�ria para usar as classes `ofstream` (sa�da) e `ifstream` (entrada) para manipula��o de arquivos.
#include <fstream> 
#include <string>
#include <vector>
// <utility> � implicitamente inclu�do por outros cabe�alhos, mas � a casa do std::pair.
using namespace std;

int main() {
    // 1) Escrever um arquivo texto simples

    // Usar um bloco de escopo `{}` � uma excelente pr�tica com fluxos de arquivo.
    // Quando a execu��o sai do bloco, o destrutor do objeto `out` � chamado automaticamente,
    // o que garante que o arquivo seja fechado. Isso � um exemplo do princ�pio RAII.
    {
        // ofstream: (Output File Stream) Classe para escrever em arquivos. Pense nela como o `cout` para arquivos.
        // O construtor `ofstream out("saida.txt");` tenta abrir (ou criar, se n�o existir) o arquivo "saida.txt" em modo de escrita.
        // Se o arquivo j� existir, seu conte�do ser� apagado (overwrite).
        ofstream out("saida.txt");

        // � crucial verificar se o arquivo foi aberto com sucesso.
        // Objetos de stream podem ser avaliados em um contexto booleano. `!out` � `true` se a abertura falhou (ex: sem permiss�o).
        if (!out) {
            // cerr: (Console Error) � o fluxo de sa�da de erro padr�o. � como o `cout`, mas destinado a mensagens de erro.
            // A principal vantagem � que `cerr` n�o usa buffer, ent�o a mensagem de erro � exibida imediatamente.
            cerr << "Erro ao abrir saida.txt para escrita\n";
            // `return 1;`: Retornar um valor diferente de 0 de `main` � a conven��o para indicar que o programa terminou com um erro.
            return 1;
        }
        // A sintaxe para escrever no arquivo � id�ntica � do `cout`.
        out << "Linha 1" << '\n';
        out << "Linha 2" << '\n';
    } // `out` sai do escopo aqui, seu destrutor � chamado, e o arquivo "saida.txt" � fechado.

    // 2) Ler o mesmo arquivo linha a linha
    {
        // ifstream: (Input File Stream) Classe para ler de arquivos. Pense nela como o `cin` para arquivos.
        ifstream in("saida.txt");
        if (!in) { cerr << "Erro ao abrir saida.txt para leitura\n"; return 1; }

        string linha;
        cout << "Conteudo de saida.txt:" << endl;
        // O idioma `while (getline(in, linha))` � a forma padr�o de ler um arquivo texto linha por linha.
        // - `getline(in, linha)` tenta ler uma linha do fluxo `in` e armazen�-la em `linha`.
        // - Se a leitura for bem-sucedida, a express�o retorna um estado que � avaliado como `true`, e o la�o continua.
        // - Ao atingir o final do arquivo, `getline` falha, a express�o � avaliada como `false`, e o la�o termina.
        while (getline(in, linha)) {
            cout << linha << endl;
        }
    } // `in` sai do escopo, e o arquivo � fechado automaticamente.

    // 3) CSV simples: "nome,idade"
    {
        ofstream csv("dados.csv"); // Cria e abre o arquivo dados.csv para escrita.
        csv << "nome,idade" << '\n'; // Escreve o cabe�alho.
        csv << "Ana,30" << '\n';
        csv << "Bruno,25" << '\n';
    }
    {
        ifstream csv("dados.csv");
        string linha;
        // vector<pair<string,int>>: Vamos usar um vetor de pares para armazenar os dados.
        // - `pair`: � um template de struct da STL que armazena exatamente dois valores. � �til para agrupar dados simples.
        //   O primeiro valor � acessado com `.first` e o segundo com `.second`.
        vector<pair<string, int>> pessoas;

        getline(csv, linha); // L� a primeira linha (cabe�alho) para descart�-la.

        while (getline(csv, linha)) {
            // auto: Uma palavra-chave que instrui o compilador a deduzir o tipo da vari�vel automaticamente a partir do seu inicializador.
            // Aqui, `linha.find(',')` retorna um `string::size_type`, e `auto` evita que tenhamos que escrever esse tipo longo.
            auto pos = linha.find(',');

            // string::npos: � um valor est�tico especial retornado por `find` quando o caractere (ou substring) n�o � encontrado.
            if (pos == string::npos) continue; // Pula linhas malformadas sem v�rgula.

            // substr(posicao_inicial, comprimento): M�todo de `string` que extrai uma parte da string.
            string nome = linha.substr(0, pos); // Extrai de 0 at� a posi��o da v�rgula.

            // stoi: (String to Integer) Fun��o global que converte uma `string` para um `int`.
            int idade = stoi(linha.substr(pos + 1)); // Extrai da posi��o AP�S a v�rgula at� o fim.

            pessoas.push_back({ nome, idade }); // Cria um `pair` na hora e o adiciona ao vetor.
        }
        cout << "\nLidos do CSV:" << endl;
        // `for (auto &p : pessoas)`: Usar `auto&` (refer�ncia) no range-based for � mais eficiente
        // pois evita copiar cada `pair` do vetor a cada itera��o.
        for (auto& p : pessoas) cout << p.first << " tem " << p.second << " anos\n";
    }

    system("pause");
    return 0;
}