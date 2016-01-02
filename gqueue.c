#include <stdio.h>
#include <stdlib.h>
#include "gqueue.h"
#include <stdbool.h>


struct queue *
queue_create (void)
{

  struct queue *temp_queue = malloc (sizeof (struct queue));
  if (temp_queue == NULL)
    return NULL;
  
  temp_queue->head = NULL;
  temp_queue->capacity = 0;
  
  return temp_queue;   
}


void
enqueue (struct queue *temp, struct queue_elem *elem)
{
 
  if (elem == NULL)
    printf ("Enqueue_failed");

  if (elem != NULL && temp->head == NULL)
    {
      temp->head = elem;
      temp->capacity = 1;
      return;
    }
     
  struct queue_elem *node;
 
  node = temp->head;
 
  while (node->next != NULL)
    {
      node = node->next;
    } 
  node->next = elem;
  
  temp->capacity = temp->capacity + 1;
  return;
}
      

struct queue_elem * 
dequeue (struct queue *temp_queue)
{
  if (temp_queue == NULL)
    {
      printf ("No such queue exists");
      return NULL;
    }
  
  struct queue_elem *temp = NULL;

  if (queue_is_empty (temp_queue))
    {
      printf ("Queue is empty");
      return NULL;
    } 
    
  if (temp_queue->head != NULL)
    temp = temp_queue->head->next;
    
  struct queue_elem *elem = NULL;
  elem = temp_queue->head;
  temp_queue->head = temp;
  
  
  return elem;

}


bool
queue_is_empty (struct queue *temp)
{
  if (temp != NULL && temp->head != NULL)
     return false;

  else return true;

}


  
