#include <iostream>
using namespace std;
void BinarySearch(int *arr,int size,int element){
    int start=0;
    int end=size-1;
    int mid=(end)/2;
    while(start<=end){
         if(arr[mid]==element){
            cout<<"Element Found"<<endl;
            return;
        }
        if(element>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }mid=start+(end-start)/2;
    }cout<<"Element Not Found!!";
    
}

int main() {
    int odd[5]={1,3,4,5,6};
    BinarySearch(odd,5,3);
    
    return 0;
}