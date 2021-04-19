#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/************************************************************************ 
QueueNode modela um elemento da pilha (um nó). Esse registro contém um 
inteiro para representar o valor (chave), demais campos necessários para 
atender a aplicação que está usando a pilha e, por fim, um campo next do 
tipo ponteiro para QueueNode que deve apontar para o próximo nó da pilha.
*************************************************************************/

struct Node{

	int info;
	struct Node *next;
	// inclua aqui os demais campos necessários
};

typedef struct Node QueueNode;


/************************************************************************* 
Queue modela uma fila. Contém contém um inteiro para armazenar a quanti-
dade de elementos da pilha, um ponteiro para o primeiro nó da fila (begin) 
e um ponteiro para o último nó da fila (end);
*************************************************************************/

typedef struct {

	int numberOfNodes;
	QueueNode* begin;
	QueueNode* end;
} Queue;


/*************************************************************************
Assinatura das funções que implementam operações elementares sobre filas
*************************************************************************/
Queue* create (); 
void destroy (Queue*);   
void destroyNode(QueueNode*);      
void enqueue (Queue *, int);  
QueueNode* dequeue (Queue *);
bool isEmpty (Queue *s);
QueueNode* search(Queue*,int);
void exception(int);  
void print (Queue*);            
void printNode (QueueNode*);

