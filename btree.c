#include <stdio.h>
#include <stdlib.h>

struct tree_node
{
  int data;
  struct tree_node *left, *right;
};




struct tree_node *root;

static void preorder (struct tree_node *node);
static void postorder (struct tree_node *node);
static void inorder (struct tree_node *node);
static void visit (struct tree_node *);


void 
insert (struct tree_node **tree, struct tree_node *item)
{
  if (*tree == NULL)
   {
      *tree = item;
       return;
   }
  
  if (item->data < (*tree)->data)
    insert (&(*tree)->left, item);

  else if (item->data > (*tree)->data)
     insert (&(*tree)->right, item);
}


void
print_tree (struct tree_node *tree)
{
  if (tree->left != NULL)
    print_tree (tree->left);
  printf ("%d\n", tree->data);
  
  if (tree->right != NULL)
    print_tree (tree->right);
}

void 
main ()
{

 struct tree_node *current;
 
 int i;

 for (i = 0; i <= 10; i++)
  {
    current = (struct tree_node *) malloc (sizeof (struct tree_node));
    if (current != NULL)
      {
         current->left = current->right = NULL;
         current->data = rand ();
         insert (&root, current);
      }   
  }
 
  print_tree (root);
  printf ("preorder :\n");
  preorder (root);
  printf ("inorder :\n");
  inorder (root);
  printf ("postorder :\n");
  postorder (root);
}

static void
preorder (struct tree_node *tree)
{
  if (tree != NULL)
   {
      visit (tree);
      preorder (tree->left);
      preorder (tree->right);
   }
}

static void
postorder (struct tree_node *tree)
{
  if (tree != NULL)
   {
      
      visit (tree);
      postorder (tree->left);
      postorder (tree->right);
   }
}


static void
inorder (struct tree_node *tree)
{
  if (tree != NULL)
   {
      inorder (tree->left);
      visit (tree);
      inorder (tree->right);
   }
}


static void
visit (struct tree_node *tree)
{
  printf ("Data:%d \n", tree->data);
}     
