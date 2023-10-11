#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "Invalid argument!\n");
        return 1;
    }

    // parse argument
    int n;
    if (sscanf(argv[1], "%d", &n) != 1){
        fprintf(stderr, "Argument is not a number!\n");
        return 1;
    }

    // validate argument
    if (n < 0){
        fprintf(stderr, "Argument is negative!\n");
    }

    //print all
    for (int i = 0; i < n; i++)
    {
        printf("Hello world!\n");
    }

    return 0;
    
}