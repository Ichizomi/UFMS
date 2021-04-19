#include <stdio.h>

#include "HashTable.h"

int main ()
{
	// criacao de uma HashTable com 10 elementos
	HashTable *Table = createHT(10);

	addHT (Table, 15);
	addHT (Table, 25);
	addHT (Table, 10);
	addHT (Table, 5);
	addHT (Table, 30);
	printHT(Table);
	removeHT (Table, 1);
	removeHT (Table, 15);
	printHT(Table);

	destroyHT(Table);
	return 0;

}
