#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define CLOCK_TYPE 

void bubbleSort(int arr[], int n) {
    clock_t start =clock();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        // If no elements were swapped, the array is already sorted
        if (!swapped) {
            break;
        }
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
    
    bubbleSort(arr,10000);
    printf("%d",arr[0]);
    
        

    return 0;

}

