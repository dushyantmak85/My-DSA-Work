#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* Reverse(Node*head,int k){
    Node*next=NULL;
    Node*prev=NULL;
    Node*curr=head;
    int count=0;
    while(curr!=NULL &&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(next!=NULL){
        head->next=Reverse(next,k);
    }
    return prev;
}

void print(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

void insertAthead(Node* &head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}

int main(){
    Node*head=new Node(10);
    insertAthead(head,12);
    insertAthead(head,1);
    insertAthead(head,22);
    insertAthead(head,32);
    print(head);
    head=Reverse(head,2);
    print(head);
    
    return 0;
}