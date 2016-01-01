#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

struct tree_node *root;

void bst_insert (struct tree_node **tree, int num){
  if (*tree == NULL) {
      *tree = (struct tree_node*) malloc (sizeof(struct tree_node));
      if(*tree != NULL){
        (*tree)->data = num ;
        (*tree)->left = NULL;
        (*tree)->right= NULL;
      }
      return;
  }

  if (num < (*tree)->data)
    bst_insert (&(*tree)->left, num);

  else if (num > (*tree)->data)
    bst_insert (&(*tree)->right, num);
}


void print_tree (struct tree_node *tree)
{
  if (tree->left != NULL)
    print_tree (tree->left);
  printf ("%d\n", tree->data);

  if (tree->right != NULL)
    print_tree (tree->right);
}

void preorder (struct tree_node *tree){
  if (tree != NULL){
      visit (tree);
      preorder (tree->left);
      preorder (tree->right);
   }
}

void postorder (struct tree_node *tree){
  if (tree != NULL){
      visit (tree);
      postorder (tree->left);
      postorder (tree->right);
   }
}


void inorder (struct tree_node *tree){
  if (tree != NULL){
      inorder (tree->left);
      visit (tree);
      inorder (tree->right);
   }
}


void visit (struct tree_node *tree){
  printf ("Data:%d \n", tree->data);
}


void
tree_bst (struct tree_node *tree)
{
  if (tree == NULL)
    return ;
  
  struct tree_node *temp;

  /* Creates a queue */ 
  tree_queue = queue_create ();
 
  /* Adding the tree to the queue */
  enqueue (tree_queue, tree);

  while (! queue_is_empty (tree_queue))
    {
      temp = dequeue (tree_queue);
      visit (temp);
      
      if (temp->left != NULL)
         enqueue (tree_queue, temp->left);
     
      if (temp->right != NULL)
          enqueue (tree_queue, temp->right);
     }
       
  queue_destroy (tree_queue);

}

int main ()
{
  int i;
  for (i = 0; i <= 10; i++)
    {
      bst_insert (&root, rand());
    }
  print_tree (root);
  printf ("preorder :\n");
  preorder (root);
  printf ("inorder :\n");
  inorder (root);
  printf ("postorder :\n");
  postorder (root);
  return 0;
}
