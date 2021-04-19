#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALLOC_ERROR 0
#define OVERFLOW_WARNING 1
#define UNDERFLOW_WARNING 2
#define DELETE_WARNING 3

/************************************************************************ 
QueueElement modela um elemento da fila circular (um nó). Esse registro contém um 
inteiro para representar o valor (chave), demais campos necessários para 
atender a aplicação que está usando a fila circular e, por fim, um campo next do 
tipo ponteiro para QueueElement que deve apontar para o próximo nó da fila circular.
*************************************************************************/

typedef struct {

	int info;
	// inclua aqui os demais campos necessários
}QueueElement;




/************************************************************************* 
Queue modela uma fila circular. Contém contém um inteiro para armazenar a quantidade
de elementos da fila circular e um ponteiro para o nó topo de fila circular (top);
*************************************************************************/

typedef struct {

	int numberOfElements;
	int capacity;
	QueueElement* data;
	int begin;
	int end;
} Queue;


/*************************************************************************
Assinatura das funções que implementam operações elementares sobre fila circulars
*************************************************************************/
Queue* create (); 

void destroy (Queue*);    
void destroyNode (QueueElement*);     
void enqueue (Queue *, int);  
QueueElement* dequeue (Queue *);
bool isEmpty (Queue *);
void exception(int exceptionError);  
void print (Queue* );            
void printElement (QueueElement);  




