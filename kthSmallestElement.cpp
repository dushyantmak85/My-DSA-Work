#include <iostream>
using namespace std;
#include <vector>

int partition(vector<int> &arr,int start,int end){
    int pivot=arr[end];
    int idx=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j],arr[idx]);
        
        }
    }idx++;
    swap(arr[idx],arr[end]);
    return idx;

}

int smallestElement(vector<int>&arr,int k,int s,int e){
    if(s<e){
        int pivIdx=partition(arr,s,e);       
         smallestElement(arr, k, s, pivIdx - 1);        
        smallestElement(arr, k, pivIdx + 1, e);
    }
    if(k>e){
        cout<<"k is greater than the size of the array"<<endl;
        return -1;
    }
    return arr[k-1];
}

int main() {
    vector<int> arr={10,11,2,3,4,5};
    int n=arr.size();
    cout<<"5th smallest element:- "<<smallestElement(arr,1,0,n-1);
    
    return 0;
}