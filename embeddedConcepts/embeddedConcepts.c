/*
    @author Chris
    @helping Kaleb
*/

#include <stdio.h>


//determined bug "main" was capitolized "Main" was throwing the error

int main(void){ //oldLine: int Main(void){
    int Var1;

    Var1 = 0b00000111;

//pointer here was returning wrong value but not the initial issue

    printf("%d", Var1); //oldLine: printf("%d", &Var1);

    return(0);
}
