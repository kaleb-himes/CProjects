/*
*  @author Kaleb Himes
*  @class CSCI 112
*/

#include <stdio.h>

main(){
    int year, month, day, m, add, final_sum, test_sum;

    printf("First we will test the program using the date, july 4th 2012\n");
    printf("Month: 7\nDay: 4\nYear: 2012\n");

    /*The first test*/
    int test_sum_days = 0;
    for(m = 7; m > 0; m--){
        add = (get_days_month(m, is_leap(2012)));
        test_sum_days+= add;
    }
    test_sum = test_sum_days - (get_days_month(7) - 4);
    printf("This date lands on the %d day of that particular year\n\n", test_sum);

    /*The second test*/
    printf("A second test of the date May 28th 2013:\n");
    printf("Month: 5\nDay:28\nYear: 2013\n");
    test_sum_days = 0;
    for(m = 5; m > 0; m--){
        add = (get_days_month(m, is_leap(2013)));
        test_sum_days+= add;
    }
    test_sum = test_sum_days - (get_days_month(7) - 28);
    printf("This date lands on the %d day of that particular year", test_sum);

    /*All testing concluded, now let's run the program for the user to find out on
      which day he/she was born*/
    printf("\n\n\nNow we will see what day of the year you were born on,\n"
           "please enter the month then day then year in which you were born");
    printf("\n\nMonth:");
    scanf("%d", &month);
    printf("\n\nDay:");
    scanf("%d", &day);
    printf("\n\nYear:");
    scanf("%d", &year);
    int sum_days = 0;

    for(m = month; m > 0; m--){
        add = (get_days_month(m, is_leap(year)));
        sum_days+= add;
    }
    final_sum = sum_days - (get_days_month(month) - day);

    printf("\nYou were born on the %d day of that particular year\n\n\n", final_sum);


return (0);
}
/* This method will take a year and check if it is a leap year returning a one for
true or a zero for false*/
int is_leap(int year){
    if(year%400 == 0){
        return (1);
    }
    else if(year%100 == 0){
        return (0);
    }
    else if(year%4 == 0){
        return (1);
    }
    else return (0);
}
/* This is a method that takes in the month and wheather or not the year is a leap
year. If leap year then feb has 29days if not a leap year than feb has 28 days*/
int get_days_month(int month, int is_leap){
    int days_in_month;
    if(month == 1){
        days_in_month = 31;
    }
    if(month == 2 && is_leap == 0){
        days_in_month = 28;
    }
    if(month == 2 && is_leap == 1){
        days_in_month = 29;
    }
    if(month == 3){
        days_in_month = 31;
    }
    if(month == 4){
        days_in_month = 30;
    }
    if(month == 5){
        days_in_month = 31;
    }
    if(month == 6){
        days_in_month = 30;
    }
    if(month == 7){
        days_in_month = 31;
    }
    if(month == 8){
        days_in_month = 31;
    }
    if(month == 9){
        days_in_month = 30;
    }
    if(month == 10){
        days_in_month = 31;
    }
    if(month == 11){
        days_in_month = 30;
    }
    if(month == 12){
        days_in_month = 31;
    }
    return (days_in_month);
}
