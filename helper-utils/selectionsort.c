#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void selectionsort(int array[], int size, void (*swap)(int*, int*));
void swap(int* x, int* y);


int main(void){
    int array[] = {110,25,134,32,7,98};
    int size = sizeof(array)/sizeof(array[0]);
    
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    
    printf("\n");
    puts("After sorting");
    
    selectionsort(array,size,swap);
    
    for (int j = 0; j < size; j++){
        printf("%d ", array[j]);
    }
    
    return EXIT_SUCCESS;
}


void selectionsort(int array[], int size, void (*swap)(int*, int*)){
    for (int i = 0; i < size -1; i++){
        int index = i;
        for (int j = i + 1 ; j < size  ; j++){
            if (array[j] < array[index]){
                index = j;
            }
        }
        if (index != i){
            swap(&array[index], &array[i]);
        }
    }
}

void swap (int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
