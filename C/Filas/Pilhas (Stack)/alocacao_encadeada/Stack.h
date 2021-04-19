#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALLOC_ERROR 0
#define OVERFLOW_WARNING 1
#define UNDERFLOW_WARNING 2
#define DELETE_WARNING 3

/************************************************************************ 
StackNode modela um elemento da pilha (um nó). Esse registro contém um 
inteiro para representar o valor (chave), demais campos necessários para 
atender a aplicação que está usando a pilha e, por fim, um campo next do 
tipo ponteiro para StackNode que deve apontar para o próximo nó da pilha.
*************************************************************************/

struct Node{

	int info;
	struct Node *next;
	// inclua aqui os demais campos necessários
};

typedef struct Node StackNode;


/************************************************************************* 
Stack modela uma pilha. Contém contém um inteiro para armazenar a quantidade
de elementos da pilha e um ponteiro para o nó topo de pilha (top);
*************************************************************************/

typedef struct {

	int numberOfNodes;
	StackNode* top;
} Stack;


/*************************************************************************
Assinatura das funções que implementam operações elementares sobre pilhas
*************************************************************************/
Stack* create (); 

void destroy (Stack*);    
void destroyNode (StackNode*);     
void push (Stack *, int);  
StackNode* pop (Stack *);
bool isEmpty (Stack *);

void exception(int exceptionError);  
void print (Stack* );            
void printNode (StackNode *);  




