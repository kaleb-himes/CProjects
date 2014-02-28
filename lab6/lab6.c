/*  @Title  : Lab 6
*   @Author : Kaleb J. Himes
*   @Class  : CSCI 112 */

#include <stdio.h>

void multiply_odd_sum(int *m, int *o);

int main(){
    int running = 0;
    while(running < 4){
        int code[12];
        int i;
        int sum_odd = 0;
        int sum_even = 0;
        int m_odd = 0;
        int sum_both = 0;
        int check_digit = 0;
        printf("\n\nenter a bar code to check, separate digits with a space >\n");
        scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &code[0], &code[1], &code[2],
              &code[3], &code[4], &code[5], &code[6], &code[7], &code[8], &code[9],
              &code[10], &code[11]);
        printf("the odd digits being summed are: ");
        for(i = 0; i < 11; i+=2){
            sum_odd += code[i];
            printf("%d ", code[i]);
        }
        printf("\nthe sum of the odd integers is > %d\n", sum_odd);
        multiply_odd_sum(&m_odd, &sum_odd);
        printf("the sum of the odds times 3 is > %d\n", m_odd);
        printf("the even digits being summed are: ");
        for(i = 1; i < 11; i+=2){
            sum_even += code[i];
            printf("%d ", code[i]);
        }
        printf("\nthe sum of the even integers is > %d\n", sum_even);
        sum_both = m_odd + sum_even;
        printf("the sum of both evens and (odds*3) is > %d\n", sum_both);

        printf("the check digit is 10 minus %d\n", sum_both % 10);

        check_digit = 10 - (sum_both % 10);

        if(check_digit == 10)
            check_digit = 10 - 10;

        printf("the check digit is > %d\n", check_digit);

        if(check_digit == code[11]){
            printf("\n**Validated**\n");

        } else printf("\n!!ERROR IN BARCODE!!\n");
        running++;
    }
    return(0);
}
//*m points to the location of the variable m_odd which stands for multiply odd
void multiply_odd_sum(int *m, int *o){
    *m = *o * 3; //updates the value stored in m_odd to be the sum of the odds multiplied by 3
}
