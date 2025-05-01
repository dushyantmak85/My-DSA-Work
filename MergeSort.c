#include <stdio.h>
#include <stdlib.h>

void Merge(int *arr, int s, int e){
    int mid=(s+e)/2;
    int *firstArray=(int*)malloc((mid-s+1)*sizeof(int));
    int *secondArray=(int*)malloc((e-mid)*sizeof(int));
    int k=s;
    for(int i=0;i<mid-s+1;i++){
        firstArray[i]=arr[k++];        
    }
    int j=mid+1;
    for(int i=0;i<e-mid;i++){
        secondArray[i]=arr[j++];
    }
    int index1=0,index2=0,mainArrayIndex=s;
    while(index1<mid-s+1&&index2<e-mid){
        if(firstArray[index1]<secondArray[index2]){
            arr[mainArrayIndex++]=firstArray[index1++];
        }else{
            arr[mainArrayIndex++]=secondArray[index2++];
        }
    }
    while(index1<mid-s+1){
        arr[mainArrayIndex++]=firstArray[index1++];
    }
    while(index2<e-mid){
        arr[mainArrayIndex++]=secondArray[index2++];
    }


}

void MergeSort(int *arr,int s,int e){
    int mid=(s+e)/2;
    if(s>=e){
        return;
    }
    MergeSort(arr,s,mid);
    MergeSort(arr,mid+1,e);
    Merge(arr,s,e);
}

int main() {
    int arr[5]={12,23,14,11,15};
    MergeSort(arr,0,5);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}