#include <stdio.h>
#include <stdlib.h>

int number_mcp (const void* a, const void* b);

int main(int argc, char *argv[]){
    FILE* f = fopen("numbers.txt", "r");
    if (!f){
        fprintf(stderr, "File dose not exist!\n");
        return 1;
    }

    // read all numbers
    int numbers[1000];
    int count = 0;
    while (fscanf(f, "%d", numbers + count) == 1)
    {
        count++;
        if(count == sizeof(numbers) / sizeof(*numbers))
            break;
    }

    //close input file
    fclose(f);
    f = NULL;
    
    // sort numbers
    qsort(numbers, count, sizeof(*numbers), number_mcp);

    f = fopen("numbers_sorted.txt", "w");
    if (!f){
        fprintf(stderr, "File dose not exist!\n");
        return 1;
    }

    // write numbers
    for (int i = 0; i < count; i++)
    {
        fprintf(f,"%d\n", numbers);
    }

    fclose(f);
    f = NULL;
    

    return 0;
}

int number_mcp (const void* a, const void* b){
    const int* a_val = (const int*)a;
    const int* b_val = (const int*)b;

    return *a_val - *b_val;
}