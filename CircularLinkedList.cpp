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
     ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }cout<<"memory is free for node with data "<<value<<endl;
    }
};

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

void deleteNode(Node*&tail,int element){
    if(tail==NULL){
        cout<<"List is Empty please check again"<<endl;
        return;
    }
    else{
        Node* prev=tail;
        Node*curr=prev->next;
        while(curr->data!=element){
            prev=curr;
            curr=curr->next;                       
        }
        if(prev==curr){
            tail=NULL;
        }
        else{
            if(tail==curr){
                tail=prev;
            }
            prev->next=curr->next;            
        }
        curr->next=NULL;
        delete curr;
    }
    
}

int main(){
    Node *tail=NULL;
    InsertNode(tail,1,12);
    InsertNode(tail,12,6);
    // print(tail); 
    //  cout<<endl;
    // InsertNode(tail,6,7);
    // print(tail); 
    //  cout<<endl;
    // InsertNode(tail,7,8);
    // print(tail); 
    //  cout<<endl;
    deleteNode(tail,12);
    print(tail);  
    cout<<endl;  
    return 0;
}