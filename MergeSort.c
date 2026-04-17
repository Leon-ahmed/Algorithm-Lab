#include<stdio.h>

void merge(int num[], int start, int mid, int end){
    int l_size, r_size, l_index, r_index, main_array_index;

    l_size = mid - start + 1;
    r_size = end - mid;

    int l_array[l_size], r_array[r_size];

    for(int i=0; i<l_size; i++){
        l_array[i] = num[start+i];
    }

    for(int i=0; i<r_size; i++){
        r_array[i] = num[mid+1+i];
    }


    l_index = 0;
    r_index = 0;

    main_array_index = start;

    while(l_index<l_size && r_index<r_size){
        if(l_array[l_index]>r_array[r_index]){
            num[main_array_index] = r_array[r_index];
            r_index += 1;
        }
        else{
            num[main_array_index] = l_array[l_index];
            l_index += 1;
        }

        main_array_index += 1;
    }

    while(l_index<l_size){
        num[main_array_index] = l_array[l_index];
        l_index += 1;
        main_array_index += 1;
    }

    while(r_index<r_size){
        num[main_array_index] = r_array[r_index];
        r_index += 1;
        main_array_index += 1;
    }
}

void merge_sort(int num[], int start, int end){



    if(start>=end){
        return;
    }

    int mid = start + (end-start)/2;

    merge_sort(num, start, mid);

    merge_sort(num, mid+1, end);

    merge(num, start, mid, end);



}

int main(){

    int n = 9;

    int num[] = {3, 5, 7, 4, 8, 1, 9, 2, 6};

    for(int i=0; i<n; i++){
        printf("%d\t", num[i]);
    }

    merge_sort(num, 0, n-1);


    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d\t", num[i]);
    }

    return 0;
}
 