#include <stdio.h>
#include <stdlib.h>
#include "MyVector.h"

int main ()
{

	MyVectorType* myVector;
	
	// Declaracao das variaveis que implementam um vetor de inteiros
	
	
	// Declaracao de variáveis auxiliares do programa
	int position, el=5;

	// Teste de criacao (alocacao) do vetor 
	myVector = create(100);
         print(myVector);

	// Teste de inserções
	add(myVector,5);
	add(myVector,50);
	add(myVector,55);
	add(myVector,30);
	add(myVector,20);
	print(myVector);
	
	// Teste de buscas
	el=5;
	position = search(myVector,el);
	if (position == -1) printf("\nnão achei o %d",el);
	else printf("\nachei o %d na posicao %d",el,position);

	el = 50;
	position = recursiveSearch(myVector,el,myVector->numberOfElements);
	if (position == -1) printf("\nnão achei o %d",el);
	else printf("\nachei o %d na posicao %d",el,position);

	el=10;
	position = search(myVector,el);
	if (position == -1) printf("\nnão achei o %d",el);
	else printf("\nachei o %d na posicao %d",el,position);

	// Teste de remoções

	el = deleteFromTail (myVector);
	printf("\nelemento removido (tail) %d",el);
	
	el = deleteFromHead (myVector);
	printf("\nelemento removido (head) %d",el);

	print(myVector);
	deleteElement (myVector,30);
	deleteElement (myVector,33);
	print(myVector);

	destroy(myVector);
}


