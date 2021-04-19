// Implementação de uma tabela de espalhamento (HashTable)
// m=quantidade de elementos da tabela (T[0..m-1])
// n=quantidade de chaves (chaves de 0 a n-1)

#include <stdio.h>
#include "HashTable.h"

HashTable* createHT (int m)
{
	HashTable* Table;
	int i;
	Table = (HashTable*) malloc (sizeof(HashTable));

	if (Table == NULL) exception(ALLOC_ERROR);


	Table->m = m;
	for (i=0; i<m; i++)
		Table->T[i] = NULL;

	return Table;
}
void destroyHT (HashTable* Table)
{
   int i;
   for (i=0; i<Table->m; i++)
   {
        if (Table->T[i] != NULL)
             destroy(Table->T[i]);		
        
   }
   free(Table);
}
 // h(x) retorna a posicao do x na HashTable 
int h (int x,int m)
{
	return x%m;
}
void addHT (HashTable* Table, int x)
{
	List* l;
	int pos = h (x,Table->m);

	if (Table->T[pos] == NULL)
	{	// cria uma nova lista
		l = create();
		Table->T[pos] = l;
	}	
	// adicona o novo elemento
	// na lista que ja existe 
	l = Table->T[pos];
	add (l, x);
}


ListNode* removeHT (HashTable* Table, int x)
{

	List* l;
	ListNode* node;
	int pos = h (x,Table->m);

	if (Table->T[pos] == NULL)
		// o elemento não está na tabela
		return NULL;
		
	
	l = Table->T[pos];
	node = removeElement (l,x);	
	if(isEmpty(l)) Table->T[pos] = NULL;	
	return node;
	

}
void printHT (HashTable* Table)
{
	int m = Table->m;
	int i;

	printf("\n");
	for (i=0; i<m; i++)
	{
   	    if (Table->T[i] == NULL)
		printf ("\nT[%d]: NULL",i);
	    else 
	    {
	 	printf ("\nT[%d]: ",i);
		print(Table->T[i]);
	    }
	}
}


bool searchHT (HashTable* Table, int x)
{
	List* l;
	ListNode* node;
	int pos = h (x,Table->m);

	if (Table->T[pos] == NULL)
		return false;
		
	l = Table->T[pos];
	if (search (l,x) != NULL)	
		return true;
	else return false;
}


