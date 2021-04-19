#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALLOC_ERROR 0
#define OVERFLOW_WARNING 1
#define UNDERFLOW_WARNING 2
#define DELETE_WARNING 3

/************************************************************************ 
StackElement modela um elemento da pilha (um nó). Esse registro contém um 
inteiro para representar o valor (chave), demais campos necessários para 
atender a aplicação que está usando a pilha e, por fim, um campo next do 
tipo ponteiro para StackElement que deve apontar para o próximo nó da pilha.
*************************************************************************/

typedef struct {

	int info;
	// inclua aqui os demais campos necessários
}StackElement;




/************************************************************************* 
Stack modela uma pilha. Contém contém um inteiro para armazenar a quantidade
de elementos da pilha e um ponteiro para o nó topo de pilha (top);
*************************************************************************/

typedef struct {

	int numberOfElements;
	int capacity;
	StackElement* data;
	int top;
} Stack;


/*************************************************************************
Assinatura das funções que implementam operações elementares sobre pilhas
*************************************************************************/
Stack* create (); 

void destroy (Stack*);    
void destroyNode (StackElement*);     
void push (Stack *, int);  
StackElement* pop (Stack *);
bool isEmpty (Stack *);
void exception(int exceptionError);  
void print (Stack* );            
void printElement (StackElement);  




