#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALLOC_ERROR 0
#define OVERFLOW_WARNING 1
#define UNDERFLOW_WARNING 2
#define DELETE_WARNING 3


struct Node{

	//int info; //to string
	char *word;
	char *wordMeaning;
		//não afeta malloc
	struct Node *prev;
	struct Node *next;
	// inclua aqui os demais campos necessários
};

typedef struct Node ListNode;



typedef struct {

	int numberOfNodes;
	ListNode* begin;
	ListNode* end;
} List;


/*************************************************************************
Assinatura das funções que implementam operações elementares sobre listas
*************************************************************************/
List* create (); 
void destroy (List*);   
void destroyNode(ListNode*);    
void add (List*, int);  //change
void addAtHead (List *, int);  //change?
void addAtTail (List *, int); //change? (COMPLETE)
ListNode* removeFromHead (List *);
ListNode* removeFromTail (List *);
ListNode* removeElement (List *, int); //change
bool isEmpty (List *s);
ListNode* search(List*,int); //change
void exception(int);  
void print (List*);            
void printNode (ListNode*);

