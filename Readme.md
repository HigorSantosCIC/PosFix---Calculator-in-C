## Gerar novamente os objetos: gcc -c funcao.c calculadora.c intopos.c -std=c99 

## Compilar os arquivos: gcc -o main main.c funcao.o calculadora.o intopos.o -lm -std=c99 -Wall



## Executar: ./main



///////////////////////////////////////////////////////////////////////////////
## Compilação:

- Abra o terminal para este diretorio.
- 
Os arquivos objetos deverão ser gerados da seguinte maneira:
 ```gcc -c funcao.c calculadora.c intopos.c -std=c99```, 
O arquivo main.c deve ser compilado após os arquivos funcao.c, calculadora.c e  intopos.c já terem sido compilados.


Execução:
 Abra o terminal para este diretorio. No terminal, use o seguinte comando:./main 


Informações: Versão do compilador: gcc 7.3.0 (ubuntu 7.3.0-16ubuntu3) 
Versão do SO: Ubuntu 18.04 LTS Versão da linguagem: C no padrão c99.
Bibliotecas utilizadas: stdio.h, stdlib.h, math.h, stdbool.h, string.h e bibliotecas internas.
