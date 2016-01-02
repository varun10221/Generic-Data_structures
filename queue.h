#include <stdio.h>

/* Implements a queue by means of a linked list, the queue is not thread_safe */

/* Defines a queue as a basic linked list */
struct queue
{
 struct queue_elem *head;   /* Head of the queue */
 int capacity;              /* current capacity of the queue */ 

};

struct queue_elem 
{
  struct queue_elem *next;  /* Next element of the linked list */
  int data;                 /* Data of the element */
};

struct queue * queue_create (void);
void enqueue (struct queue *, int);
int  dequeue (struct queue *);
bool queue_is_empty (struct queue *);






