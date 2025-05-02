#include <iostream>

#include <vector>
using namespace std;

int partition(vector<int> &arr,int start,int end){
    int pivot=arr[end];
    int idx=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }        
    }
    idx++;
    swap(arr[idx],arr[end]);

    return idx;

}

void quickSort(vector<int> &arr,int start,int end){
    if(start<end){
        int Pivindex=partition(arr,start,end);
        quickSort(arr,start,Pivindex-1);
        quickSort(arr,Pivindex+1,end);
    }

}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;   

    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    
    return 0;
}