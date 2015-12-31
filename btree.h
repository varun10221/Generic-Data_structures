#include <stdio.h>
#include <stdlib.h>

struct tree_node{
  int data;
  struct tree_node *left, *right;
};

void preorder (struct tree_node *);
void postorder (struct tree_node *);
void inorder (struct tree_node *);
void visit (struct tree_node*);
void bst_insert (struct tree_node **, int);
void print_tree(struct tree_node *);
void tree_read();
void insert();
