
#include <stdio.h>
#include "List.h"


int main ()
{
	int number;
	FILE *inFilePointer;
	FILE *outFilePointer

	char *inFileName = "in.txt";	
	char *outFileName = "out.txt";

	inFilePointer = fopen(inFileName, "r");//r- read only, w-write, a-append
	if ( inFilePointer == NULL)
	{
		printf("\nProblemas com a abertura do arquivo de entrada");
	}	

	outFilePointer = fopen(outFileName, "w");
	if ( outFilePointer == NULL)
	{
		printf("\nProblemas com a abertura do arquivo de saida");
	}

	fscanf(inFilePointer, "%d", &number);
	fprintf(outFilePointer, "%d", number);

	fclose(inFilePointer);
	fclose(outFilePointer);

	List *l = create ();
	ListNode*aux;

	add(l, 3);
	add(l, 8);
	add(l, 11);
	add(l, 14);
	add(l, 22);
	add(l, 35);

	addAtHead(l, 1);
	addAtTail(l, 37);

	print(l);
	
	aux = removeFromHead(l);
	if (aux) printf("\nElemento removido %d", aux->info);
	print(l);

	aux = removeFromTail(l);
	if (aux)  printf("\nElemento removido %d", aux->info);
	print(l);
	


	aux = removeElement(l, 21);
	if (aux) printf("\nElemento removido %d", aux->info);
	print(l);

	aux = removeElement(l, 22);
	if (aux) printf("\nElemento removido %d", aux->info);
	print(l);

	aux = removeElement(l, 14);
	if (aux) printf("\nElemento removido %d", aux->info);
	print(l);


	destroy(l);



}



