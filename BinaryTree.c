#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    int front;
    int rear;
    int size;
    struct Node * arr;
};

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return q->rear == q->size - 1;
}

// Function to enqueue an element
void Enqueue(struct Queue* q, struct Node* root) {
    if (isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = *root; //

} 
// Function to dequeue an element
struct Node* Dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!!\n");
        return NULL;
    }
    q->front++;
    return &q->arr[q->front];
}



void BinaryTree(struct Node**root){
    int data1;
    printf("%s","Enter the data:- ");
    scanf("%d",&data1);
    if(data1==-1){
        return ;
    }
    *root = (struct Node*)malloc(sizeof(struct Node));
    (*root)->data = data1;
    (*root)->left = NULL;
    (*root)->right = NULL;
    printf("Enter the left data for %d \n",data1);
    BinaryTree(&(*root)->left);
    printf("Enter the right data for %d \n",data1);
    BinaryTree(&(*root)->right);    
}

void LevelTraversing(struct Node* root){
    if(root==NULL){
        return ;
    }
    struct Queue q;
    q.size = 100;
    q.front = q.rear = -1;
    q.arr = (struct Node*)malloc(q.size * sizeof(struct Node*));
    Enqueue(&q,root);
    while(!isEmpty(&q)){
        struct Node* current = Dequeue(&q);
        printf("%d ",current->data);
        if(current->left!=NULL){
            Enqueue(&q,current->left);
        }
        if(current->right!=NULL){
            Enqueue(&q,current->right);
        }
    }
   
}

void InOrderTraversal(struct Node * root){
    if(root==NULL){
        return ;
    }
    InOrderTraversal(root->left);
    printf("%d ",root->data);
    InOrderTraversal(root->right);
}
void PreOrderTraversal(struct Node * root){
    if(root==NULL){
        return ;
    }
    printf("%d ",root->data);
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
void PostOrderTraversal(struct Node * root){
    if(root==NULL){
        return ;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    printf("%d ",root->data);
}

int main() {
    struct Node* root;
    BinaryTree(&root);
    printf("\n");

    printf("InOrder Traversal:- ");
    InOrderTraversal(root);
    printf("\n");

    printf("PostOrder Traversal:- ");
    PostOrderTraversal(root);
    printf("\n");

    printf("PreOrder Traversal:- ");
    PreOrderTraversal(root);
    printf("\n");

    printf("Level Order Traversal:- ");
    LevelTraversing(root);
    printf("\n");

    
    return 0;
}