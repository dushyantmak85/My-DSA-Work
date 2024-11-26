#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

string check(Node*head){
    if(head==NULL){
        return "True";
    }
    Node*temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return "True";
    }
    return "False";
    
}
void InsertNode(Node*&tail,int element,int d){
    if(tail==NULL){
        Node* newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        Node *curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node* newNode=new Node(d);
        newNode->next=curr->next;
        curr->next=newNode;
    }
}

void print(Node*tail){
    Node*temp=tail;
    if(tail==NULL){
        cout<<"List is Empty";
        return ;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
}


int main() {
    Node *tail=NULL;
    InsertNode(tail,1,12);
    InsertNode(tail,12,6);
    InsertNode(tail,6,7);
    print(tail);
    cout<<endl;
    cout<<(check(tail));
    
    return 0;
}