

#define ALLOC_ERROR 0
#define OVERFLOW_WARNING 1   //ANTIGO ADD_ERROR
#define UNDERFLOW_WARNING 2
#define DELETE_WARNING 3


typedef struct 
{
	int *data;
	int numberOfElements;
	int capacity;

}MyVectorType;


void exception (int);
MyVectorType* create (int);
void add (MyVectorType*, int);
void addTail (MyVectorType*, int);
void addHead (MyVectorType*, int);
int  search (MyVectorType*, int);
int recursiveSearch (MyVectorType*, int, int );
void destroy (MyVectorType*);
void print(MyVectorType*);
int  deleteFromTail (MyVectorType*);
int  deleteFromHead (MyVectorType*);
void deleteElement (MyVectorType*, int);
void sort (MyVectorType*);
void bubbleSort (int *, int);




