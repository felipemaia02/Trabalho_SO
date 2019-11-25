# PROPOSTA
Compreender o funcionamento do sistema operacional e sua comunicação com os dispositivos
conectados.

Mais informações sobre o projeto podem ser encontrados no arquivo oferecido pelo professor Eduardo Santos no arquivo: `Plano Projeto Final.pdf` 

# DIVISÃO
Abordamos o problema com 3 estratégias as quais cada uma será publicada em sua branch específica, sendo a última branch "Trava Condicional" a resolução final.
- Tempo de Espera
- Trava Condicional

# O PROBLEMA
O problema encontrado no exercício passado é a condição de corrida. Isto ocorre quando o processo depende de uma sequência e/ou ocorrência de outro evento. Neste caso nosso evento é o acesso aos Saldos. 
Quando uma thread acessa o saldo ela impossibilita o acesso das outras. Ou seja, nossas threads são dependentes do resultado da thread anterior. 