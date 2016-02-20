/* This program will construct a binary search tree from a sorted array and does a breadth first search (level order traversal) */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gqueue.h"

struct tree_node
{
  int data;
  struct tree_node *left;
  struct tree_node *right;
  struct queue_elem elem;
};   


void
tree_node_init  (struct tree_node *node, int data)
{

  if (node)
   {
     node->data = data;
     node->left = NULL;
     node->right = NULL;
   }
}

static struct tree_node *
Bst_construct (int *sorted_array, int start_index, int end_index)
{

  if (start_index > end_index)
    return NULL;

  int mid;
  mid = (start_index + end_index) / 2;
  
  struct tree_node *root = (struct tree_node *) malloc (sizeof (struct tree_node));
  tree_node_init (root , sorted_array [mid]);
  
  root->left = Bst_construct (sorted_array, start_index, mid - 1);
  root->right = Bst_construct (sorted_array, mid + 1, end_index);

  return root;

}

void
level_order (struct tree_node *root)
{

  if (!root)
    return;

  struct queue *node_queue;
  node_queue = queue_create ();
  
  enqueue (node_queue, &root->elem);
  
  struct tree_node *temp_node = root;

  while (!queue_is_empty (node_queue))
    {
      printf ("\n %d", temp_node->data);
      
      if (temp_node->left)
        enqueue (node_queue, &temp_node->left->elem);
      
      if (temp_node->right)
        enqueue (node_queue, &temp_node->right->elem);

      struct queue_elem *e;
      e = dequeue (node_queue);
      
      temp_node = queue_entry (e, struct tree_node, elem);  
    }
}


int
main (char **argv, int argc)
{
 
  int a[7] = {12, 18 ,24, 30, 36, 42, 48};
  struct tree_node *root;
  root = (struct tree_node *) malloc (sizeof(struct tree_node));
  tree_node_init (root, 0);

  int n;
  n = (sizeof (a)/ sizeof (a[0]));

  root = Bst_construct (&a[0], 0, n);
  level_order (root);
  
  return 0;  

}






