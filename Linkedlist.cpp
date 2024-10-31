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
void deleteNode(int position,Node*&head,Node*&tail){
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node * curr=head;
        Node * prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(head==NULL){
            tail=NULL;
        }
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void insertAthead(Node* &head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node *&tail,int d){
    Node*temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void insertAtposition(Node *&head,Node *&tail,int position,int d){
    Node*temp=head;
    int cnt=1;
    if(position==1){
        insertAthead(head,d);
        return ;
    }

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }Node * nodeToinsert=new Node(d);
    nodeToinsert->next=temp->next;
    temp->next=nodeToinsert;
    if (nodeToinsert->next == NULL) {
        tail = nodeToinsert;
    }
}

void print(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int main(){
    Node *node1=new Node(10);
    Node*tail=node1;
    Node*head=node1;
    // print(head);
    // insertAtTail(tail,12);
    // print(head);
    // insertAtTail(tail,15);
    // insertAtposition(head,tail,4,22);
    // print(head);
    // insertAthead(head,20);
    // deleteNode(4,head,tail);
    print(head);
    cout<<"head:-"<<head->data<<endl;
    cout<<"tail:-"<<tail->data;    
    return 0;
}