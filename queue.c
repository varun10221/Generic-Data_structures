#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <stdbool.h>

struct queue* head = NULL;
static int count = 0 ;
void
enqueue (struct tree_node* ptr)
{
 
  if (head == NULL){
    
    head = (struct queue*)malloc (sizeof(struct queue));
    if(head != NULL) {
        head -> next = NULL;
        head -> ptr = ptr ;
        count = 1 ;
    }
    
  }
    
  else{  
        struct queue* temp ;
        temp = head ;
        while (temp ->next != NULL)
        {
          temp = temp->next;
        } 

        struct queue* node = (struct queue*)malloc (sizeof(struct queue));
        if (node != NULL){
            temp->next = node;
            node->ptr = ptr;
            node->next = NULL;
            count++ ;
        }
  }
}
      

struct tree_node* 
dequeue ()
{
  if (head == NULL)
    {
      printf ("\nNo such queue exists\n");
      return NULL;
    }

  if (queue_is_empty ())
    {
      printf ("\nQueue is empty\n");
      return NULL;
    } 
    
  if(head != NULL){
    struct tree_node* data = head->ptr;
    
  struct queue *temp_head = head -> next;
  
  free (head);
  head = temp_head ;
  count-- ;
  
  return data;
    }
}


bool
queue_is_empty ()
{
  if (count == 0)
     return true;

  else return false;

}


  
