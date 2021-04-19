#include "Queue.h"

int main ()
{
	Queue *s = create (5);

	enqueue(s, 4);
	print(s);
	enqueue(s, 3);
	print(s);
	enqueue(s, 1);
	print(s);
	enqueue(s, 5);
	print(s);
	enqueue(s, 6);
	print(s);
	enqueue(s, 2);
	print(s);

      
	QueueElement *a = dequeue(s);
	print(s);
	enqueue(s, 7);
	print(s);
	enqueue(s, 8);
	print(s);

	a = dequeue(s);
	 print(s);

	a = dequeue(s);
	 print(s);
	
	a = dequeue(s);
	print(s);

	a = dequeue(s);
	print(s);
	
	a = dequeue(s);
	print(s);

	destroy (s);

        return 0;
}



