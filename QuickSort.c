#include <stdio.h>

int partition(int num[], int low, int high){
    int p, i, count, temp;

    p = num[high];

    for(i=low, count = low-1; i<high; i++){
        if(num[i]<p){
            count++;

            temp = num[i];
            num[i] = num[count];
            num[count] = temp;
        }
    }

    temp = num[high];
    num[high] = num[count+1];
    num[count+1] = temp;

    return count+1;
}

void quick_sort(int num[], int low, int high){

    if(low >= high){
        return;
    }

    int x;
    x = partition(num, low, high);

    quick_sort(num, low, x-1);
    quick_sort(num, x+1, high);

}

int main(){
    int n = 9;
    int num[] = {3, 6, 7, 9, 5, 1, 2, 8, 4};

    printf("Before sorting: \n");
    for(int i=0; i<n; i++){
        printf("%d  ", num[i]);
    }

    quick_sort(num, 0, n-1);

    printf("\nAfter sorting: \n");
    for(int i=0; i<n; i++){
        printf("%d  ", num[i]);
    }


    return 0;
}
 