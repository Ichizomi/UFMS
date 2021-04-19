#include "MyHeap.h"

int main ()
{
	MyHeap* heap;
	heap = create (100); // cria um heap com 100 elementos

	MyHeapElement el;

	el.priority = 8;
	add_heap(heap,el);
	print (heap);

	el.priority = 9;
	add_heap(heap,el);
	print (heap);

	el.priority = 10;
	add_heap(heap,el);
	print (heap);
	
	el.priority = 6;
	add_heap(heap,el);
	print (heap);	

	el.priority = 5;
	add_heap(heap,el);
	print (heap);	

	el.priority = 50;
	add_heap(heap,el);
	print (heap);

	el.priority = 35;
	add_heap(heap,el);
	print (heap);

	el.priority = 15;
	add_heap(heap,el);
	print (heap);


	el = remove_max(heap);
	printf("\nElemento de maior prioridade removido %d",el.priority);
	print (heap);

	el = remove_max(heap);
	printf("\nElemento de maior prioridade removido %d",el.priority);
	print (heap);

	update (heap, 5, 80);
	print (heap);
	update (heap, 2, 0);
	print (heap);
	

	
	MyHeap* temp_heap;
	temp_heap = create(100);

	el.priority = 13;
	add(temp_heap,el);

	el.priority = 15;
	add(temp_heap,el);

	el.priority = 17;
	add(temp_heap,el);

	el.priority = 27;
	add(temp_heap,el);

	el.priority = 7;
	add(temp_heap,el);

	el.priority = 37;
	add(temp_heap,el);
	print(temp_heap);
	build (temp_heap);
	print(temp_heap);

	destroy(heap);
	destroy(temp_heap);

		return 0;
}
