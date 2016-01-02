#include <stdio.h>
#include <stdbool.h>
#include "btree.h"
/* Implements a queue by means of a linked list, the queue is not thread_safe */

/* Defines a queue as a basic linked list */
struct queue
{
 struct queue* next;   /* Head of the queue */
 struct tree_node* ptr ;   
};

void enqueue (struct tree_node *);
struct tree_node*  dequeue (void);
bool queue_is_empty ();






