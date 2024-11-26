#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;

};

void InsertNodeAthead(struct Node** head, int d) {    
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

void InsertAtposition(struct Node **head,int p,int d){
    if(p%7==0){
        struct Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=d;
        temp->next=newNode;
        newNode->next=NULL;
        return ;
    }
    if(p%5==0){
        InsertNodeAthead(head,d);
        return ;
    }
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=d;
    newNode->next=(*head)->next;
    (*head)->next=newNode;
}

int main() {
    struct Node* head =(struct Node*)malloc(sizeof(struct Node));
    head->data=10;
    head->next=NULL;
    InsertNodeAthead(&head,12);
    InsertNodeAthead(&head,13); 
    InsertNodeAthead(&head,14);
    traverse(head);
    int position,data;
    printf("Enter the position:- ");
    scanf("%d",&position);
    printf("Enter the data:- ");
    scanf("%d",&data);

    InsertAtposition(&head,position,data);
    traverse(head);
    
    
    return 0;
}