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
    int even[6]={2,3,6,8,9,10};
    int odd[5]={1,5,8,9,12};
    BinarySearch(even,6,10);
    BinarySearch(odd,5,13);
    
    
    return 0;
}