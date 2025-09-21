#include <stdio.h>
#include <stdbool.h>

void bubblesort(int array[], int size, void (*swap)(int*, int*));
void swap(int* x,int* y);

int main() {
    int array[] = {110,25,134,32,7,98};
    int size = sizeof(array)/sizeof(array[0]);
    
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    
    printf("\n");
    puts("After sorting\n");
    
    bubblesort(array,size,swap);
    
    for (int j = 0; j < size; j++){
        printf("%d ", array[j]);
    }
    
    return 0;
}

void bubblesort(int array[], int size, void (*swap)(int*, int*)){
    for (int i = 0; i < (size -1); i++){
        bool sorted = false;
        for (int j = 0; j < size -i-1; j++){
            if (array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
                sorted = true;
            }
        }
        if (!sorted){
            return;
        }
    }
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
