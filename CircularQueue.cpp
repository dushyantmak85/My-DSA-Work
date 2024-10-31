#include <iostream>
using namespace std;


class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    CircularQueue(int n){
        size=n;
        arr=new int[size];
        front=rear=-1;
    }
    void enqueue(int value){
        if (front==0 && rear==size-1|| rear==front-1){
            cout<<"Queue is full"<<endl;
            return ;
        }
        else if (front==-1){
            front=rear=0;
        }else if(rear==size-1 && front!=0){
            rear=0;
        }else{
            rear++;
        }arr[rear]=value;
    }
    int dequeue(){
        if (front==-1){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }else if(front ==size-1){
            front=0;                
        }else{
            front++;
        }return ans;
    }
    void print(){
        for(int i=0;i<size;i++){
            if(arr[i]==-1){
                continue;
            }
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    CircularQueue q1(5);
    q1.enqueue(1);
    q1.enqueue(8);
    q1.enqueue(4);
    q1.enqueue(3);
    q1.enqueue(7);
    q1.dequeue();
    q1.enqueue(12);
    q1.enqueue(13);
    q1.dequeue();
    q1.print();
    return 0;
}