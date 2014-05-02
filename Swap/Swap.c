#include <stdio.h>

int main(void){
    int a, b;
    a = 5;
    b = 10;
    //print prior
    printf("Prior to swap:\n");
    printf("a = %d, b = %d\n\n", a, b);
    //swap
    a = (a + b) - (b = a);
    //print after
    printf("After swap:\n");
    printf("a = %d, b = %d\n\n", a, b);
    //pause before termination of program.
    char c;
    printf("Enter any letter and hit return to exit");
    scanf("%s", &c);
    return(0);
}
