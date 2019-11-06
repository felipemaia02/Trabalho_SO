# PROPOSTA SOLUÇÃO
Uma solução muito utlizada para evitar condições de corrida é criar uma Trava. Chamamos de Trava condicional já que especifíca melhor o conceito. 
Sendo assim, ao adicionarmos uma trava para o acesso das threads podemos impedir que elas acessem os saldos ao mesmo tempo. Porém, enquanto elas estão impossibilitadas pela trava optamos em por para "dormir" com o comando "sleep(0.1)"

# ERRO DA SOLUÇÃO
Apesar do conceito estar bem claro, o programa ainda está defeituoso (Erro de segmentação principalmente), após semanas tentando acabamos deixando de lado.
O que suspeitamos é que enquanto a trava está fechada o programa acumula as threads o que causa que elas acessem o saldo antes da trava ser ativada.

