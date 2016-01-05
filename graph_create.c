#include <stdio.h>
#include <stdlib.h>


struct Adjacency_node
{
  int dest;
  struct Adjacency_node *next;
  struct queue_elem elem;
  int data;
};

struct Graph
{

  int V;
  struct Adjacency_node *Array;
};

struct Adjacency_node *
Adjacency_node_create (int dest)
{

  struct Adjacency_node *node = (struct Adjacency_node *)
                                  malloc (sizeof (Adjacency_node));

  if (node)
   {
     node->dest = dest;
     node->next = NULL;
   }

  return node;

}

struct Graph*
createGraph (int Vertices)
{

  struct Graph *graph;
  graph = (struct Graph *) malloc (sizeof (struct Graph));
  if (graph == NULL)
    return NULL;

  graph->V = Vertices;
  
  graph->Array = (struct Adjacency_node *) malloc (sizeof (struct Adjacency_node ) * Vertices);
 
   init_Graph (graph); 
   return Graph;

}
  
void
addEdge (struct Graph *graph, int src, int dest)
{

  struct Adjacency_node *node = Adjacency_node_create (dest);
  node->next = graph->array[src]->next;
  graph->array[src]->next = node;

  new_node = Adjacency_node_create (src);

  if (new_node == NULL)
     return;

  new_node->next = graph->array[dest]->next;
  graph->array[dest]->next = new_node; 
  
}

void	
printGraph (struct Graph * graph)
{
 if (graph == NULL)
    return; 
 
 int v;
 for (v = 0; v < graph->V; v++)
   {
     struct Adjacency_node * node = graph->array[v].next;
     printf ("\n Adjacency list of vertex %d\n head",v);
     while (node)
       {
         printf ("-> %d", pCrawl->dest);
         node = node->next;
       }
     printf ("\n");
   }
  
}

int 
main ()
{
  int V = 5;
  struct Graph *graph = create_graph (V);
  addEdge (graph, 0, 1);
  addEdge (graph, 0, 4);
  addEdge (graph, 1, 2);
  addEdge (graph, 1, 3);
  addEdge (graph, 1, 4);
  addEdge (graph, 2, 3);
  addEdge (graph, 3, 4);

  printGraph (graph);
  
  return 0;
}
  



