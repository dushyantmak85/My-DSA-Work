#include <iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = (s + e) / 2;
    int l1 = mid - s + 1;
    int l2 = e - mid;

    int *FirstArray = new int[l1];
    int *SecondArray = new int[l2];

    // Copying elements to FirstArray
    int k = s;
    for (int i = 0; i < l1; i++) {
        FirstArray[i] = arr[k++]; 
    }

    // Copying elements to SecondArray
    k = mid + 1;
    for (int i = 0; i < l2; i++) {
        SecondArray[i] = arr[k++]; 
    }

    // Merging two sorted arrays
    int index1 = 0, index2 = 0;
    k = s;
    while (index1 < l1 && index2 < l2) {
        if (FirstArray[index1] < SecondArray[index2]) {
            arr[k++] = FirstArray[index1++];
        } else {
            arr[k++] = SecondArray[index2++];  
        }
    }

    // Copy remaining elements of FirstArray if any
    while (index1 < l1) {
        arr[k++] = FirstArray[index1++];
    }

    // Copy remaining elements of SecondArray if any
    while (index2 < l2) {
        arr[k++] = SecondArray[index2++];
    }

    delete[] FirstArray;
    delete[] SecondArray;
}

void MergeSort(int *arr, int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;
    MergeSort(arr, s, mid);
    MergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main() {
    int arr[5] = {12, 1, 4, 10, 11};
    MergeSort(arr, 0, 4);  // Pass last index as 4

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
