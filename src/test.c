#include "lib.h"

int count = 1 , quantity = 0;

int main( int argc , char *argv[] ) {
    /*
    ======================  
    main

    calls the functions that will make the tests.
    ======================
    */

    sscanf( argv[1] , "%d" , &quantity );

    SmallCase();
    BigCase();
    Add();
    printf( "4\n" );
    SearchAll();
    RemoveAll();
    printf( "4\n" );
    Add();
    printf("4\n");
    SearchAllInverse();
    RemoveAllInverse();
    printf("4\n");
    printf( "5\n" );
    return 0;
}

void Add( ){
    /*
    ======================  
    Add

    Adds entry's to the data structure.
    ======================
    */
    count = 1;
    while ( count <= quantity ) {
        printf( "1\n" );
        printf( "%d\n" , count );
        printf( "%d\n" , count );
        printf( "%d\n" , count );
        count++;
    }
}

void SearchAll( ) {
    /*
    ======================  
    SearchAll

    searchs all entry's in the data structure left to right
    ======================
    */
    count = 1;
    while ( count <= quantity ) {
        printf( "3\n" );
        printf( "%d\n" , count );
        count++;
    }
}

void RemoveAll( ) {
    /*
    ======================  
    SearchAll

    removes all entry's in the data structure from left to right
    ======================
    */
    count = 1;
    while ( count <= quantity ) {
        printf( "2\n" );
        printf( "%d\n" , count );
        count++;
    }
}

void SearchAllInverse( ) {
    /*
    ======================  
    SearchAll

    searchs all entry's in the data structure from right to left
    ======================
    */
    count = quantity;
    while ( count >= 1 ) {
        printf( "3\n" );
        printf( "%d\n" , count );
        count--;
    }
}

void RemoveAllInverse( ) {
    /*
    ======================  
    SearchAll

    removes all entry's in the data structure from right to left
    ======================
    */
    count = quantity;
    while ( count >= 1 ) {
        printf( "2\n" );
        printf( "%d\n" , count );
        count--;
    }
}

void SmallCase() {
    /*
    ======================  
    SmallCase

    Add, search and remove the small possible entry in the data structure
    ======================
    */
    printf( "1\n" );
    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    printf( "4\n" );
    printf( "3\n" );
    printf( "\n" );
    printf( "2\n" );
    printf( "\n" );
    printf( "4\n" );
}

void BigCase(){
    /*
    ======================  
    BigCase

    Add, search and remove the biggest possible entry in the data structure
    ======================
    */
    printf( "1\n" );
    printf( "1234567890123456789\n" );
    printf( "%d\n", INT_MAX );
    printf( "123456789012345678901234567890123456789\n" );
    printf( "4\n" );
    printf( "3\n" );
    printf( "1234567890123456789\n" );
    printf( "2\n" );
    printf( "1234567890123456789\n" );
    printf( "4\n" );
}