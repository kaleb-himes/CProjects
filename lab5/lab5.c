/*
*   @Title: Lab 5
*   @Author: Kaleb Himes
*   @Class: CSCI 112
**/

#include <math.h>
#include <stdio.h>
double do_next_op(char c, double a, double total);
int main(){
    double result_so_far, input;
    char op;
    scanf("%c%lf", &op, &input);
    while(op != 'q'){
        result_so_far = do_next_op(op, input, result_so_far);
        printf("result so far is %f\n", result_so_far);
        scanf("%c%lf", &op, & input);
    }
    return 0;
}
double do_next_op(char c, double a, double total){
        if(c == '+' || a < 0){
            total = total + a;
        }
        if(c == '*'){
            total = total * a;
        }
        if(c == '/'){
            total = total / a;
        }
        if(c == '^'){
            total = pow(total, a);
        }
        if(c == 'q'){
        total = total;
        }
    return(total);
}
