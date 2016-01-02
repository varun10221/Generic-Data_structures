#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>


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
};


/* A macro that converts the queue_elem QUEUE_ELEM in to a pointer to
   the structure that contains it */

/* Please embed a queue_elem in the structure u want to add in queue. 
   This queue_entry macro retrives the structure based on the queue_element
   by computing the struct address from the address of the queue_element.
   This trick is achieved by figuring out the offset of the queue_elem from
   the struct address, which is obtained by casting the address zero to struct   type and find the absolute address from that. */

#define queue_entry(QUEUE_ELEM, STRUCT, MEMBER)            \
        ((STRUCT *) ((uint8_t *) &(QUEUE_ELEM)->next       \
                     - offsetof (STRUCT, MEMBER.next)))

struct queue * queue_create (void);
void enqueue (struct queue *, struct queue_elem *);
struct queue_elem * dequeue (struct queue *);
bool queue_is_empty (struct queue *);






