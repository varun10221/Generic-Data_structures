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

void tree_read(FILE **fptr){
  char c;
  while ((c = fgetc(*fptr)) != EOF)
        insert(&root,c);
}

void insert(struct tree_node **node, char c){
  if(*node == NULL){
    *node = (struct tree_node*) malloc (sizeof(struct tree_node));
    if(*node != NULL){
      if(c == '@')
        (*node) = NULL ;
      else{
        (*node)->data = c ;
        (*node)->left = NULL;
        (*node)->right= NULL;
      }
    }
  }
  else{


  }

}

void tree_bst (struct tree_node *tree){

 return ;

}

int main (int argc, char* argv[]){
    int i;
    FILE *fin;

    if(argc < 2)
    exit(0);
    else
    fin = fopen(argv[1],"r");

    tree_read(&fin);
    for (i = 0; i <= 10; i++){
           bst_insert (&root, rand());
    }
    print_tree (root);
    printf ("\npreorder :\n");
    preorder (root);
    printf ("\ninorder :\n");
    inorder (root);
    printf ("\npostorder :\n");
    postorder (root);
    return 0;
}
