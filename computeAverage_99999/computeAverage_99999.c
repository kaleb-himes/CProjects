/*
*   @author Kaleb
*   @date 1 May 2014
*/
#include <stdio.h>

int method1();

int method2();

int main(void){
    method1();
    method2();
    return 0;
}
int method1(){
    printf("This is the first method for computing an average of numbers.\n\n");
    //number of arguments
    int count = 0;
    //total sum of those arguments
    int total = 0;
    //user input
    int current;
    for(;;) {
        printf("Please enter a number:");
        scanf("%d", &current);
        if(current == 99999) {
            break;
        } else {
            total = total + current;
            count = count + 1;
        }
    }
    if(count > 0)
        printf("\nThe average is:%d\n", total/count);
    else
        printf("\nNo numbers input. average undefined\n");
    return(0);
}

int method2(){
    printf("This is the second method for computing an average of numbers.\n\n");
    int count = 0;
    int total = 0;
    int current;
    scanf("%d", &current);
    while(current != 99999) {
        total = total + current;
        count = count + 1;
        scanf("%d", &current);
    }
    if(count > 0)
        printf("\nThe average is:%d\n", total/count);
    else
        printf("\nNo numbers input. average undefined\n");
    return(0);
}
