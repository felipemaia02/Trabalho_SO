#define _GNU_SOURCE
#define _OPEN_THREADS
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

struct c {
    int saldo;
};
typedef struct c conta;

conta from, to;
int valor;

/* 
Variável utilizada como trava condicional:
0 -> Falso, trava fechada
1 -> Verdadeiro, trava aberta
*/
int disp = 1; 

/* 
Variável utilizada para determinar fluxo da conta:
0 -> From transfere para To
1 -> To transfere para From
*/
int flux = 0;

// Função executada pelas Threads
void *transferencia( void *arg){

    while (disp == 0) // Trava Fechada
        sleep(0.5); 

    disp = 0; // Fechando a Trava.

    if (flux == 0){
        if (from.saldo >= valor){ // 2
            from.saldo -= valor;
            to.saldo += valor;
        }
    }
    else{
        if (to.saldo >= valor){ // 2
            to.saldo -= valor;
            from.saldo += valor;
        }
    }
    

    printf("Saldo de c1: %d\n", from.saldo);
    printf("Saldo de c2: %d\n", to.saldo);
    printf("Transferência concluída com sucesso!\n");

    disp = 1; // Abrindo Trava.
    
    pthread_exit(0);
}
int main()
{
    pthread_t t_thread[100];

    // Todas as contas começam com saldo 1000
    from.saldo = 1000;
    to.saldo = 1000;
    valor = 10;

    
    for (int i = 0; i < 50; i++) {

        // Chamada para criar uma nova thread
        pthread_create(&t_thread[i], NULL, transferencia, NULL);
    }

    // for loop para esperar a execução das threads não finalizadas do PRIMEIRO fluxo
    for (int i = 0; i < 50; i++)
       pthread_join(t_thread[i], NULL);

    flux = 1; // Trocando o fluxo de transferência

    for (int i = 50; i < 100; i++) {

        // Chamada para criar uma nova thread
        pthread_create(&t_thread[i], NULL, transferencia, NULL);
    }

     // for loop para esperar a execução das threads não finalizadas do SEGUNDO fluxo
    for (int i = 50; i < 100; i++)
       pthread_join(t_thread[i], NULL);

    printf("Transferências concluídas e memória liberada.\n");
    return 0;
}