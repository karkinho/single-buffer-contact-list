#include "lib.h"

void *pBuffer = NULL;

int main( ) {
    /*
    ======================  
    main

    Starts the data structure, the menu and Clears the data structure when the pogramns ends; 
    ======================
    */
    Reset();
    Menu();
    Clear();
    return 0;
}

void Menu() {
    /*
    ======================  
    menu

    Prints the menu in the terminal and gets the input of the action the user wants to make and calls the respective function.
    ======================
    */
    while ( *( int *)( pBuffer + JUMP_AUX ) != 5 ) {
        /*printf( "\tDigite 1 Para Adicinar a Agenda\n" );
        printf( "\tDigite 2 Para Remover da Agenda\n" );
        printf( "\tDigite 3 Para Buscar na Agenda\n" );
        printf( "\tDigite 4 Para Listar a Agenda\n" );
        printf( "\tDigite 5 Para Sair\n\n" ); */ 

        ReadToBuff();
        if ( strlen( ( char * )( pBuffer + JUMP_BUFF ) ) == 0 ) {
            *( int *)( pBuffer + JUMP_AUX ) = 0;
        } else {
            sscanf( ( char * )( pBuffer + JUMP_BUFF ) , "%d" , ( int *)( pBuffer + JUMP_AUX) );
        }
        

        switch ( *( int *)( pBuffer + JUMP_AUX ) ) {
            case 1:
                Push();
                *( int * )( pBuffer + JUMP_AUX ) = 0;
                break;
            case 2:
                // printf( "Digite o Nome Para Excluir: ");
                Pop();
                *( int * )( pBuffer + JUMP_AUX ) = 0;
                break;
            case 3:
                // printf( "Digite o Nome Para Procurar: ");
                SearchPrint();
                *( int * )( pBuffer + JUMP_AUX ) = 0;
                break;     
            case 4:
                List();
                *( int * )( pBuffer + JUMP_AUX ) = 0;
                break;
            case 5:
                break;   
            default:
                //printf( "\tDigite Um Número Válido\n\n");
                break;
        }
    }
}

void Pop(){
    /*
    ======================  
    Pop

    Calls Search and delete the returned entry
    ======================
    */
    Search();
    if( *( int * )( pBuffer + JUMP_AUX ) == -1 ){
        printf( "Pessoa Não Encontrada\n");
        exit( 0 );
        return;
    }
    if( !( *( int * )( pBuffer + JUMP_AUX ) + 1 == *( int * )( pBuffer + JUMP_ENTRYS) && *( int * )( pBuffer + JUMP_ENTRYS ) != 0 ) ) {
        memcpy( ( void * )( pBuffer + SIZE_VARIABLES + SIZE_ENTRY * *( int *)( pBuffer + JUMP_AUX ) ) , ( void * )( pBuffer + SIZE_VARIABLES + SIZE_ENTRY * ( *( int *)( pBuffer + JUMP_AUX ) + 1 ) ) , SIZE_ENTRY * ( *( int * )( pBuffer + JUMP_ENTRYS ) - *( int * )( pBuffer + JUMP_AUX ) - 1 ) );
        *( int *)( pBuffer + JUMP_ENTRYS) -= 1;
        MyRealloc();
    } else if( *( int * )( pBuffer + JUMP_ENTRYS ) != 0 ) {
        *( int *)( pBuffer + JUMP_ENTRYS) -= 1;
        MyRealloc();
    }
    //printf( "\n" );
}

void SearchPrint(){
    /*
    ======================  
    SearchPrint

    Calls Search and prints if the information in the returned index
    ======================
    */
    Search();
    if( *( int * )( pBuffer + JUMP_AUX ) == -1 ){
        printf( "Pessoa Não Encontrada\n");
        exit( 0 );
        return;
    }
    /*printf( "Pessoa Encontrada: \n");
    printf( "-----------------------------\n");
    printf( "Nome: %s\n", ( char * )( pBuffer + JUMP_NAME + ( SIZE_ENTRY * *( int * )( pBuffer + JUMP_AUX ) ) ) );
    printf( "Idade: %d\n", *( int * )( pBuffer + JUMP_AGE + ( SIZE_ENTRY * *( int * )( pBuffer + JUMP_AUX ) ) ) );
    printf( "Email: %s\n", ( char * )( pBuffer + JUMP_EMAIL + ( SIZE_ENTRY * *( int * )( pBuffer + JUMP_AUX ) ) ) );
    printf( "-----------------------------\n"); */
}

void Search(){
    /*
    ======================  
    Search

    Reads a name from the user and search for it in the contact list, if it finds returns the index
    ======================
    */
    ReadToBuff();
    *( int *)( pBuffer + JUMP_AUX ) = 0;
    while ( *( int * )( pBuffer + JUMP_AUX ) < *( int * )( pBuffer + JUMP_ENTRYS ) ) {
        if ( strcmp( ( char * )( pBuffer + JUMP_BUFF ) , ( char * )( pBuffer + JUMP_NAME + ( SIZE_ENTRY * *( int * )( pBuffer + JUMP_AUX ) ) ) ) == 0 ) {
            return;
        } 
        *( int * )( pBuffer + JUMP_AUX ) += 1;
    }
    *( int *)( pBuffer + JUMP_AUX ) = - 1;
}

void Clear() { 
    /*
    ======================  
    Clear

    Free's the data structure and put null in the pointer
    ======================
    */
    free( pBuffer );
    pBuffer = NULL;
}

void ReadToBuff() {
    /*
    ======================  
    ReadToBuff

    Reads a input from the stdin and puts in the buffer to be treated latter
    ======================
    */
    fgets( ( char * )( pBuffer + JUMP_BUFF ) , LENGTH_BUFF , stdin );
    *( char * )( pBuffer + JUMP_BUFF + strcspn( ( char * )( pBuffer + JUMP_BUFF ) , "\n" ) ) = '\0';  
}

void Push() {
    /*
    ======================  
    Push

    Puts a new entry in the end of the contaclist
    ======================
    */
    *( int * )( pBuffer + JUMP_ENTRYS ) += 1;
    *( int * )( pBuffer + JUMP_AUX ) = *( int * )( pBuffer + JUMP_ENTRYS ) - 1;
    MyRealloc();

    // printf( "Digite o Nome: ");
    ReadToBuff(); 
    strncpy( ( void * )( pBuffer + JUMP_NAME + ( SIZE_ENTRY * *( int * )( pBuffer + JUMP_AUX ) ) ) , ( void * )( pBuffer + JUMP_BUFF ) , LENGTH_NAME );

    // printf( "Digite a Idade: ");
    ReadToBuff(); 
    if ( strlen( ( char * )( pBuffer + JUMP_BUFF ) ) == 0 ) {
        *( int * )( pBuffer + JUMP_AGE + ( SIZE_ENTRY * ( *( int * )( pBuffer + JUMP_ENTRYS ) - 1 ) ) ) = 0;
    } else {
        sscanf( ( char * )( pBuffer + JUMP_BUFF ) , "%d" , ( int * )( pBuffer + JUMP_AGE + ( SIZE_ENTRY * *( int * )( pBuffer + JUMP_AUX ) ) ) );
    }

    // printf( "Digite o Email: ");
    ReadToBuff();
    strncpy( ( char * )( pBuffer + JUMP_EMAIL + ( SIZE_ENTRY * *( int * )( pBuffer + JUMP_AUX ) ) ) , ( char * )( pBuffer + JUMP_BUFF ) , LENGTH_EMAIL );

    //printf( "\n " );    
}

void MyRealloc() {
    /*
    ======================  
    MyRealloc

    Realloc pBuffer and checks if it was successful
    ======================
    */
    pBuffer = realloc( pBuffer , SIZE_VARIABLES + SIZE_ENTRY * *( int * )( pBuffer + JUMP_ENTRYS ) );
    if ( pBuffer == NULL ) {
        printf( "Memória não alocada\n" );
        exit( 0 );
    }
}

void List() {
    if( !( *( int * )( pBuffer + JUMP_ENTRYS ) == 0 ) ) {
        *( int * )( pBuffer + JUMP_AUX ) = 0;
        printf( "-----------------------------\n");
        while ( *( int * )( pBuffer + JUMP_AUX ) < *( int * )( pBuffer + JUMP_ENTRYS ) ) {
            printf( "Nome: %s\n", ( char * )( pBuffer + JUMP_NAME + ( SIZE_ENTRY * *( int * )( pBuffer + JUMP_AUX ) ) ) );
            printf( "Idade: %d\n", *( int * )( pBuffer + JUMP_AGE + ( SIZE_ENTRY * *( int * )( pBuffer + JUMP_AUX ) ) ) );
            printf( "Email: %s\n", ( char * )( pBuffer + JUMP_EMAIL + ( SIZE_ENTRY * *( int * )( pBuffer + JUMP_AUX ) ) ) );
            printf( "-----------------------------\n");
            *( int * )( pBuffer + JUMP_AUX ) += 1;
        }
    } else {
        printf( "Agenda Vazia\n" );
    }
    // printf( "\n" );
}

void Reset() {
    /*
    ======================  
    Reset

    Starts the data structure.
    ======================
    */
    pBuffer = malloc( SIZE_VARIABLES );
    if ( pBuffer == NULL ) {
        printf( "Memória não alocada\n" );
        exit( 0 );
    }
    *( int * )( pBuffer + JUMP_ENTRYS ) = 0;
    *( void ** )( pBuffer + JUMP_AUX ) = NULL;
}


 