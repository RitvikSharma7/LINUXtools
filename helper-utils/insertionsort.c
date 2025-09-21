#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void insertionsort(int array[], int size, void (*swap)(int*, int*));
void swap(int* x, int* y);


int main(void){
    int array[] = {110,25,134,32,7,98};
    int size = sizeof(array)/sizeof(array[0]);
    
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    
    printf("\n");
    puts("After sorting");
    
    insertionsort(array,size,swap);
    
    for (int j = 0; j < size; j++){
        printf("%d ", array[j]);
    }
    
    return EXIT_SUCCESS;
}


void insertionsort(int array[], int size, void (*swap)(int*, int*)){
    for (int i = 1; i < size; i++){
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp){
            array[j + 1] = array[j];
            j--;
        }  
        array[j+1] = temp;
    }
}

void swap (int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
