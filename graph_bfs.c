#include<stdio,h>

void bfs(struct Adjacency_node *node){
    
    if(node == NULL)
        return;

    struct Adjacency_node *temp;
    struct queue *tree_queue;
    struct queue_elem *e;
    Adjacency_node node* ptr;
    Graph *graph;

    tree_queue = queue_create();
    enqueue(tree_queue, &tree_queue);

    while(!queue_is_empty(tree_queue)){
        
        e = dequeue(tree_queue);
        temp = queue_entry(e, struct ,elem);
        printf("\n%d",temp->dest);
        ptr = graph->Array[temp->dest];
        visited[temp->dest]= 1 ;

        while(ptr != NULL){ 
            if(!visited[temp->dest])
                enqueue(tree_queue,ptr->next) 
                ptr = ptr-> next;
        }                                            }
    
    }


}
