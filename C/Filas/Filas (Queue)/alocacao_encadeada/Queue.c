
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


#define ALLOC_ERROR 0
#define OVERFLOW_WARNING 1
#define UNDERFLOW_WARNING 2
#define DELETE_WARNING 3

/************************************************************************ 
Implementação de uma estrutura de dados do tipo Fila com alocação 
dinâmica, simplesmente encadeada. Não há limite de quantidade de elementos 
na estrutura. Podem ser inseridos elementos repetidos. Inserções e 
remocoões obedecem política FIFO (first in first out) e têm complexidade 
constante. A inserção ocorre em um dos extremos (end) e a remoção ocorre 
no outro (begin). 
************************************************************************ /



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
Criação de uma fila vazia
*************************************************************************/

Queue* create ()
{
	Queue* s = (Queue*) malloc (sizeof(Queue));
	s->numberOfNodes = 0;
	s->begin = s->end = NULL;
	return s;
} 
/************************************************************************ 
Liberação de toda memória previamente alocada parar armazenar elementos 
da fila (destruição da fila toda)
*************************************************************************/
void destroy (Queue* q)
{
	QueueNode* tmp = q->begin;
	while (tmp)
	{
		tmp=tmp->next;
		destroyNode(q->begin);
		q->begin = tmp;
	}
	free (q);
}         


/************************************************************************ 
Liberação de toda memória previamente alocada parar armazenar um nó da fila
(destruição do nó)
*************************************************************************/
void destroyNode (QueueNode* n)
{
	free(n);
}


/************************************************************************ 
Inserção de um novo elemento na fila s - o elemento em questão tem apenas 
o dado info (por simplicidade). A inserção tem complexidade constante - O(1)
*************************************************************************/
void enqueue (Queue *s, int info)
{
	/*aloca e preenche o novo nó*/
	QueueNode *newNode = (QueueNode*) malloc (sizeof(QueueNode));
	newNode->info = info;
	newNode->next = NULL;

	/*se a fila é vazia, o novo nó deve ser o primeiro da fila*/	
	if (s->numberOfNodes == 0) 
		s->begin = newNode;
	else /*senão, insere o novo nó no final da fila*/
		(s->end)->next = newNode;

	/*atualiza o ponteiro para o ultimo no na fila*/
	s->end = newNode;

	/*atualiza a quantidade de nós na fila*/
	(s->numberOfNodes)++;

}  

/************************************************************************ 
Remoção de um nó da fila s - a remoção sempre ocorre no início da fila
A remoção tem ccomplexidade constante - O(1).
IMPORTANTE: tomamos a decisão de projeto de não liberar memória ocupada
pelo nó removido, supondo que outro método da aplicação ou da própria fila
utilizará (ou não) os dados presentes no nó e, sem seguida, liberará memória
do nó usando a função destroyNode. 
*************************************************************************/
QueueNode* dequeue (Queue *s)
{


	/*salva em tmp o ponteiro para o primeiro nó da fila*/
	QueueNode* tmp = s->begin;

	/*se a fila está vazia, aviso de underflow*/
	if (s->begin == NULL) exception (UNDERFLOW_WARNING);
	else
	{
		/*senão, avança ponteiro de de inicio de fila para o próximo no 
		  e a atualiza quantidade de nós da fila*/
		s->begin = (s->begin)->next;
		(s->numberOfNodes)--;

		/*se o nó removido era o único, atualiza também o ponteiro para 
		  o último nó da fila*/
		if (s->begin == NULL) s->end = NULL;

	}
	// retorna o ponteiro para o nó removido da fila
	return tmp;
}



/************************************************************************ 
Realiza um percurso sobre os elementos da fila, partindo do início da fila,
até chegar em um ponteiro nulo. O objetivo é realizar a busca de um elemento
"info" (inteiro) na estrutura. A busca bem sucedida retorna o ponteiro 
para o nó que armazena o elemento; busca mal sucedida retorna NULL. Se 
houver mais de uma ocorrência do elemento "info", essa busca retorna o ponteiro
para o nó que armazena a primeira ocorrência do elemento "info" na estrutura.
*************************************************************************/
QueueNode* search(Queue *q, int info)
{
	QueueNode* tmp = q->begin;

	while (tmp!=NULL)
	{
		if (tmp->info == info)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;

}


/**************************************************************************
Imprime os dados armazenados na fila
****************************************************************************/
void print (Queue* s)
{

	QueueNode *tmp = s->begin;
	printf("\n\nNumber of Nodes: %d", s->numberOfNodes);	
	printf("\nElements:\n");


	while (tmp !=NULL)
	{
		printNode (tmp);
		tmp = tmp->next;
	}

	if ( (s->begin) != NULL) printf("\nBegin: %d", (s->begin)->info);
	if ( (s->end) != NULL) printf("\nEnd: %d", (s->end)->info);
	
}            

/**************************************************************************
Imprime os dados de um nó da fila
****************************************************************************/
void printNode (QueueNode *s)
{
	printf ("%d ", s->info);
	// implemente aqui a impressão dos demais campos do nó
}  


/****************************************************************************
Retorna TRUE se a fila s está vazia; retorna FALSE, caso contrário
*****************************************************************************/

bool isEmpty (Queue *s)
{
	return ((s->numberOfNodes) == 0);

}
