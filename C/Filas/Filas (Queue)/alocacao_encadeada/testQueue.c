#include "Queue.h"

int main ()
{
	Queue *q = create ();

	enqueue(q, 4);
	enqueue(q, 3);
	enqueue(q, 1);
	print(q);
	if (isEmpty(q)) printf("\n\nfila vazia");
	else printf("\n\nfila não vazia");

	QueueNode *a = dequeue(q);

	a = (QueueNode*) search(q,3);
	if (a == NULL) printf("\n\nnão encontrou o %d", 3);
	else printf("\n\nencontrou o %d", 3);


	a = search(q,5);
	if (a == NULL) printf("\n\nnão encontrou o %d", 5);
	else printf("\n\nencontrou o %d", 5);


	a = search(q,1);
	if (a == NULL) printf("\n\nnão encontrou o %d", 1);
	else printf("\n\nencontrou o %d", 1);


	print(q);

	a = dequeue(q);
	print(q);

	if (isEmpty(q)) printf("\n\nfila vazia");
	else printf("\n\nfila não vazia");


	a = dequeue(q);
	print(q);
	a = dequeue(q);
	print(q);


	if (isEmpty(q)) printf("\n\nfila vazia");
	else printf("\n\nfila não vazia");

	destroy (q);
	return 0;
}



