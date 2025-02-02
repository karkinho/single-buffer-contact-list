# Single Buffer Contact List

## Introdução

Este programa é uma agenda que utiliza apenas de um bufer para guardar as variaveis utilizadas para a execução do programa e todas as entradas na agenda, não á variaveis declaradas fora do buffer, somente ponteiros que apontão para as variaveis que estão dentro do buffer.

## Testes

A principal forma de teste que foi usada nesse programa foi um arquivo c que atraves de bash redirecting simula inputs na programa assim podendo fazer testes longos e automaticos, um teste feito foi adicionar 20000 entradas procurar elas da esquerda para direita e retirar elas nessa ordem depois adicionar elas novamente e fazer as mesma ações só que da direita para a esquerda, e utilizando o valgrind que levantará erros de memória caso aconteça, nos testes feitos não foi levantado nenhum.

## Como Executar

Os comandos para a execução do programa estão dentro do makefile, que contem como executar o programa sem e com valgrind, tambem podendo usar o address sanitize caso prefira e rodar os testes automatizados.
