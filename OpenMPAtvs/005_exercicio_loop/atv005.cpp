/*
Lista de Exercícios — Programação Paralela (OpenMP)
Prof. Rodrifo Gonçalves.

Exercício 1 — “Hello World” Paralelo
a) Crie uma região paralela com #pragma omp parallel.
b) Cada thread deve imprimir uma mensagem indicando seu número (omp_get_thread_num()) e o total de 
threads (omp_get_num_threads()).
c) Configure o programa para rodar com 4 threads.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
using namespace std;

int main(int argc, char *argv[]){

    //omp_set_num_threads(4); //seta o numero de threads a serem usadas na porcao paralelizada
    //IMPORTANTE !! se declarado fora, ele seta o numero de threads para todas as regioes paralelas

    #pragma omp parallel num_threads(4) //seta 4 threads apenas nessa regiao
        {
        #pragma omp critical //utiliza a sincronizacao critica
            {        
                cout << "Thread numero: " << omp_get_thread_num() << " e total de Threads: "<< omp_get_num_threads() <<"\n";

            }    
        }


//-----------------------------------------------------
/*
Exercício 2 — Paralelizando um for simples
a) Crie um vetor v de tamanho 100 e inicialize todos os elementos com o valor 1.
b) Escreva um loop sequencial que soma todos os elementos.
c) Refaça o loop com #pragma omp parallel for reduction(+:soma).
d) Compare os resultados e explique por que a diretiva reduction é necessária.
*/
    int N = 100;
    double v[N];

    double soma_total = 0; 

    // Preenche os vetores com valores de exemplo 1
    for (int i = 0; i < N; i++) {
       v[i] = 1;
    }

    double soma = 0;

    for (int i = 0; i < N; i++){ //soma dos indices do vetor v com um loop for simples
         soma += v[i];
    }
    
    cout << "\n";
    #pragma omp parallel for reduction (+:soma_total) //declara for reduction ( operacao:variavel_a_ser_acessada_pela_operacao)
    
    for (int i = 0; i < N; i++){
        soma_total += v[i];
    }
    
    cout << "Soma Total = " << soma_total << endl;
    cout << "Resultado esperado = " << soma << endl;
    


//-----------------------------------------------------
/*
Exercício 3 — Expressão Vetorial
Implemente a expressão: a[i] = x[i]^2 + y[i]^2 + z[i]^2 para vetores de tamanho 1.000.000.
a) Faça a versão sequencial.
b) Paralelize com #pragma omp parallel for schedule(static).
c) Mostre o tempo total de execução em cada versão.
*/
    int M = 1000000;

    vector <double> a(M); //como o tamanho do stack e 8 MB, e necesario alocar os vetores no Heap
    vector <double> x(M); //caso contrario o stack overflows e da segmentation fault
    vector <double> y(M);
    vector <double> z(M);

    
    // Preenche os vetores com valores de exemplo 1
    for (int i = 0; i < N; i++) {
        x[i] = i;
        y[i] = i - 1;
        z[i] = i + 1;
        }

        double startSequencial = omp_get_wtime(); //start tempo sequencial

    for (int i = 0; i <= M; i++){ //loop sequencial
        a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
    }

        double endSequencial = omp_get_wtime(); //fim tempo em sequencial
        

    vector <double> timeThread(M); //declara vetor para armazenar tempos de execucao de cada thread

    int threads_usadas = 0;
    
        double startPara = omp_get_wtime(); //start tempo em paralelo

    #pragma omp parallel //inicia soma de vetores em paralelo
    {    
        threads_usadas = omp_get_num_threads();
            
        #pragma omp for schedule(static) //inicia soma de vetores em paralelo
        for (int i = 0; i < M; i++) { //loop em paralelo
            double t0 = omp_get_wtime(); //tempo 0 da thread

            a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);

            double t1 = omp_get_wtime(); //tempo 1 da thread
            timeThread[i] = (t1 - t0); // mede o tempo de cada thread e salva o numero da thread no mesmo index
            }
        }
        double endPara = omp_get_wtime(); //fim tempo paralelo

    cout << endl << "Tempo gasto em sequencial = " << ( endSequencial - startSequencial) << endl;
    cout << endl << "Tempo gasto em paralelo = " << ( endPara - startPara) << endl;

//-----------------------------------------------------
/*
Exercício 4 — Medindo tempo por thread
Adapte o código do exercício anterior para:
a) Medir e exibir o tempo total de execução.
b) Medir e exibir o tempo gasto por cada thread.
c) Mostrar quantas threads foram utilizadas no cálculo.
*/

    cout << endl << "Tempo Total de execucao = " << ( endPara - startSequencial) << endl;
    cout << endl << "Threads usadas: " << threads_usadas << endl;
    cout << endl << "Tempo de execucao de cada thread:" << endl;
    cout << endl << "Pressione enter para ver tempo de execucao de cada thread";
    cin.get();
    for(int i = 0; i < threads_usadas /*valor reduzido para better viewing*/; i++){
    cout << "  Thread: " << i << " Tempo de execucao: " << timeThread[i] << endl;
    }



//-----------------------------------------------------
/*
Exercício 5 — Escalonamento
Use novamente o cálculo de a[i] = x[i]^2 + y[i]^2 + z[i]^2, mas:
a) Execute com schedule(static) e schedule(dynamic, 1000).
b) Compare os tempos em diferentes quantidades de threads (2, 4, 8).
c) Explique em quais situações static e dynamic são mais adequados.
*/

    vector <double> timeThreadStatic(M);
    vector <double> timeThreadDynamic(M);
    int NumThreads = 0;
    int Continue = 0;

    while(Continue != -1){

        cout << "\nInsira o numero de threads a ser usado a seguir:\n: ";
        cin >> NumThreads;
        #pragma omp parallel num_threads(NumThreads)//inicia soma de vetores em paralelo
        {                
            threads_usadas = omp_get_num_threads();
            #pragma omp for schedule(static) //inicia soma de vetores em paralelo
                for (int i = 0; i < M; i++) { //loop em paralelo
                    double t0 = omp_get_wtime(); //tempo 0 da thread

                    a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);

                    double t1 = omp_get_wtime(); //tempo 1 da thread
                    timeThreadStatic[i] = (t1 - t0); // mede o tempo de cada thread e salva o numero da thread no mesmo index
                }
        }

        #pragma omp parallel num_threads(NumThreads)
        {
            #pragma omp for schedule(dynamic, 1000)
                for (int i = 0; i < M; i++) { //loop em paralelo
                    double t0 = omp_get_wtime(); //tempo 0 da thread

                    a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);

                    double t1 = omp_get_wtime(); //tempo 1 da thread
                    timeThreadDynamic[i] = (t1 - t0); // mede o tempo de cada thread e salva o numero da thread no mesmo index
                }       
        }
        cout << "\nThreads utilizadas: " << threads_usadas << endl;
        for(int i = 0; i < NumThreads; i++){
            cout << "\nThread: " << i << "\nstatic: " << timeThreadStatic[i] <<endl << "dynamic: " << timeThreadDynamic[i] << endl;
        }
        cout << "\nDeseja continuar? 1 para sim, -1 para nao.\n: ";
        cin >> Continue;
    }



}
    