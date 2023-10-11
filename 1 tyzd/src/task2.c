#include <stdio.h>

int main(int argc, char *argv[]){
    int a, b;
    printf("Enter two numbers: ");
    //load numbers
    if (scanf("%d %d", &a, &b) != 2)
    {
        fprintf(stderr, "Invalid input!\n");
        return 1;
    }

    // validate argument
    if (b == 0){
        fprintf(stderr, "Can not divide by zero!\n");
        return 1;
    }

    // calculate and print
    printf( "real = %f\n", (float)a / b);
    printf("int = %d\n", a/b);
    printf("mod = %d\n", a%b);

    return 0;
    
}