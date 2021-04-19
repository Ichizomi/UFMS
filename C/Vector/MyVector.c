/*	
DATA: 16 de abril de 2014

ESSE ARQUIVO CONTÉM A IMPLEMENTAÇÃO DE OPERAÇÕES BÁSICAS SOBRE VETORES.

AS OPERAÇÕES EM QUESTÃO SÃO: 

create: Criação da estrutura. A alocação é dinâmica e os elementos do vetor são armazenados
        sequencialmente na memória. 
add: Inserção de um novo elemento na estrutura
deleteFromHead: Remoção do primeiro elemento 
deleteFromTail: Remoção do último elemento 
deleteElement: Remoção de um elemento específico dentro da estrutura (necessita busca)
search: busca
sort: ordenação
destroy: liberação de memória
exception: tratamento de exceções
print: impressão

*/


#include <stdio.h>
#include <stdlib.h>
#include "MyVector.h"


/********************************************************************************************
   void exception(int exceptionError)
   Função de tratamento de exceções.    
   Algumas das exceções são tratadas finalizando o programa (ERROR) e algumas exceções são 
   consideradas menos problemáticas e são tratadas apenas com avisos ao usuário (WARNINGS). 


   exceptionError: inteiro que identifica uma exceção ocorrida durante a execução dos métodos 
                   sobre a estrutura MyVector

*********************************************************************************************/
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



/********************************************************************************************
   MyVectorType* create (int capacity)
   Função de para criação da estrutura de dados MyVector. 

   A função é responsável por alocar memória necessária para armazenamento dos campos do 
   registro. Ao final, a função retorna um ponteiro para a estrutura criada. 


   capacity: quantidade de elementos que devem ser alocados.

*********************************************************************************************/
MyVectorType* create (int capacity)
{

	/* alocação de memória e criação de um vetor do tipo MyVectorType*/
	if (capacity < 0 ) exception (ALLOC_ERROR); 

	MyVectorType* newVector = (MyVectorType*) malloc (sizeof(MyVectorType)); 
	/*validação da alocação de memória */
	if (newVector == NULL) exception (ALLOC_ERROR);


	/* capacidade do vetor */
	newVector->capacity = capacity;   
	/* quantidade de elementos de fato armazenados no vetor - inicialmente zero */
	newVector->numberOfElements = 0;  
	/*alocação de memória para o vetor data - campo responsável por armazenar os elementos*/
	newVector->data = (int*) malloc (capacity*sizeof(int));  
	/*validação da alocação de memória */
	if (newVector->data == NULL) exception (ALLOC_ERROR);
	/* retorno de um ponteiro para a estrutura recem-criada*/
	return newVector;

}


/********************************************************************************************
   void add (MyVectorType* myVector, int element)
   Função de para inserção de um novo elemento. A priori, a inserção será realizada no final
   da estrutura para garantir custo de inserção O(1).
   Custo: O(1)

   myVector: ponteiro para a estrutura estrutura 
   element: inteiro a ser inserido   
*********************************************************************************************/
void add (MyVectorType* myVector, int element)
{

	addTail(myVector,element);
}


/********************************************************************************************
   void addTail (MyVectorType* myVector, int element)
   Função de para inserção de um novo elemento no final da estrutura. 
   Custo: O(1).

   myVector: ponteiro para a estrutura estrutura 
   element: inteiro a ser inserido   
*********************************************************************************************/

void addTail (MyVectorType* myVector, int element)
{

	if (myVector->numberOfElements == myVector->capacity)
		exception (OVERFLOW_WARNING);
	else
	{
		myVector->data[myVector->numberOfElements] = element;
		myVector->numberOfElements++;
	}
	
	
}

/********************************************************************************************
   void addHead (MyVectorType* myVector, int element)
   Função de para inserção de um novo elemento no inicio da estrutura. 
   Custo: O(n) no pior caso, onde n é a quantidade de elementos do vetor.

   myVector: ponteiro para a estrutura estrutura 
   element: inteiro a ser inserido   
*********************************************************************************************/

void addHead (MyVectorType* myVector, int element)
{
	
	int i;
	if (myVector->numberOfElements == myVector->capacity)
		exception (OVERFLOW_WARNING);
	else
	{
		for (i=0; i<=myVector->numberOfElements; i++)
			myVector->data[i+1] = myVector->data[i];
	
		myVector->data[0] = element;
		myVector->numberOfElements++;
	}
		
}



/********************************************************************************************
   void destroy (MyVectorType* myVector)
   Função para liberação de memória alocada para a estrutura.
   
   myVector: ponteiro para a estrutura estrutura 
*********************************************************************************************/

void destroy (MyVectorType *myVector)
{
	
	if (myVector->data != NULL) free(myVector->data);

	if (myVector != NULL) free(myVector);

}


/********************************************************************************************
   int search (MyVectorType *myVector, int element)

   Função de para busca de um determinado elemento (element) na estrutura. Essa função é
   iterativa e percorre o vetor do início para o final. Se "element" pertence a estrutura, 
   a função retornará o índice da PRIMEIRA ocorrência do elemento na estrutura. Caso contrário,
   a função retornará -1. 

   Custo: O(n) no pior caso, onde n é a quantidade de elementos do vetor.

   myVector: ponteiro para a estrutura estrutura 
   element: inteiro a ser inserido   
*********************************************************************************************/

int search (MyVectorType *myVector, int element)
{

	int i;
	for (i=0; i<myVector->numberOfElements; i++)
		if (myVector->data[i] == element) return i;

	return -1; 

/* Outra maneira de realizar a busca - só quenesse caso a busca será da última ocorrência do elemento no vetor
for (i=myVector->numberOfElements-1; i>=0 && myVector->data[i]!=element; i--);

return i;
*/
}


/********************************************************************************************
   int recursiveSearch (MyVectorType *myVector, int element)

   Função recursiva para busca de um determinado elemento (element) na estrutura. 
   Se "element" pertence a estrutura, a função retornará o índice da ÚLTIMA ocorrência do 
   elemento na estrutura. Caso contrário, a função retornará -1. 

   Custo: O(n) no pior caso, onde n é a quantidade de elementos do vetor.

   myVector: ponteiro para a estrutura estrutura 
   element: inteiro a ser inserido   
*********************************************************************************************/

int recursiveSearch (MyVectorType* myVector, int element, int n)
{
	/* condicao de parada quando eu não encontro o elemento no conjunto */
	if (n==0) return -1;

	/* condicao de parada quando encontro o elemento */
	if (myVector->data[n-1] == element)
		return n-1;

	/* chamada recursiva, caso nenhuma das condições de parada sejam satisfeitas */
	return recursiveSearch (myVector, element, n-1);
}

/********************************************************************************************
   int deleteFromTail (MyVectorType* myVector)

   Função para remoção do último elemento da estrutura. A função retorna o elemento removido.
   
   Custo: O(1)

   myVector: ponteiro para a estrutura estrutura 
*********************************************************************************************/

int deleteFromTail (MyVectorType* myVector)
{
	int element = 0;

	if (myVector->numberOfElements == 0) exception (UNDERFLOW_WARNING);

	else 
	{
		element = myVector->data[myVector->numberOfElements-1];

		myVector->numberOfElements --;
	}

 	return element;
}



/********************************************************************************************
   int deleteFromHead (MyVectorType* myVector)

   Função para remoção do primeiro elemento armazenado na estrutura. 
   A função retorna o elemento removido.
   
   Custo: O(n), no pior caso, onde n é a quantidade de elementos armazenados.

   myVector: ponteiro para a estrutura estrutura 
*********************************************************************************************/

int deleteFromHead (MyVectorType* myVector)
{
	int element = 0;
	int i;

	if (myVector->numberOfElements == 0) exception (UNDERFLOW_WARNING);
	else 
	{
		element = myVector->data[0];

		for (i=0; i<myVector->numberOfElements-1; i++)
			myVector->data[i] = myVector->data[i+1];

		myVector->numberOfElements --;
	}
	return element;



}
/********************************************************************************************
   int deleteElement (MyVectorType* myVector, int element)

   Função para remoção de um determinado elemento "element" na estrutura. Necessita realizar 
   uma busca do elemento; caso o elemento não se encontre, gera uma exceção e retorna 0 apenas
   por compatibilidade com o tipo de retorno da estrutura. 

   Custo: O(n), no pior caso, onde n é a quantidade de elementos armazenados.

   myVector: ponteiro para a estrutura estrutura 
   element: elemento a ser removido
*********************************************************************************************/

void deleteElement (MyVectorType* myVector, int element)
{
	int i;
	int index = search(myVector, element);
	if (index != -1) 
	{
	      for (i=index; i<myVector->numberOfElements-1; i++)
		 myVector->data[i]=myVector->data[i+1];


       	      myVector->numberOfElements--;

	}
}



/********************************************************************************************
   void sort (MyVectorType* myVector)

   Função responsável pela ordenação dos elementos da estrutura.

   Custo: dependente do método de ordenação que será usado. bubbleSort: O(n^2)

   myVector: ponteiro para a estrutura estrutura 

*********************************************************************************************/
void sort (MyVectorType* myVector)
{
	/* Prepara os argumentos e faz chamada de bubbleSort */
	bubbleSort(myVector->data, myVector->numberOfElements);
	
}


void bubbleSort(int *v, int n)
{

	/* copie aqui e adapte, se necessário, o código do bubbleSort */



}


/********************************************************************************************
   void print (MyVectorType* myVector)

   Função responsável por imprimir dos dados da estrutura.

   Custo: O(n), onde n é a quantidade de elementos na estrutura. 

   myVector: ponteiro para a estrutura estrutura 

*********************************************************************************************/
void print (MyVectorType* myVector)
{
	
	int i;

	printf("\n-------------------\nPrinting Vector:\n-------------------");
	printf("\nNumberOfElements:%d   Capacity:%d \nElements:\n", myVector->numberOfElements, myVector->capacity);
	for (i=0; i<myVector->numberOfElements; i++)
	{
		printf ("%d ", myVector->data[i]);
	}
	printf("\n-------------------\n");
}






