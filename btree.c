#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.c"

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
  printf ("%c\n", tree->data);

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
  printf ("Data:%c \n", tree->data);
}

struct tree_node* insert(FILE *fptr){
    char ch ;
    ch = fgetc(fptr);
    if (ch == '@') return NULL;
    struct tree_node* p = (struct tree_node*) malloc(sizeof(struct tree_node));
    p -> data = ch ;
    p -> left = insert(fptr);
    p -> right = insert(fptr);
    return p;
}

void
tree_bfs (struct tree_node *tree)
{
  if (tree == NULL)
    return ;

  struct tree_node *temp;
  struct queue *tree_queue;

  /* Adding the tree to the queue */
  enqueue (tree);

  while (! queue_is_empty ())
    {
      temp = dequeue ();
      visit (temp);

      if (temp->left != NULL)
         enqueue (temp->left);

      if (temp->right != NULL)
          enqueue (temp->right);
     }

}

int main (int argc, char* argv[]){
    int i;
    FILE *fin;

    if(argc < 2){
      printf("\nEnter the file name. Exiting...\n");
      exit(0);
    }
    else{
      fin = fopen(argv[1],"r");
      root = insert(fin);
    }

    /*
    for (i = 0; i <= 10; i++){
           bst_insert (&root, rand());
    }
    */
   // print_tree (root);
    tree_bfs(root);
    printf ("\npreorder :\n");
    preorder (root);
    printf ("\ninorder :\n");
    inorder (root);
    printf ("\npostorder :\n");
    postorder (root);
    return 0;
}
