#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h> 

// SIZE_BUFFER | AUX_INT | AUX_POINTER | BUFF_NAME | BUFF_EMAIL | BUFF_INT | INSERTION_POINT

#define LENGTH_BUFF 255 // length of the buffer that reads char inputs
#define SIZE_VARIABLES ( sizeof( int ) * 3 + sizeof( void * ) + sizeof( char ) * 12 + sizeof( char ) * LENGTH_BUFF * 2 ) // size of all the variables in the start of the buffer
#define JUMP_SIZE_BUFFER 0 // variable for getting the size of the buffer in bytes
#define JUMP_AUX_INT sizeof( int ) // a auxiliary int variable 
#define JUMP_AUX_POINTER ( sizeof( int ) * 2 ) // a auxiliary void pointer
#define JUMP_BUFF_NAME ( sizeof( int ) * 2 + sizeof( void * ) ) // a buffer for storing the input for the name of a entry
#define JUMP_BUFF_EMAIL ( sizeof( int ) * 2 + sizeof( void * ) + sizeof( char ) * LENGTH_BUFF ) // a buffer for storing the input for the email of a entry
#define JUMP_BUFF_INT ( sizeof( int ) * 2 + sizeof( void * ) + sizeof( char ) * LENGTH_BUFF * 2 ) // a buffer for storing the input of type int
#define JUMP_LAST_ENTRY ( sizeof( int ) * 2 + sizeof( void * ) + sizeof( char ) * LENGTH_BUFF * 2  + sizeof( char ) * 12 ) // stores the bytes for the deslocation to the insertion point for the push

// NEXT | AGE | JUMP_EMAIL | NAME | EMAIL

#define JUMP_NEXT 0 // inside a entry is the size in bytes of that entry
#define JUMP_AGE sizeof( int ) // Stores the age of the entry
#define JUMP_JUMP_EMAIL ( sizeof( int ) * 2 ) // stores the number of bytes for the deslocation to the start of the email of that entry
#define JUMP_NAME ( sizeof( int ) * 3 ) // Stores the name of the entry
#define SIZE_ENTRY_STATIC ( sizeof( int ) * 3 ) // size of the statics elements of the entry

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

