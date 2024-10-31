#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define CLOCK_TYPE 

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void optimizedSelectionSort(int arr[], int n) {
    clock_t start =clock();
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int minIndex = i, maxIndex = j;

        for (int k = i; k <= j; k++) {
            if (arr[k] < arr[minIndex]) {
                minIndex = k;
            }
            if (arr[k] > arr[maxIndex]) {
                maxIndex = k;
            }
        }

        swap(&arr[i], &arr[minIndex]);

        // Adjust the maxIndex if it was swapped with the min element
        if (maxIndex == i) {
            maxIndex = minIndex;
        }

        swap(&arr[j], &arr[maxIndex]);
    }clock_t end =clock();
    printf("Processing time: %.3f nanoseconds\n",(double)(end-start)/(CLOCKS_PER_SEC) );
}


int main(){
    FILE *fp;
   
    
    
    fp=fopen("C:\\Users\\jaish\\OneDrive\\Desktop\\random_numbers1.txt","r");
    int arr[10000],i=0;
    while(i<10000 &&fscanf(fp,"%d",&arr[i])==1){
        i++;
    }
    fclose(fp);
    
    optimizedSelectionSort(arr,10000);
    printf("%d",arr[0]);
    
        

    return 0;

}

