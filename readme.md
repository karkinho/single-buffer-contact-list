# Single Variable Contact List || Lista De Contatos De Variável Única

The objective of this project is to create a contact list that uses a single variable, being a buffer of void pointer.

### PT-BR

O objetivo deste projeto é criar uma lista de contatos onde o programa usa apenas uma única variável, sendo um buffer de ponteiro void.

### Memory space in the void pointer

Space of `sizeof( int )` : Used to count the number of entry's in the buffer.
Space of `sizeof( int )`: Used as a auxiliary int.
Space of `sizeof( char ) * LENGTH_BUFF`: Space used for reading stdin.

#### PT-BR

Espaço de `sizeof( int )` : Usado para contar o número de entradas na agenda.
Espaço de `sizeof( int )`: Usado como uma variavel auxiliar de tipo int.
Espaço de `sizeof( char ) * LENGTH_BUFF`: usado para guardar a leitura do stdin.

### Entry's in the data structure || Entradas na estrutura de dados

Each entry in the data structure consists of a name, age and email. in this order. The data is stored sequentially after the variables of the program.

#### PT-BR

Cada entrada na estrutura de dados contém nome, idade e e-mail, nesta exata ordem. As informações são armazenadas depois da variavel do programa.

## main.c

C file that contains all the functions of the contact list.

### PT-BR

Arquivo C que contém todas as funções da lista de contatos.

## lib.h

Contains all the declarations of the functions of all C files of the project, and also contains defines that help to write the program, with information on where in memory the variables are located and their sizes.

### PT-BR

Contém todas as declarações de funções de todos os arquivos do projeto, além de defines que são utilizados para facilitar a escrita do programa, com informações sobre onde na memória estão localizadas as variáveis e seus tamanhos.

## maintest.c & test.c

maintest is the main file with suppressed printfs for better readability in the terminal during testing and added exits in case any tests fail.

test is a file that creates the test entries that will be processed by maintest via bash input redirection. It takes an integer value in the arguments, which defines how many times it will generate entries for the contact list.

### PT-BR

maintest.c é o arquivo principal com algumas modificações. Grande parte dos printf foram removidos para facilitar a visualização no terminal, e foram adicionadas saídas do programa para caso alguma falha ocorra.

test.c é um arquivo que cria as entradas de teste que serão captadas pelo maintest através de redirecionamento de entrada no bash. Ele recebe um número inteiro nos argumentos, que define quantas vezes ele criará entradas para o teste.

## How To Execute || Como Executar

All the execution and compiling commands are inside the Makefile. The key commands are:

make: Compiles the program and runs it.
make test: Compiles and runs the tests.
make testval: Compiles and runs the tests using valgrind.

### PT-BR

Todos os comandos de execução estão dentro do Makefile, sendo os principais:

make: Compila o programa e o executa.
make test: Compila o programa e executa os testes.
make testval: Compila e executa os testes usando o valgrind
