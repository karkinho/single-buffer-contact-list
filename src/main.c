#include "lib.h"

void *pBuffer = NULL , *auxPointer = NULL;
int *auxInt = NULL , *sizeBuffer = NULL;
char *buffName = NULL, *buffEmail = NULL, *buffInt = NULL;

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
    while (  *auxInt != 5 ) {
        printf( "\tDigite 1 Para Adicinar a Agenda\n" );
        printf( "\tDigite 2 Para Remover da Agenda\n" );
        printf( "\tDigite 3 Para Buscar na Agenda\n" );
        printf( "\tDigite 4 Para Listar a Agenda\n" );
        printf( "\tDigite 5 Para Sair\n\n" );

        ReadToBuffInt();
        sscanf( buffInt , "%d" , auxInt );

        switch ( *auxInt ) {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                Search();
                break;     
            case 4:
                List();
                break;
            case 5:
                break;    
            default:
                printf( "\tDigite Um Número Válido\n\n");
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
}

void SearchPrint(){
    /* 
    ======================  
    SearchPrint

    Calls Search and prints if the information in the returned index
    ======================
    */
}

void Search(){
    /*
    ======================  
    Search

    Reads a name from the user and search for it in the contact list, if it finds returns the index
    ======================
    */
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
    sizeBuffer = NULL;
    auxInt = NULL;
    auxPointer = NULL;
    buffName = NULL;
    buffEmail = NULL;
    buffInt = NULL;
}

void ReadToBuffInt() {
    /*
    ======================  
    ReadToBuffInt

    Reads a input from the stdin and puts in the buffer for int
    ======================
    */
    fgets( buffInt , 12 , stdin );
    buffInt[ strcspn( buffInt , "\n" ) ] = '\0';  
}

void ReadToBuffName() {
    /*
    ======================  
    ReadToBuffName

    Reads a input from the stdin and puts in the buffer for the name
    ======================
    */
    fgets( buffName , LENGTH_BUFF , stdin );
    buffName[ strcspn( buffName , "\n" ) ] = '\0';  
}

void ReadToBuffEmail() {
    /*
    ======================  
    ReadToBuffEmail

    Reads a input from the stdin and puts in the buffer for the email
    ======================
    */
    fgets( buffEmail , LENGTH_BUFF , stdin );
    buffEmail[ strcspn( buffEmail , "\n" )  ] = '\0';  
}

void Push() {
    /*
    ======================  
    Push

    Puts a new entry in the end of the contaclist
    ======================
    */

    printf( "Digite o Nome: " );
    ReadToBuffName();
    printf( "Digite A Idade: " );
    ReadToBuffInt();
    printf( "Digite o Email: " );
    ReadToBuffEmail();
    printf( "\n" );
    
    *auxInt = strlen( buffName ) + SIZE_ENTRY_STATIC + strlen( buffEmail ) + 2;
    *sizeBuffer += *auxInt ;
    MyRealloc();

    auxPointer = ( void * )( pBuffer + *( int * )( pBuffer + JUMP_LAST_ENTRY ) );

    *( int * )( auxPointer + JUMP_NEXT ) = *auxInt;
    *( int * )( auxPointer + JUMP_JUMP_EMAIL ) = strlen( buffName ) + SIZE_ENTRY_STATIC + 1;
    sscanf( buffInt , "%d" , ( int * )( auxPointer + JUMP_AGE ) );
    strcpy( ( char * )( auxPointer + JUMP_NAME ) , buffName );
    strcpy( ( char * )( auxPointer + *( int * )( auxPointer + JUMP_JUMP_EMAIL ) ) , buffEmail ); 
    
    *( int * )( pBuffer + JUMP_LAST_ENTRY ) = *sizeBuffer;
}

void MyRealloc() {
    /*
    ======================  
    MyRealloc

    Realloc pBuffer and checks if it was successful
    ======================
    */
    pBuffer = realloc( pBuffer , *sizeBuffer );
    if ( pBuffer == NULL ) {
        printf( "Memória não alocada\n" );
        exit( 0 );
    }
    sizeBuffer = ( int * ) pBuffer;
    auxInt = ( int * )( pBuffer + JUMP_AUX_INT );
    auxPointer = ( void * )( pBuffer + JUMP_AUX_POINTER );
    buffName = ( char * )( pBuffer + JUMP_BUFF_NAME );
    buffEmail = ( char * )( pBuffer + JUMP_BUFF_EMAIL );
    buffInt = ( char * )( pBuffer + JUMP_BUFF_INT );
}

void List() {
    /*
    ======================  
    List

    Lists all the entry's 
    ======================
    */
    
    if ( *sizeBuffer == SIZE_VARIABLES ) {
        printf( "Agenda Vazia\n\n" );
        *auxInt = 0;    
        return;
    }

    *auxInt = SIZE_VARIABLES;

    printf( "-----------------------------\n" );
    while ( *sizeBuffer != *auxInt ) {
        auxPointer = pBuffer;
        auxPointer = ( void * )( auxPointer + *auxInt );
        printf( "Nome: %s\n", ( char * )( auxPointer + JUMP_NAME ) );
        printf( "Idade: %d\n", *( int * )( auxPointer + JUMP_AGE ) );
        printf( "Email: %s\n", ( char * )( auxPointer + *( int * )( auxPointer + JUMP_JUMP_EMAIL ) ) );
        printf( "-----------------------------\n" );
        *auxInt += *( int *)( auxPointer + JUMP_NEXT );
    }
    *auxInt = 0;
    printf( "\n" );
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
    sizeBuffer = ( int * ) pBuffer;
    auxInt = ( int * )( pBuffer + JUMP_AUX_INT );
    auxPointer = ( void * )( pBuffer + JUMP_AUX_POINTER );
    buffName = ( char * )( pBuffer + JUMP_BUFF_NAME );
    buffEmail = ( char * )( pBuffer + JUMP_BUFF_EMAIL );
    buffInt = ( char * )( pBuffer + JUMP_BUFF_INT );
    *sizeBuffer = SIZE_VARIABLES;
    *auxInt = 0;
    *( int* )( pBuffer + JUMP_LAST_ENTRY ) = SIZE_VARIABLES;
}


 