#include <stdio.h>
#include <graph_create.h>

void dfs (int v){

    Adjacency_node node* ptr;
    Graph *graph;

    printf("\n%d",v);
    ptr = graph->Array[v];
    visited[v] = 1;

    while(ptr != NULL){
        v = ptr -> data;
        if(!visited[v])
            dfs(v);
        p = p-> next;
    }
}


