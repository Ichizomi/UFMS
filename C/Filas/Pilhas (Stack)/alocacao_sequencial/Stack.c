#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"


/************************************************************************ 
Implementação de uma estrutura de dados do tipo Pilha com alocação 
sequencial na memória . O limite para a quantidade de elementos é 
dada pelo valor de "capacity", fornecido na entrada. Podem ser inseridos 
elementos repetidos. Inserções e remocoões obedecem política LIFO 
(last in first out) e têm complexidade constante. A inserção e a remoção 
ocorrem no mesmo extremo (topo)
************************************************************************/


/************************************************************************ 
Função de Tratamento de exceção
*************************************************************************/
void exception(int exceptionError)
{

	switch(exceptionError)
	{
		case ALLOC_ERROR: 	
				printf("\nALLOC ERROR");
				exit(1);
		case OVERFLOW_WARNING:
				printf("\nOVERFLOW WARNING" );
				break;
		case UNDERFLOW_WARNING:
				printf("\nUNDERFLOW WARNING");
				break;
		case DELETE_WARNING:
				printf("\nDELETE WARNING");
				break;
		default:
				printf("\nUNKNOWN ERROR");
				exit(1);
	}
}

/************************************************************************ 
Criação de uma pilha vazia com capacidade limitada por "capacity"
*************************************************************************/

Stack* create (int capacity)
{
	Stack* s = (Stack*) malloc (sizeof(Stack));
	int i;

	/* inicialmente, a pilha está vazia */
	s->numberOfElements = 0;
	s->capacity = capacity;
	/* alocação de memória para armazenamento dos dados*/
	s->data = (StackElement*) malloc (sizeof(StackElement) * capacity);
	/* topo de pilha é -1 já que não há elementos na pilha*/
	s->top = -1;
	if (s->data == NULL) exception(ALLOC_ERROR);

	return s;
} 


/************************************************************************ 
Liberação de toda memória previamente alocada parar armazenar elementos 
da pilha (destruição de toda a pilha)
*************************************************************************/
void destroy (Stack* s)
{
	if (s->data) free (s->data);
	if (s) free (s);

}        


/************************************************************************ 
Inserção de um novo elemento na pilha s - o elemento em questão tem apenas 
o dado info (por simplicidade). A inserção ocorre no topo da pilha e 
tem complexidade constante - O(1)
*************************************************************************/
void push (Stack *s, int info)
{
	StackElement el;
	el.info = info;

	if (s->top == s->capacity) exception (OVERFLOW_WARNING);

	else
	{	
		(s->top)++;
		s->data [s->top] = el;
		
	}
	(s->numberOfElements)++;

}  


/************************************************************************ 
Remoção de um nó da pilha s - a remoção sempre ocorre no topo da pilha
e tem complexidade constante - O(1). Se não há elementos para remover, 
pop retorna NULL
*************************************************************************/

StackElement* pop (Stack *s)
{

	StackElement *tmp = NULL;
	if ( s->numberOfElements == 0) exception (UNDERFLOW_WARNING);

	else  
	{
		tmp = &(s->data [s->top]);
		(s->top)--;		
		(s->numberOfElements)--;
	}
	return tmp;
}

/**************************************************************************
Imprime os dados armazenados na pilha
***************************************************************************/
void print (Stack* s)
{
	int i;

	printf("\n\nCapacity: %d", s->capacity);		
	printf("\nNumber of Nodes: %d", s->numberOfElements);	
	printf("\nTop: %d", s->top);	
	printf("\nElements:\n");

	for (i=0; i<=s->top; i++)
	{
		printElement(s->data[i]);
	}

	
} 

/**************************************************************************
Imprime os dados de um elemento da pilha
***************************************************************************/
void printElement (StackElement el)
{
	printf ("%d ", el.info);
	// implemente aqui a impressão dos demais campos do nó
} 


/************************************************************************ 
Realiza um percurso sobre os elementos da pilha.O objetivo é realizar 
a busca de um elemento "info" (inteiro) na estrutura. A busca bem sucedida 
retorna o inidice da primeira ocorrencia do elemento na estrutura; a busca 
mal sucedida retorna -1. 
************************************************************************/
int search(Stack *s, int info)
{
	int i;
	for (i=0; i<=(s->top); i++)
	{
		if ((s->data[i]).info == info)
			return i;
	}
	return -1;
}
         

 
/****************************************************************************
Retorna TRUE se a fila s está vazia; retorna FALSE, caso contrário
****************************************************************************/

bool isEmpty (Stack *s)
{
	return ((s->numberOfElements) == 0);

}


