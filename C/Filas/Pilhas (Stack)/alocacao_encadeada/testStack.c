#include "Stack.h"

int main ()
{
	Stack *s = create ();

	push(s, 4);
	push(s, 3);
	push(s, 1);
	print(s);
	if (isEmpty(s)) printf("\n\npilha vazia");
	else printf("\n\npilha não vazia");
	StackNode *a = pop(s);
	print(s);

	a = pop(s);
	print(s);

	if (isEmpty(s)) printf("\n\npilha vazia");
	else printf("\n\npilha não vazia");


	a = pop(s);
	print(s);
	a = pop(s);
	print(s);


	if (isEmpty(s)) printf("\n\npilha vazia");
	else printf("\n\npilha não vazia");

	destroy (s);
	return 0;
}



