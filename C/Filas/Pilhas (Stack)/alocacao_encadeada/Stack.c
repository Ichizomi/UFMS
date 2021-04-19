#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"


/************************************************************************ 
Implementação de uma estrutura de dados do tipo Pilha com alocação 
dinâmica, simplesmente encadeada. Não há limite de quantidade de elementos 
na estrutura. Podem ser inseridos elementos repetidos. Inserções e 
remocoões obedecem política LIFO (last in first out) e têm complexidade 
constante. A inserção e a remoção ocorrem no mesmo extremo (topo)
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
Criação de uma pilha vazia
*************************************************************************/

Stack* create ()
{
	Stack* s = (Stack*) malloc (sizeof(Stack));
	s->numberOfNodes = 0;
	s->top = NULL;
	return s;
} 


/************************************************************************ 
Liberação de toda memória previamente alocada parar armazenar elementos 
da pilha (destruição de toda a pilha)
*************************************************************************/
void destroy (Stack* s)
{
	StackNode* tmp = s->top;

	while (tmp)
	{
		tmp=tmp->next;
		destroyNode(s->top);
		s->top = tmp;
	}

	free (s);

}        

/************************************************************************ 
Liberação de toda memória previamente alocada parar armazenar um nó da fila
(destruição do nó)
*************************************************************************/
void destroyNode (StackNode* n)
{
	free(n);
}

/************************************************************************ 
Inserção de um novo elemento na pilha s - o elemento em questão tem apenas 
o dado info (por simplicidade). A inserção ocorre no topo da pilha e 
tem complexidade constante - O(1)
*************************************************************************/
void push (Stack *s, int info)
{

	StackNode *newNode = (StackNode*) malloc (sizeof(StackNode));
	
	newNode->info = info;
	
	newNode->next = s->top;
	
	s->top = newNode;
	(s->numberOfNodes)++;

}  


/************************************************************************ 
Remoção de um nó da pilha s - a remoção sempre ocorre no topo da pilha
e tem complexidade constante - O(1).
IMPORTANTE: tomamos a decisão de projeto de não liberar memória ocupada
pelo nó removido, supondo que outro método da aplicação ou da própria pilha
utilizará (ou não) os dados presentes no nó e, sem seguida, liberará memória
do nó usando a função destroyNode. 
*************************************************************************/

StackNode* pop (Stack *s)
{
	StackNode* tmp = s->top;
	if (s->top == NULL) exception (UNDERFLOW_WARNING);

	else  
	{
		s->top = s->top->next;
		(s->numberOfNodes)--;
	}
	return tmp;
}


/************************************************************************ 
Realiza um percurso sobre os elementos da pilha, partindo do início da pilha,
até chegar em um ponteiro nulo. O objetivo é realizar a busca de um elemento
"info" (inteiro) na estrutura. A busca bem sucedida retorna o ponteiro 
para o nó que armazena o elemento; busca mal sucedida retorna NULL. Se 
houver mais de uma ocorrência do elemento "info", essa busca retorna o ponteiro
para o nó que armazena a primeira ocorrência do elemento "info" na estrutura.
*************************************************************************/
StackNode* search(Stack *s, int info)
{
	StackNode* tmp = s->top;

	while (tmp!=NULL)
	{
		if (tmp->info == info)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;

}


/**************************************************************************
Imprime os dados armazenados na pilha
****************************************************************************/
void print (Stack* s)
{

	StackNode *tmp = s->top;
	printf("\n\nNumber of Nodes: %d", s->numberOfNodes);	
	printf("\nElements:\n");


	while (tmp !=NULL)
	{
		printNode (tmp);
		tmp = tmp->next;
	}
	if ( (s->top) != NULL) printf("\nTop: %d", (s->top)->info);
	
}           

/**************************************************************************
Imprime os dados de um nó da pilha
****************************************************************************/ 
void printNode (StackNode *s)
{
	printf ("%d ", s->info);
	// implemente aqui a impressão dos demais campos do nó
}  
/****************************************************************************
Retorna TRUE se a fila s está vazia; retorna FALSE, caso contrário
*****************************************************************************/

bool isEmpty (Stack *s)
{
	return ((s->numberOfNodes) == 0);

}
