#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node*prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL && this->prev!=NULL){
            delete next;
            this->next==NULL;
            this->prev==NULL;
        }else{
            cout<<"The data value deleted is :-"<<value<<endl;
        }        
    }
};
void InsertAthead(Node*&head,int d,Node*&tail){
    if(head==NULL){
        Node* temp= new Node(d);
        head=temp;
        tail=temp;
    }else{
        Node*NodeToInsert= new Node(d);
        head->prev=NodeToInsert;
        NodeToInsert->next=head;
        NodeToInsert->prev=NULL;
        head=NodeToInsert;        
    }
}
void InsertAtTail(Node*&head,int d,Node*&tail){
    if(tail==NULL){
        Node* temp= new Node(d);
        head=temp;
        tail=temp;
    }else{
        Node* NodetoInsert=new Node(d);
        NodetoInsert->prev=tail;
        tail->next=NodetoInsert;
        NodetoInsert->next=NULL;
        tail=NodetoInsert;
    }
}
void InsertAtPosition(Node*&head,int d,Node*&tail,int position){
    if(position==1){
        InsertAthead(head,d,tail);
    }  
    else{
        Node* NodetoInsert=new Node(d);
        Node*temp=head;
        int cnt=1;
        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            InsertAtTail(head,d,tail);
            return ;
        }
        temp->next=NodetoInsert;
        NodetoInsert->prev=temp;
        NodetoInsert->next=temp->next;
        temp->next->prev=NodetoInsert;        
    }

}
void print(Node *&head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void deleteNode(Node*&head,int position){
    if(position==1){
        Node * temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node*curr=head;
        Node*prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        
    }
}


int main() {
    Node* node1=new Node(10);
    Node*tail=node1;
    Node*head=node1;
    InsertAthead(head,15,tail);
    InsertAthead(head,16,tail);
    InsertAtTail(head,9,tail);
    InsertAtPosition(head,15,tail,1);
    deleteNode(head,2);
    print(head);
    cout<<"\nhead:-"<<head->data;
    cout<<"\ntail:-"<<tail->data;
    return 0;
}