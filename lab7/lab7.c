/*
*   @Title: Lab 7
*   @Author: Kaleb Himes
*   @Class: CSCI 112
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRSIZ 30
#define MAXAPP 50

int main(void){
    char applicants[MAXAPP][STRSIZ];
    char *alpha[MAXAPP];
    char full[30];
    int num_app = 6;
    int i, j;
    char one_char;
    char last[30], first[20], age[2], whitespace[1];

    printf("Today we are alphabatizing %d names\n", num_app);

    printf("Those names are as follows:\n\n");

    FILE *inp = fopen("names.dat","r");  //open file for reading
     if(inp == NULL){
       printf("File does not exist");  //prints error message
     }else
//      {
        for(i = 0; i < num_app; i++){
            fscanf(inp, "%s%s%s", &last, &first, &age);
            strcat(last, " ");
            strcat(last, first);
            strcat(last, " ");
            strcat(last, age);
            strcpy(*alpha, last);

            printf("%s\n", *alpha);
            //printf(strcat(last, "\n"));
        }
        fclose(inp);

//    for(i = 0; i < num_app; i++)
//        printf("%-10s", applicants[i]);

    for(i = 0; i < num_app; i++)
        alpha[i] = applicants[i];
    select_sort_str(alpha, num_app);

    printf("\n\n%-30s\n\n", "Alphabetical Order");
    for(i = 0; i < num_app; i++)
        printf("%-30s\n", alpha[i]);

    return(0);
}

int alpha_first(char *list[], int min_sub, int max_sub){
    int first, i;

    first = min_sub;
    for(i = min_sub + 1; i <= max_sub; i++){
        if(strcmp(list[i], list[first]) < 0){
            first = i;
        }
    }
    return(first);
}

void select_sort_str(char *list[], int n){
    int fill, index_of_min;
    char *temp;

    for(fill = 0; fill < n - 1; fill++){
        index_of_min = alpha_first(list, fill, n - 1);

        if(index_of_min != fill){
            temp = list[index_of_min];
            list[index_of_min] = list[fill];
            list[fill] = temp;
        }
    }
}
