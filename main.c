#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
// 64kB stack
#define FIBER_STACK 1024*64
struct c {
    int saldo;
};
typedef struct c conta;

conta from, to;
int valor;

// Função executada pelas Threads
int transferencia( void *arg){

    if (from.saldo >= valor){ // 2
        from.saldo -= valor;
        to.saldo += valor;
    }

    printf("Saldo de c1: %d\n", from.saldo);
    printf("Saldo de c2: %d\n", to.saldo);
    printf("Transferência concluída com sucesso!\n");

    return 0;
}
int main()
{
    void* stack;
    pid_t pid;
    int i;

    // Alocando espaço no stack
    stack = malloc( FIBER_STACK );
    if ( stack == 0 )
    {
        perror("malloc: could not allocate stack");
        exit(1);
    }
    // Todas as contas começam com saldo 1000
    from.saldo = 1000;
    to.saldo = 1000;


    printf( "Transferindo 10 para a conta c2\n" );
    valor = 10;
    for (i = 0; i < 100; i++) {

        sleep(1); // Adicionando tempo de espera entre cada loop.

        // Chamada para criar uma nova thread
        pid = clone( &transferencia, (char*) stack + FIBER_STACK,
        SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0 );

        if ( pid == -1 ){
            perror( "clone" );
            exit(2);
        }
    }
    // Liberando o Stack
    free( stack );
    printf("Transferências concluídas e memória liberada.\n");
    return 0;
}