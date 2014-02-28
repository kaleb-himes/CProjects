/*
* @class CSCI 112 - 001
* @author Kaleb Himes
* @Instructor Back Yoo
*/

#include <stdio.h>
#include <string.h>

#define five_ninths 0.555556

main(){
    double Fa, Ce, convert;
    char choice;
    printf("\n\n================================\n");
    printf("     Fahrenheit        Celsius\n");
    printf("--------------------------------\n");
    for(Fa = 0; Fa < 101; Fa+=10){
            Ce = five_ninths * (Fa - 32);
        printf("       %3.0f               %3.1f\n", Fa, Ce);
    }
    printf("--------------------------------\n\n\n");
    printf("Would you like to convert a specific Temperature[Y/N]?");
    scanf("%s", &choice);

        while(choice == 'Y' || choice == 'y'){
            printf("\nOk, enter the temperature in Fahrenheit you would like to convert : ");
            scanf("%lf", &convert);
            printf("\nYou entered %3.1f degrees Fahrenheit, the temperature in Celcius is %3.1f\n\n", convert, five_ninths * (convert - 32));
            printf("Would you like to convert another Temperature to Celcius[Y/N]?");
            scanf("%s", &choice);
        }
        if(choice == 'N' || choice == 'n'){
                printf("\nOk, thankyou for viewing my conversion table, Have a wonderful day!\n\n\n");
        }
        else{
            printf("\n\n\nThat is not a valid choice, please type [Y/N] next time.\n\n\n");
        }

    return (0);
}

