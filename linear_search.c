#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int array[], int size, int target) {
    for(int i = 0; i < size; i++)
        if(target == array[i]) return i;
    return -1;
}

void generateRandomArray(int array[], int size){
    for(int i = 0; i < size; i++)
        array[i] = rand() % 100000;
}

int main() {
    int input_size[8] = {10, 50, 100, 1000, 3000, 5000, 7000, 10000};
    int iterations = 1000;
    
    srand(time(NULL));

    printf("Array Size\tTotal Time (seconds)\n");
    printf("--------------------------------------\n");

    for(int i = 0; i < 8; i++) {
        int size = input_size[i];
        int array[size];
        
        double total_time = 0;
        
        for(int iter = 0; iter < iterations; iter++) {
            generateRandomArray(array, size);
            int target = rand() % 10000;
            
            clock_t start = clock();
            linear_search(array, size, target);
            clock_t end = clock();
            
            total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
        }
        
        printf("%d\t\t%lf\n", size, total_time);
    }
    return 0;
}
