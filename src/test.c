#include "lib.h"

int count = 1 , quantity = 0;

/*
======================  
main

calls the functions that will make the tests.
======================
*/
int main( int argc , char *argv[] ) {
    sscanf( argv[1] , "%d" , &quantity );

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

/*
======================  
Add

Adds entry's to the data structure.
======================
*/
void Add( ){
    count = 1;
    while ( count <= quantity ) {
        printf( "1\n" );
        printf( "%d\n" , count );
        printf( "%d\n" , count );
        printf( "%d\n" , count );
        count++;
    }
}

/*
======================  
SearchAll

searchs all entry's in the data structure left to right
======================
*/
void SearchAll( ) {
    count = 1;
    while ( count <= quantity ) {
        printf( "3\n" );
        printf( "%d\n" , count );
        count++;
    }
}

/*
======================  
SearchAll

removes all entry's in the data structure from left to right
======================
*/
void RemoveAll( ) {
    count = 1;
    while ( count <= quantity ) {
        printf( "2\n" );
        printf( "%d\n" , count );
        count++;
    }
}

/*
======================  
SearchAll

searchs all entry's in the data structure from right to left
======================
*/
void SearchAllInverse( ) {
    count = quantity;
    while ( count >= 1 ) {
        printf( "3\n" );
        printf( "%d\n" , count );
        count--;
    }
}

/*
======================  
SearchAll

removes all entry's in the data structure from right to left
======================
*/
void RemoveAllInverse( ) {
    count = quantity;
    while ( count >= 1 ) {
        printf( "2\n" );
        printf( "%d\n" , count );
        count--;
    }
}
