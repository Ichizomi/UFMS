
#include <stdio.h>
#include <stdlib.h>
#include "List.h"


#define ALLOC_ERROR 0
#define OVERFLOW_WARNING 1
#define UNDERFLOW_WARNING 2
#define DELETE_WARNING 3

/************************************************************************ 
Implementação de uma estrutura de dados do tipo lista duplamente encadeada
com alocação dinâmica. Não há limite de quantidade de elementos 
na estrutura. Podem ser inseridos elementos repetidos. 
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
Criação de uma lista vazia
*************************************************************************/

List* create ()
{
	List* s = (List*) malloc (sizeof(List));
	s->numberOfNodes = 0;
	s->begin = s->end = NULL;
	return s;
} 



/************************************************************************ 
Liberação de toda memória previamente alocada parar armazenar elementos 
da lista (destruição da lista toda)
*************************************************************************/
void destroy (List* q)
{
	ListNode* tmp = q->begin;
	while (tmp)
	{
		tmp=tmp->next;
		destroyNode(q->begin);
		q->begin = tmp;
		
	}
	free (q);
}         


/************************************************************************ 
Liberação de toda memória previamente alocada parar armazenar um nó da lista
(destruição do nó)
*************************************************************************/
void destroyNode (ListNode* n)
{
	free(n);
}


/************************************************************************ 
Inserção de um novo elemento na lista s - o elemento em questão tem apenas 
o dado info (por simplicidade). A inserção ocorrera no final da lista 
e tem complexidade constante - O(1)
*************************************************************************/
void addAtTail (List *s, int info)
{
	/*aloca e preenche o novo nó*/
	ListNode *newNode = (ListNode*) malloc (sizeof(ListNode));
	newNode->info = info;
	newNode->next = NULL;

	newNode->prev = s->end;
	/*se a lista é vazia, o novo nó deve ser o primeiro da lista*/	
	if (s->numberOfNodes == 0) 
		s->begin = newNode;
	else /*senão, insere o novo nó no final da lista*/
	{
		(s->end)->next = newNode;
	}

	/*atualiza o ponteiro para o ultimo no na lista*/
	s->end = newNode;

	/*atualiza a quantidade de nós na lista*/
	(s->numberOfNodes)++;

}  

/************************************************************************ 
Inserção de um novo elemento na lista s - o elemento em questão tem apenas 
o dado info (por simplicidade). A inserção ocorrera no final da lista 
e tem complexidade constante - O(1)
*************************************************************************/
void add (List *s, int info)
{
	addAtTail (s,info);
}


/************************************************************************ 
Inserção de um novo elemento na lista s - o elemento em questão tem apenas 
o dado info (por simplicidade). A inserção ocorrera no inicio da lista 
e tem complexidade constante - O(1)
*************************************************************************/
void addAtHead (List *s, int info)
{
	/*aloca e preenche o novo nó*/
	ListNode *newNode = (ListNode*) malloc (sizeof(ListNode));
	newNode->info = info;
	newNode->prev = NULL;

	/*se a lista é vazia, o novo nó deve ser o primeiro da lista*/	

	newNode->next = s->begin;
	if (s->numberOfNodes == 0) 
		s->end = newNode;
	else 
		(s->begin)->prev = newNode;

	s->begin = newNode;

	/*atualiza a quantidade de nós na lista*/
	(s->numberOfNodes)++;

}  

/************************************************************************ 
Remoção do primeiro elemento da lista s.
Complexidade O(1).
IMPORTANTE: tomamos a decisão de projeto de não liberar memória ocupada
pelo nó removido, supondo que outro método da aplicação ou da própria lista
utilizará (ou não) os dados presentes no nó e, sem seguida, liberará memória
do nó usando a função destroyNode. 
*************************************************************************/
ListNode* removeFromHead (List *s)
{

	// ponteiro auxiliar para o priemeiro nó da lista
	// esse será o nó "retirado" da lista
	
	ListNode* aux = s->begin;
	
	// se a lista está fazia deve retornar NULL
	if (aux == NULL) return NULL;
	
	// em caso contrário, atualiza numberOfNodes e avança o ponteiro de inicio de lista
	s->numberOfNodes = (s->numberOfNodes)-1;
	
	s->begin = aux->next;  // avanca o ponteiro begin
	
	// se o primeiro nó da lista é também o último nó da lista
	if (s->begin == NULL) 
		s->end = NULL;
	else     
	{
		(s->begin)->prev = NULL;

	}


	aux->prev = aux->next = NULL;
	return aux;
	

}

/************************************************************************ 
Remoção do último elemento da lista s.
Complexidade O(1).
IMPORTANTE: tomamos a decisão de projeto de não liberar memória ocupada
pelo nó removido, supondo que outro método da aplicação ou da própria lista
utilizará (ou não) os dados presentes no nó e, sem seguida, liberará memória
do nó usando a função destroyNode. 
*************************************************************************/
ListNode* removeFromTail (List *s)
{
	// ponteiro auxiliar para o priemeiro nó da lista
	// esse será o nó "retirado" da lista
	
	ListNode* aux = s->end;
	
	// se a lista está fazia deve retornar NULL
	if (aux == NULL) return NULL;
	
	// em caso contrário, atualiza numberOfNodes e atualiza ponteiro para final de lista
	s->numberOfNodes = (s->numberOfNodes)-1;
	
	s->end = aux->prev;
	
	// se o primeiro nó da lista é também o último nó da lista
	if (s->end == NULL) 
		s->begin = NULL;
	else     
		(s->end)->next = NULL;

	return aux;

}

/************************************************************************ 
Remoção de um elemento específico da lista. Essa função recebe um valor
inteiro e realiza a busca desse valor na lista. Se o elemento for encontrado,
deve ser removido da lista e deve ser retornado um ponteiro para o nó removido.
Senão, a função deve retornar NULL.
Complexidade O(n), onde n é a quantidade de elementos da lista.

IMPORTANTE: tomamos a decisão de projeto de não liberar memória ocupada
pelo nó removido, supondo que outro método da aplicação ou da própria lista
utilizará (ou não) os dados presentes no nó e, sem seguida, liberará memória
do nó usando a função destroyNode. 
*************************************************************************/
ListNode* removeElement (List *s,int el)
{
 	ListNode *aux = search (s,el);
	
	if (aux == NULL) return NULL; // o elemento não foi encontrado na lista - retorne NULL
	
	s->numberOfNodes = (s->numberOfNodes)-1;
	// caso contrário, aux aponta para o nó que contem o elemento a ser removido
	if (aux->prev == NULL) // aux é o primeiro da lista 
		s->begin = aux->next;
	else 
		(aux->prev)->next = aux->next;


	if (aux->next == NULL) // aux é o ultimo da lista 
		s->end = aux->prev;

	else
		(aux->next)->prev = aux->prev;
	
	aux->prev = aux->next = NULL;
	return aux;

}


/************************************************************************ 
Realiza um percurso sobre os elementos da lista, partindo do início da lista,
até chegar em um ponteiro nulo. O objetivo é realizar a busca de um elemento
"info" (inteiro) na estrutura. A busca bem sucedida retorna o ponteiro 
para o nó que armazena o elemento; busca mal sucedida retorna NULL. Se 
houver mais de uma ocorrência do elemento "info", essa busca retorna o ponteiro
para o nó que armazena a primeira ocorrência do elemento "info" na estrutura.

Complexidade: O(n)
*************************************************************************/
ListNode* search(List *q, int info)
{
	ListNode* tmp = q->begin;

	while (tmp!=NULL)
	{
		if (tmp->info == info)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;

}


/**************************************************************************
Imprime os dados armazenados na lista
****************************************************************************/
void print (List* s)
{

	ListNode *tmp = s->begin;
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
Imprime os dados de um nó da lista
****************************************************************************/
void printNode (ListNode *s)
{
	printf ("\n%d ", s->info);
	/*printf ("aponta para next=");
	if (s->next != NULL)  printf("%d", (s->next)->info); 
	else { printf("null"); }
	printf (" e aponta para prev=");
	if (s->prev != NULL)  printf("%d", (s->prev)->info); 
	else { printf("null"); }
	*/




	// implemente aqui a impressão dos demais campos do nó
}  


/****************************************************************************
Retorna TRUE se a lista s está vazia; retorna FALSE, caso contrário
*****************************************************************************/

bool isEmpty (List *s)
{
	return ((s->numberOfNodes) == 0);

}
