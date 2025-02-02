#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h> 

#define LENGTH_BUFF 255
#define SIZE_VARIABLES ( sizeof( int ) * 3 + sizeof( void * ) + sizeof( char ) * 12 + sizeof( char ) * LENGTH_BUFF * 2 ) // Size Of the buffer | Int Aux | Aux pointer | Buff for reading stdin
#define JUMP_SIZE_BUFFER 0
#define JUMP_AUX_INT sizeof( int )
#define JUMP_AUX_POINTER ( sizeof( int ) * 2 )
#define JUMP_BUFF_NAME ( sizeof( int ) * 2 + sizeof( void * ) )
#define JUMP_BUFF_EMAIL ( sizeof( int ) * 2 + sizeof( void * ) + sizeof( char ) * LENGTH_BUFF )
#define JUMP_BUFF_INT ( sizeof( int ) * 2 + sizeof( void * ) + sizeof( char ) * LENGTH_BUFF * 2 )
#define JUMP_LAST_ENTRY ( sizeof( int ) * 2 + sizeof( void * ) + sizeof( char ) * LENGTH_BUFF * 2  + sizeof( char ) * 12 )
#define JUMP_NEXT 0
#define JUMP_AGE sizeof( int )
#define JUMP_JUMP_EMAIL ( sizeof( int ) * 2 )
#define JUMP_NAME ( sizeof( int ) * 3 )
#define SIZE_ENTRY_STATIC ( sizeof( int ) * 3 )
// Quantity of bytes to next | bytes to email | age | name | email

// declarations from main.c

void Pop(); 
void MyRealloc();
void Push();   
void Reset(); 
void List();  
void Search(); 
void Clear(); 
void Menu(); 
void SearchPrint();
void ReadToBuffInt();
void ReadToBuffName();
void ReadToBuffEmail();

// declarations from tests.c

void Add();
void SearchAll();
void RemoveAll();
void SearchAllInverse();
void RemoveAllInverse();
void BigCase();
void SmallCase();

