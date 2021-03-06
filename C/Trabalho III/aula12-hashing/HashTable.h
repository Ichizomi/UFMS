// Implementação de uma tabela de espalhamento (HashTable)
// m=quantidade de elementos da tabela (T[0..m-1])
// n=quantidade de chaves (chaves de 0 a n-1)

#include <stdio.h>
#include "List.h"

#define MAX 100

typedef struct {
	int m;
	List* T[MAX];
} HashTable;

// Funções disponíveis para manipulação da HashTable

HashTable* createHT (int m);
void destroyHT (HashTable*);
int h (int x, int m); // h(x,m) retorna a posicao do x na HashTable de tamanho m
void addHT (HashTable*, int );
ListNode* removeHT (HashTable*, int);
void printHT (HashTable*);
bool searchHT (HashTable*, int);




