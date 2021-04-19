#include "Stack.h"

int main ()
{
	Stack *s = create (100);

	push(s, 4);
	push(s, 3);
	push(s, 1);
	print(s);

      
	StackElement *a = pop(s);
	if (a) print(s);

	a = pop(s);
	if (a) print(s);

	a = pop(s);
	if (a) print(s);
	
	a = pop(s);
	if (a) print(s);


	if (isEmpty(s)) printf("\n\npilha vazia");
	else printf("\n\npilha não vazia");

	destroy (s);

        return 0;
}



