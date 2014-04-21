/* @author Kaleb*/
#include <stdio.h>
#include <stdbool.h>

//a structure for type point
typedef struct{
    char name;
    char next;
    int value;
    char previous;
}point;

//friendly print method that can be called when needed
void feedBack(char c);

//a function for getting the users input
char getInput();

//a method for verifying that the user has chosen correctly
char verify(char c);

int main(void) {
    /*VARIABLES*/
    point a,b,c,z;
    point data;
    char doubleCheck;

    a.name = 'a';
    a.next = 'b';
    a.value = 0;
    a.previous = 'z';

    b.name = 'b';
    b.next = 'c';
    b.value = 1;
    b.previous = 'a';

    c.name = 'c';
    c.next = 'z';
    c.value = 2;
    c.previous = 'b';

    z.name = 'z';
    z.next = 'a';
    z.value = 25;
    z.previous = 'c';

    //get the user input
    data.name = getInput();
    //convert input to lowercase
    data.name = tolower(data.name);
    //double check that user did not accidentally input wrong data
    doubleCheck = verify(data.name);
    //notification of data access
    if(doubleCheck == 'G'){
        printf("the data to be accessed is, %c\n\n", data.name);
        if(data.name == 'a'){
            printf("the value of your data is %d\n\n", a.value);
            printf("The left and right siblings of your data are:\n\n");
            printf("%c <-- %c --> %c\n\n", a.previous, a.name, a.next);
        }
        else if(data.name == 'b'){
            printf("the value of your data is %d\n", b.value);
            printf("The left and right siblings of your data are:\n\n");
            printf("%c <-- %c --> %c\n\n", b.previous, b.name, b.next);
        }
        else if(data.name == 'c'){
            printf("the value of your data is %d\n", c.value);
            printf("The left and right siblings of your data are:\n\n");
            printf("%c <-- %c --> %c\n\n", c.previous, c.name, c.next);
        }
        else if(data.name == 'z'){
            printf("the value of your data is %d\n", z.value);
            printf("The left and right siblings of your data are:\n\n");
            printf("%c <-- %c --> %c\n\n", z.previous, z.name, z.next);
        }
        else{
            printf("You have chosen a data set that contains no data and is not a member of \n");
            printf("this data structure,  please choose carefully next time\n\n");
        }
    }
    return 0;
}

char verify(char c){

    /*VARIABLES*/
    char confirming;

    //Get confirmation
    printf("Enter yes/no or y/n:");

    scanf("%s", &confirming);

    if(confirming ==  'y'||
       confirming ==  'Y'){
        return ('G');
    }else if(confirming ==  'N'||
             confirming == 'n'){
        printf("Woops, my mistake.\n");
        //try again if user mistakenly put in wrong data
        getInput();
    }else{
        printf("-> Wrong format, try again! <-\n");
        //start over
        verify(c);
    }
}

char getInput(){
    /*VARIABLES*/
    char user_request;

    //Ask which data the user would like to access
    printf("Which data would you like to access, please enter a, b, c, or z:");

    //get the user input
    scanf("%s", &user_request);

    //confirm input is of an acceptable type
    bool check = isdigit(user_request);

    if(check == 1){
        printf("-> Wrong format, try again! <-\n");
        //start over
        getInput();
    }

    //return if acceptable
    feedBack(user_request);
    return user_request;
}

void feedBack(char c){
    //print a return line
    printf("\n");
    //Let the user know they are accessing the correct data and verify
    printf("You have indicated that you would like to access \"%c\", is this correct?\n", c);
    //confirm data access
}
