/*
Ciência da Computação
IESB: Coefficient of variation
October 28, 2025

Exercício Final: Análise de Dados com OpenMP

Objetivo

    O objetivo deste exercício é implementar um programa em C/C++ para calcular o
    coeficiente de variação para uma distribuição de dados com intervalo de classe, utilizando
    OpenMP para paralelizar os cálculos e otimizar o desempenho.
    Descrição do Problema

    Você receberá um conjunto de dados contendo a estatura (em cm) e o peso (em
    kg) de 1000 pessoas. Sua tarefa é calcular o coeficiente de variação para cada uma dessas
    duas variáveis. Para isso, os dados devem ser agrupados em intervalos de classe.
    Requisitos.

        • Entrada de Dados: O programa deverá ser capaz de processar uma entrada de
        dados para 1000 pessoas. Assuma que os dados serão fornecidos em um arquivo de
        texto, onde cada linha contém a estatura e o peso de uma pessoa, separados por
        espaço.

        • Intervalos de Classe:
            – Para a variável estatura, crie um intervalo de classe de 8 cm.
            – Para a variável peso, crie um intervalo de classe de 4 kg.

        • Paralelismo: Utilize as diretivas do OpenMP para paralelizar os principais laços
        de cálculo (soma, média, desvio padrão) e melhorar a eficiência do programa.

Fórmulas Necessárias

    Para resolver este problema, você precisará das seguintes fórmulas estatísticas. Para
    dados agrupados em classes, utilizamos a média ponderada, onde a ponderação é a fre-
    quência de cada classe.

    1. Média Ponderada (μ). A média para dados agrupados é calculada pela soma dos
    produtos do ponto médio de cada classe (xi) pela sua respectiva frequência (fi), dividida
    pela soma das frequências (que é o número total de observações, N).

        μ = sum( xi*fi ) / sum ( fi ) = sum( xi*fi )/N

        Onde:
        • xi é o ponto médio da classe i.
        • fi é a frequência (número de pessoas) na classe i.
        • k é o número de classes.
        • N é o número total de pessoas (1000).

    2. Desvio Padrão Populacional (σ). O desvio padrão populacional mede a dispersão
    dos dados em relação à média. Para dados agrupados, a fórmula é:

        σ = sqrt( sum( fi*(xi-μ)² ) / N )

        Onde:
        • σ é o desvio padrão populacional.
        • xi, fi, μ, N, k têm o mesmo significado da fórmula da média.

    3. Coeficiente de Variação (CV). O coeficiente de variação é uma medida de disper-
    são relativa, que expressa o desvio padrão como uma porcentagem da média. É útil para
    comparar a variabilidade de diferentes conjuntos de dados.
        
        CV = σ/μ * 100%

        Onde:
        • CV é o coeficiente de variação.
        • σ é o desvio padrão populacional.
        • μ é a média populacional.

O que deve ser entregue

    1) O código-fonte completo em C/C++ com as diretivas do OpenMP.

    2) Um breve relatório (em formato PDF) explicando quais partes do código foram
    paralelizadas e por quê.

    3) Os resultados obtidos: o coeficiente de variação para a estatura e para o peso.

    4) Uma análise de desempenho, comparando o tempo de execução da versão sequen-
    cial com a versão paralela do seu programa.

*/

#include <iostream>
#include <fstream>      //para manipulacao de arquivos
#include <cstdlib>      //para random 
#include <algorithm>    //para sort
#include <ctime>        
#include <vector>       //para vetores
#include <cmath>
#include <omp.h>
using namespace std;

int criaTXT();
vector <double> medeFrequencias(vector <double> , double , double, double );
double mediaPonderada(vector <double>, double, double, int);
double mediaPondParalela();
double desvioPadrao(vector <double>, double, double, int, double);
double desvioPadraoParalelo();
double coeficienteVariacao(double, double);
double coeficienteVarParalelo();

int main(){

    int arquivoBool = 0;
    cout << "Deseja criar arquivo TXT com 1000 linhas de peso e altura?\nDigite 1 para SIM e 0 para NAO\n(O programa ira fechar automaticamente apos criacao do arquivo): ";
    cin >> arquivoBool;
    if( arquivoBool == 1){
        criaTXT(); //cria arquivo com alturas de 1.4 a 2.2 e pesos de 40 a 120
    }

    vector <double> alturas;
    vector <double> pesos;
    double altura, peso;
    
    ifstream file("data.txt");  // abre o arquivo
        if (!file) { //checa se o arquivo foi aberto com sucesso
            cerr << "Error opening file!" << endl;
            return 1;
        }
        
        //preenche cada vetor com os valores do .TXT
        while (file >> altura >> peso){
            alturas.push_back(altura);
            pesos.push_back(peso);
        }    
        file.close(); //fecha o arquivo

    //roda algoritmo de sort em cada vetor
    sort(alturas.begin(), alturas.end());
    sort(pesos.begin(), pesos.end());

    //medir frequencias em cada intervalo de valor nos dois vetores
    //alturas intervalo de 0.08 m
    vector <double> alturaFrequencias = medeFrequencias(alturas, 0.08, 1.4, 2.2); //vetor alturas, intervalo, altura minima/inicial
    
    //pesos intervalo de 4 kg
    vector <double> pesosFrequencias = medeFrequencias(pesos, 4, 40, 120); //vetor pesos, intervalo, peso minimo/inicial
    cout << endl;

    //calcula alturas
    double t0 = omp_get_wtime(); // t0 de sequencial
    double mediaAltura = mediaPonderada(alturaFrequencias, 0.08, 1.4, 9); // vetor de frequencias, intervalos, valor inicial, int de parada
    double dPAltura = desvioPadrao(alturaFrequencias, 0.08, 1.4, 9, mediaAltura); // || + media ponderada
    double cVarAltura = coeficienteVariacao(dPAltura, mediaAltura);
    //calcula pesos
    double mediaPesos = mediaPonderada(pesosFrequencias, 4, 40, 19); // vetor de frequencias, intervalos, valor inicial, int de parada
    double dPPesos = desvioPadrao(pesosFrequencias, 4, 40, 19, mediaPesos); // || + media ponderada
    double cVarPesos = coeficienteVariacao(dPPesos, mediaPesos);
    double t1 = omp_get_wtime(); // t1 de sequencial
    
    cout << "\nMedias: Peso: " << mediaPesos << " Altura: " << mediaAltura << endl;
    cout << "Desvios: Peso: " << dPPesos << " Altura: " << dPAltura << endl;

    cout << "Coeficientes de Variacao Sequencial:\nAltura: " << cVarAltura << "\nPesos: " << cVarPesos << "\nTempo de execucao: " << t1 - t0 << endl; 

return 0;
}

int criaTXT(){
    ofstream file("data.txt");  //cria e abre o arquivo
    if (!file) { //checa se o arquivo foi aberto com sucesso
        cerr << "Error opening file!" << endl;
        return 1;
    }
    srand(static_cast<unsigned>(time(nullptr))); // semente para criacao de valores aleatorios
    for (int i = 0; i < 1000; ++i) { //loop para adicao de valores no data.txt
        // gera pesos e alturas aleatorios
        double height = 1.4 + static_cast<double>(rand()) / RAND_MAX * (2.2 - 1.4); // altura entre 1.4 e 2.0 m
        double weight = 40.0 + static_cast<double>(rand()) / RAND_MAX * (120.0 - 40.0); // peso entre 40 e 120 kg
        file << height << " " << weight << "\n";
    }
    file.close(); // fecha o arquivo
    cout << "Arquivo criado e preenchido com sucesso: data.txt" << endl;
}
vector <double> medeFrequencias(vector <double> vetor, double intervalo, double valorInicial, double valorFinal){
    vector <double> vetorFrequencias;
    int counter = 0;
    double intervaloAtual = valorInicial + intervalo;
    double inter = 0;
    for (int i = 0; i <= 1000; i++){ //loop para medir freqeuncia
        
        if(vetor[i] <= valorFinal){

            if(vetor[i] <= intervaloAtual){ counter++; //checa se o valor do indice do vetor esta dentro do intervalo
            }else{ //caso nao esteja dentro do intervalo, atualiza-se o intervalo para frente, salva a frequencia no indice do vetorFrequencia e reseta o counter
                vetorFrequencias.push_back (counter);
                counter = 0.0;
                inter = intervaloAtual;
                intervaloAtual = inter + intervalo; }            
        }
    } return vetorFrequencias;
}
double mediaPonderada(vector <double> vetorFreq, double intervalo, double valorInicial, int parada){
    double mPonderada = 0.0;
    double sumFreq = 0;
    double sumFreqLocal = 0;
    double sum = 0;
    double sumLocal = 0;
    double intervaloAtual = valorInicial + intervalo;
    double mediator;

    for(int i = 0; i <= parada; i++){

        sumLocal  = intervaloAtual*vetorFreq[i];
        mediator = sum;
        sum = mediator + sumLocal;   //soma frequencia mais valor do intervalo
        mediator = sumFreq;
        sumFreq = mediator + vetorFreq[i]; //soma frequencias para obter N
        mediator = intervaloAtual;
        intervaloAtual = mediator + intervalo;
    }
    mPonderada = sum / sumFreq;
    return mPonderada;
}
double mediaPondParalela(){

}
double desvioPadrao(vector <double> vetorFreq, double intervalo, double valorInicial, int parada, double mPonderada){
    
    double dPadrao = 0.0;
    double sumFreq = 0;
    double sumFreqLocal = 0;
    double sum = 0;
    double sumLocal = 0;
    double intervaloAtual = valorInicial + intervalo;
    double value = 0;

    for(int i = 0; i <= parada; i++){
        
        double x, x2, x3, mediator;

        x = (intervaloAtual-mPonderada);
        x2 = x*x;
        x3 = vetorFreq[i]*x2;

        mediator = sum;
        sum = mediator + x3;   //soma parte de cima

        mediator = sumFreq;
        sumFreq = mediator + vetorFreq[i]; //soma frequencias para obter N

        mediator = intervaloAtual;
        intervaloAtual = mediator + intervalo;
    }
        value = sum/sumFreq;
        dPadrao = sqrt(value);
        return dPadrao;
}
double desvioPadraoParalelo(){

}
double coeficienteVariacao(double dPadrao, double mPonderada){
    double coeficiente = (dPadrao/mPonderada)*100;
    return coeficiente; 
}
double coeficienteVarParalelo(){

}

