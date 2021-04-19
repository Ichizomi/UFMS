#include <stdio.h>
#include <stdlib.h>

#define ALLOC_ERROR 0
#define OVERFLOW_WARNING 1
#define UNDERFLOW_WARNING 2
#define DELETE_WARNING 3



/************************************************************************ 
MyHeapElement modela um elemento do heap. Esse registro contém um inteiro
para representar a prioridade no elemento e os campos necessários para 
atender a aplicação que está usando o heap.
*************************************************************************/


typedef struct {

	int priority;
	// inclua aqui os demais campos necessários
} MyHeapElement;



/************************************************************************* 
MyHeap modela o heap. Contém contém um inteiro para armazenar a quantidade
de elementos do heap, um inteiro para armazenar a capacidade máxima do heap
e um ponteiro para uma sequencia de elementos do heap.
*************************************************************************/
typedef struct {

	int numberOfElements;
	int capacity;
	MyHeapElement* S;
}MyHeap;


/*************************************************************************
Métodos para implementação das operações elementares sobre heaps
*************************************************************************/
MyHeap* create (int capacity); 
void destroy (MyHeap* heap);         
void add (MyHeap* heap, MyHeapElement el);  
void add_heap (MyHeap* heap, MyHeapElement el); 
MyHeapElement remove_max (MyHeap* heap);	
void update (MyHeap* heap, int i, int p);	
void build (MyHeap* heap); 			

/*************************************************************************
Métodos de apoio para as operações elementares sobre heaps
*************************************************************************/
int dad (int i);  
int left (int i);
int right (int i); 
void up (MyHeap* heap, int i);
void down (MyHeap* heap, int i);
void exchange (MyHeap* heap, int i, int k);  
int max (MyHeap* heap, int i); 
void exception(int exceptionError);  
void print (MyHeap* heap);            
void printElement (MyHeapElement s);  




