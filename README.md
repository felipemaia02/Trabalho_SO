# PROPOSTA SOLUÇÃO
Se a ideia é permitir que apenas uma thread acesse o Saldo podemos colocar um tempo de espera entre a criação das threads sendo assim, se colocar um tempo de espera de 1 segundo, através do comando sleep(1), a thread criado tem tempo suficiente para realizar sua operação, deixando o saldo livre para a próxima thread.

# ERRO DA SOLUÇÃO
Diferente da proposta da solução anterior o problema não está na execução em si, porém o objetivo do projeto não é atingido. Ao colocar um tempo de espera entre as threads acabamos com a concorrência, além de criar um sistema extremamente lento. Como ensinado nas aulas o tempo não pode ser um fator utilizado para relacionar threads/processos já que não é possível controlá-lo.
