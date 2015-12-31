#include <stdio.h>
#include <stdlib.h>

#define MAXWORDSIZE 64

struct tree_node{
  int data;
  struct tree_node *left, *right;
};

void preorder (struct tree_node *);
void postorder (struct tree_node *);
void inorder (struct tree_node *);
void visit (struct tree_node*);
void bst_insert (struct tree_node **, int);
void tree_bfs (struct tree_node *);
void print_tree(struct tree_node *);
struct tree_node* insert(FILE *in);
