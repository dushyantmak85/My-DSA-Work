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
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }cout<<"memory is free for node with data "<<value<<endl;
    }
};


/*Node* Reverse(Node*&head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    Node*curr=head;
    Node*prev=NULL;
    Node*forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}*/

// Recursive method 

/*void Reverse(Node *&head,Node*curr,Node*prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    Node * forward=curr->next;
    Reverse(head,forward,curr);
    curr->next=prev;
}*/ 


//Second Recursive method 

Node* Reverse(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newhead=Reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
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

int main() {
    Node *node1=new Node(10);
    Node *head=node1;
    insertAthead(head,20);
    insertAthead(head,30);
    insertAthead(head,80);
    insertAthead(head,50);
    print(head);  
    head=Reverse(head);
    print(head);    
    return 0;
}