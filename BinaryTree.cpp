#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node * BinaryTree(Node * root){
    int data;
    cout<<"Enter Data :- ";
    cin>>data;
    root= new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data for left of"<<data<<endl;
    root->left=BinaryTree(root->left);
    cout<<"Enter the data for right of"<<data<<endl;
    root->right=BinaryTree(root->right);
    return root;
}

void LevelOrderTraversal(Node * root){
    queue <Node*> q;
    q.push(root);
    q.push(NULL); 
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

        }

    }
}

void Inorder(Node * root){
    if(root==NULL){
        return ;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(Node * root){
    if(root==NULL){
        return ;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

void Preorder(Node * root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void BuildfromLevelOrderTraversal(Node * &root){
    queue<Node *> q;
    int data;
    cout<<"Enter the data :- ";
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        cout<<"Enter the left data for "<<temp->data<<":-";
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter the right data for "<<temp->data<<":-";
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }       

    }


    

}



int main() {
    Node* root=NULL;
    BinaryTree(root);
    LevelOrderTraversal(root);

    return 0;
}