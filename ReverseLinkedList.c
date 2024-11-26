#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;

};
void traverse(struct Node*ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }printf("\n");
}
void InsertNode(struct Node** head, int d) {    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next = *head;  // Set new node's next to the current head
    *head = newNode;         // Update head to point to the new node
}

struct Node* Reverse(struct Node* head){
    if(head->next==NULL){
        return head;
    }                                                                                  
    struct Node* newhead=Reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
    
int main(){
    struct Node* head =(struct Node*)malloc(sizeof(struct Node));
    head->data=10;
    head->next=NULL;
    InsertNode(&head,12);
    InsertNode(&head,13);
    InsertNode(&head,14);
    traverse(head);
    head=Reverse(head);
    traverse(head);
    return 0;
}