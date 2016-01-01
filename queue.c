#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


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
enqueue (struct queue *temp, int data)
{
 
  if (temp == NULL)
    printf ("Enqueue_failed");

  struct queue_elem *elem = malloc (sizeof (struct queue_elem));
  if (elem != NULL)
    {
      elem->next = NULL;
      elem->data = data;
    }
     
  else printf ("Enqueue failed ");

  struct queue_elem *node = NULL;

  if (temp->head == NULL)
    {
      temp->head = elem;
      temp->capacity = 1;
      return;
    }
  node = temp->head;

  while (node->next != NULL)
    {
      node = node->next
    } 
  node->next = elem;
  
  temp->capacity = temp->capacity + 1;
  return;
}
      

int 
dequeue (struct queue *temp_queue)
{
  if (temp_queue == NULL)
    {
      printf ("No such queue exists");
      return;
    }
  
  int data;

  if (queue_is_empty (temp_queue))
    {
      printf ("Queue is empty");
    } 
    
  if (temp_queue->head != NULL)
    data = temp_queue->head->data;
    
  struct queue_elem *elem = head;
  temp_queue->head = temp_queue->head->next;
  
  free (head);
  
  return data;

}


bool
queue_is_empty (struct queue *temp)
{
  if (temp != NULL && temp->head != NULL)
     return true;

  else return false;

}


  
