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
<<<<<<< HEAD
void tree_bfs (struct tree_node *);
=======
void print_tree(struct tree_node *);
>>>>>>> 0b5780a10e83e08d1e0c4f65eba0327c9cc50322
