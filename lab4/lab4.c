/*
*   @TITLE: Lab 4
*   @Author: Kaleb Himes
*   @Class CSCI 112
*/

#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE 1
#define NO_ROOT -99999.0

double bisect(double x_left, double x_right, double epsilon, double f(double farg));
double g(double x);
double h(double x);

int main(void){
double x_left, x_right, /* left, right endpoints of interval */
        epsilon, root;  /* error tolerance */

        /*Get endpoints and error tolerance from user*/
        printf("\n\nEnter interval left endpoint> ");
        scanf("%lf", &x_left);
        printf("\nEnter interval right endpoint> ");
        scanf("%lf", &x_right);
        printf("\nEnter tolerance> ");
        scanf("%lf", &epsilon);

        /* Use bisect funtion to look for roots of g and h*/

        printf("\n\nf(g) = x^3 - x - 2 \n\n");
        printf("\nIteration    x_left        x_right        x_mid       f(x_mid)\n");
        printf("---------    ------        -------        -----       --------\n");
        root = bisect(x_left, x_right, epsilon, g);
        if(root != NO_ROOT){
            printf("\n\n x = %.7f\n\n", root);
        }
    return (0);
}

/*Implements the bisection method for finding a root of a function f.
* Returns a root if signs of fp(x_left) and fp(x_right) are different.
* Otherwise returns NO_ROOT
*/
double bisect(double x_left,  /*input - endpoints of interval in*/
              double x_right, /*which to look for a root*/
              double epsilon, /*input - error tolerance*/
              double f(double farg))/*input - the funtion*/{

    double x_mid, /* midpoint of interval*/
           f_left, /* f(x_left) */
           f_mid, /* f(x_mid) */
           f_right; /* f(x_right) */

    int root_found; /* flag to indicate whether root is found */
    int iteration = 1;

    /* Computes function values at initial endpoints of interval */
        f_left = f(x_left);
        f_right = f(x_right);

    /* If no change of sign occurs on the interval there is not a
    *  unique root. Exit function and return NO_ROOT
    */
        if(f_left * f_right > 0){
            printf("\nMay be no root in [%.7g, %.7g]", x_left, x_right);
            return NO_ROOT;
        }
    /* Searches as long as interval size is large enough
    *  and no root has been found
    */
        root_found = FALSE; /* no root found yet*/
        while(fabs(x_right - x_left) > epsilon && !root_found){
        /*Computes midpoint and funtion value at midpoint*/
            x_mid = (x_left + x_right) / 2.0;
            f_mid = f(x_mid);
            /* Trace loop execution - print root location or new interval*/
                if(root_found){
                    printf("\nRoot found at x = %.7f, midpoint of [%.7f, %.7f]", x_mid, x_left, x_right);
                }
                else printf("\n%5d        %-10.7g    %-10.7g     %-8.7g    %-7.7g ",iteration, x_left, x_right, x_mid, f(x_mid));
                iteration++;

                if(f_mid == 0.0) {
                    root_found = TRUE; /* Here's the root */
                }
                else if(f_left * f_mid < 0.0){ /* Root in [x_left, x_mid]*/
                    x_right = x_mid;
                }
                else {              /* Root in [x_mid, x_right]*/
                    x_left = x_mid;
                }
        }
        /* If there is a root, it is the midpoint of [x_left, x_right] */
        return ((x_left + x_right) / 2.0);
}
/* Functions for which roots are sought*/
double g(double x){
    return (((x * x) * x) - x - 2);
}
