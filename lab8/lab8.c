/*
*   @Title: Lab 8
*   @Author: Kaleb Himes
*   @Class: CSCI 112
*/

#include <stdio.h>
#include <math.h>

int generate_random(int *c, int *d);
double calc_probability(int c, int d);

int main(void){
    int i, possible_BD;
    int iter = 6;
    int people_in_room = 10;
    int prob = 0;
    printf("===============\n");
    printf("   n      P(n)  \n");
    printf("---------------\n");
    //Generate random numbers
    for(i = 0; i < iter; i++){
        possible_BD = generate_random(&people_in_room, &prob);
        double probability = (double) prob / (double) possible_BD;
        printf("%4d%10.3f  \n", people_in_room, probability);
        people_in_room += 10;
    }
    printf("---------------\n\n");
    return(0);
}
int generate_random(int *c, int *d){
    int i, j, random_BD;
    int numerator = *c * 400;
    for(i = 0; i < numerator; i++){
        random_BD = rand()%365 + 1;
        for(j = 0; j < 100; j++){
            if(random_BD == j) *d += 1;
        }
    }
    return(numerator);
}
