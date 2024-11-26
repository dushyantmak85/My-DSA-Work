#include <stdio.h>
struct Node{
    int data;
    struct Node* next;

};

void InsertNode(struct Node** head, int d) {    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next = *head;  // Set new node's next to the current head
    *head = newNode;         // Update head to point to the new node
}
void traverse(struct Node*ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }printf("\n");
}

struct Node* insertionSort(struct Node* head) {
    
}




int main() {
    struct Node* head =(struct Node*)malloc(sizeof(struct Node));
    head->data=10;
    head->next=NULL;
    InsertNode(&head,15);
    InsertNode(&head,13);
    InsertNode(&head,14);
    InsertNode(&head,10);
    traverse(head);
    
    return 0;
}