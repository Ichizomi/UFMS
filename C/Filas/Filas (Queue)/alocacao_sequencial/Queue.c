#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"


/************************************************************************ 
Implementação de uma estrutura de dados do tipo fila circular com alocação 
sequencial na memória . O limite para a quantidade de elementos é 
dada pelo valor de "capacity", fornecido na entrada. Podem ser inseridos 
elementos repetidos. Inserções e remocoões obedecem política FIFO 
(last in first out) e têm complexidade constante. A inserção ocorrre no 
fim da fila e  remoção ocorre no inicio da fila.
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
Criação de uma fila vazia com capacidade limitada por "capacity"
*************************************************************************/

Queue* create (int capacity)
{
	Queue* s = (Queue*) malloc (sizeof(Queue));
	int i;

	/* inicialmente, a fila está vazia */
	s->numberOfElements = 0;
	s->capacity = capacity;
	/* alocação de memória para armazenamento dos dados*/
	s->data = (QueueElement*) malloc (sizeof(QueueElement) * capacity);
	if (s->data == NULL) exception(ALLOC_ERROR);
	/* topo de fila é -1 já que não há elementos na fila*/
	s->begin = -1;
	s->end = -1;
	

	return s;
} 


/************************************************************************ 
Liberação de toda memória previamente alocada parar armazenar elementos 
da fila (destruição de toda a fila)
*************************************************************************/
void destroy (Queue* s)
{
	if (s->data) free (s->data);
	if (s) free (s);

}        


/************************************************************************ 
Inserção de um novo elemento na fila s - o elemento em questão tem apenas 
o dado info (por simplicidade). A inserção ocorre no topo da fila e 
tem complexidade constante - O(1)
*************************************************************************/
void enqueue (Queue *s, int info)
{
	QueueElement el;
	el.info = info;

	if (s->numberOfElements == s->capacity) exception (OVERFLOW_WARNING);

	else
	{	
		(s->end)=((s->end)+1)%(s->capacity);
		s->data [s->end] = el;
		if (s->begin == -1) s->begin = s->end;
		(s->numberOfElements)++;
		
	}
	

}  


/************************************************************************ 
Remoção de um nó da fila s - a remoção sempre ocorre no topo da fila
e tem complexidade constante - O(1). Se não há elementos para remover, 
dequeue retorna NULL
*************************************************************************/

QueueElement* dequeue (Queue *s)
{

	QueueElement *tmp = NULL;
	if ( s->numberOfElements == 0) exception (UNDERFLOW_WARNING);

	else  
	{

		tmp = &(s->data [s->begin]);

		(s->numberOfElements)--;

		if (s->numberOfElements == 0) 
		{
			s->begin = s->end = -1;
		}
		else
		{
			(s->begin) = ((s->begin)+1)%(s->capacity);		
		}
		
		
	}
	return tmp;
}

/**************************************************************************
Imprime os dados armazenados na fila
***************************************************************************/
void print (Queue* s)
{
	int j;
	int tmp;

	printf("\n\nCapacity: %d", s->capacity);		
	printf("\nNumber of elements: %d", s->numberOfElements);	
	printf("\nBegin: %d", s->begin);	
	printf("\nEnd: %d", s->end);	
	printf("\nElements:\n");

	tmp = s->begin;
	for (j=0; j<s->numberOfElements; j++)
	{
		printElement(s->data[tmp]);
		tmp = (tmp+1)%(s->capacity);
		
	}

	
} 

/**************************************************************************
Imprime os dados de um elemento da fila
***************************************************************************/
void printElement (QueueElement el)
{
	printf ("%d ", el.info);
	// implemente aqui a impressão dos demais campos do nó
} 


/************************************************************************ 
Realiza um percurso sobre os elementos da fila.O objetivo é realizar 
a busca de um elemento "info" (inteiro) na estrutura. A busca bem sucedida 
retorna o inidice da primeira ocorrencia do elemento na estrutura; a busca 
mal sucedida retorna -1. 
************************************************************************/
int search(Queue *s, int info)
{
	int j;
	int tmp;

	tmp = s->begin;
	for (j=0; j<s->numberOfElements; j++)
	{
		if ((s->data[tmp]).info == info)
			return tmp;
		tmp = (tmp+1)%(s->capacity);

		
	}
	return -1;

}
         

 
/****************************************************************************
Retorna TRUE se a fila s está vazia; retorna FALSE, caso contrário
****************************************************************************/

bool isEmpty (Queue *s)
{
	return ((s->numberOfElements) == 0);

}


