#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int data;
    struct Node * next;
} Node;

void enQueue(Node ** head, int x){

}

void deQueue(Node ** head,Node ** tail, int x){
    if(*head){
        Node * temp = * head;
        *head = temp->next;
    }
}

int front(Node * head){
    if(head){
        return head->data;
    }
    printf("Empty Queue\n");
    return -1;
}

int main(){
    Node * head = NULL,* tail = NULL;
    int queries,mode,val;
    scanf("%d",&queries);
    while(q--){

    }
    return 0;
}