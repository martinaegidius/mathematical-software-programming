#include <stdio.h>
#include <stdlib.h>

typedef struct snode
{
    double x;           // Payload
    struct snode *next; // Pointer to next snode (NULL if tail)
} snode_t;

typedef struct sll
{
    size_t length;      // Length (number of nodes)
    struct snode *head; // Pointer to head (NULL if empty)
} sllist_t;

int sllist_replace_value(const sllist_t *L, const size_t k, const double val){
    if(!L||k>=L->length){
        return 1;
    }
    snode_t *current = L->head;
    for(size_t i=0;i<k;i++){
        current=current->next;
    }
    current -> x = val;
    return 0;
}

int main(){
//initialization
    struct snode * head = NULL; 
    struct snode * second = NULL;
    struct snode * third = NULL; 
//allocation
    head = (struct snode*)malloc(sizeof(struct snode));
    second = (struct snode*)malloc(sizeof(struct snode));
    third = (struct snode*)malloc(sizeof(struct snode));
//filling
    head->x = 2.0;
    head->next = second;
    second->x = 1337;
    second->next = third;
    third->x = 0;
    third->next = NULL;

//creating list and linkage 
    size_t n = 3;
    struct sll * list;
    list = (struct sll*)malloc(sizeof(struct sll));
    list->length = n;
    list -> head = head;
    printf("list becomes %f,%f,%f\n",head->x,second->x,third->x);
    printf("access of list element 2 %f",list->head->next->x);
    int outers = sllist_replace_value(list,0,14.0);
    printf("\nlist becomes %f,%f,%f\n",head->x,second->x,third->x);
    return 0;    
    
}