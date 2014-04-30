/*
*   @author Kaleb
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//calculate the nth fibonacci number
int runFib();

//a function for getting the users input
int getInput();

//looping method
void again();

void main(void)
{

    // Declaration of Variables
    int userDefined;

    //Which Fib to calculate
    userDefined = getInput();
    //calculate the nth fib
    runFib(userDefined);
}

int runFib(int a){
    //Variable Declaration
    int b,c;
    unsigned long long f;
    b = 0;
    c = 0;
    f = 0;
    //base case 1
    if(a < 0){
        printf("n cannot be less than zero.");
        getInput();
    }
    //base case 2
    if(a == 0){
        printf("Result: %d\n\n", 0);
        getInput();
    }
    //base case 3
    if(a == 1 | a == 2){
        printf("Result: %d\n\n", 1);
        again();
    }
    b = 1, c = 1;
    while(a > 2){
        f = b + c;
        b = c;
        c = f;
        a--;
    }
    printf("Result: %lld\n\n", f);
    //loop
    again();
}

int getInput(){
    /*VARIABLES*/
    int user_request;
    user_request = 0;

    //Ask which fib to calculate
    printf("\nPlease enter which fibonacci number you would like to calculate.\n");
    printf("NOTE: Decimals or floating point numbers will be rejected.\n");

    //get the user input
    scanf("%d", &user_request);
    //return if acceptable
    return user_request;
}

void again(){
    //Variables Declaration
    char decision;

    printf("Would you like to try another?(y or n): ");
    scanf("%s", &decision);

    if(decision == 'y' || decision == 'Y'){
        main();
    }
    else{
        exit(0);
    }
}
