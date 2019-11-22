# PROPOSTA SOLUÇÃO
Uma solução muito utlizada para evitar condições de corrida é criar uma Trava. Chamamos de Trava condicional já que especifíca melhor o conceito. 
Sendo assim, ao adicionarmos uma trava para o acesso das threads podemos impedir que elas acessem os saldos ao mesmo tempo. Porém, enquanto elas estão impossibilitadas pela trava optamos em por para "dormir" com o comando `sleep(0.5)`.


# P_THREAD
Alteramos o código para utilizar a biblioteca p_thread, uma biblioteca dedicada à criação e organização das mesmas.
Vamos passar por alguns comandos utilizados ao decorrer do programa:\
`#include <pthread>`: Incluindo a biblioteca.\
`pthread_t t_thread[100]`: Criamos uma array de 100 espaços do tipo pthread_t.\
`pthread_create(&t_thread[i], NULL, transferencia, 0);`: Esta função cria/inicia uma pthread_t ao decorrer da array.\
`pthread_join(t_thread[i], NULL);`: Espera as threads finalizarem.

# COMPLICAÇÕES
Um problema que estava ocorrendo depois da implementação das pthreads era que apesar do programa não apresentar nenhum erro ele não finalizava todas as operações.
Isto ocorria devido o for loop acabar antes da execução das pthreads e a main thread ao chegar no comando `return(0);` finalizava todas suas filhas.
Por isso, foi utilizado o comando `pthread_join` para que a main thread espere a execução das "filhas" não finalizadas.

# PROBLEMA DA SOLUÇÃO
Em algumas execuções a última thread não é executada, mas isso ocorre com uma frequência muita baixa e provavelmente pelo mesmo motivo do tópico **COMPLICAÇÕES**. 

