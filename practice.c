#include <stdio.h>

#define NUMELEMENTS(x) (sizeof(x)/sizeof(x[0]))

int main(){
    int numbers[13] = {1, 3, 7, 7, 7, 8, 12, 2, 21, 13, 17, 19, 1};
    //printf("size of array being sent: %d\n", NUMELEMENTS(numbers));
    int z = NUMELEMENTS(numbers);
    printArray(numbers, 0, z);

}

void printArray(int x[], int i, int z){
    //printf("size of incoming array is %d\n", z);
    //printf("currently looking at spot %d\n", i);
    if(i < z){
        printf("\[%d\] ", x[i]);
        printArray(x, i+1, z);
    }
    printf("END\n");
    exit(0);
}
