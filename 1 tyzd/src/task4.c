#include <stdio.h>

void my_fun(int* no);

int main(int argc, char *argv[]){
    int a = 5;
    int* a_ptr = &a;
    printf("main: a = %d\n", a);
    printf("main: a_ptr = 0x%p\n", a_ptr);

    my_fun(a_ptr);

    printf("main: a = %d\n", a);
    printf("main: a_ptr = 0x%p\n", a_ptr);

    return 0;
    
}

void my_fun(int* no){
    printf("my_fun: *no = %d\n", *no);
    printf("my_fun: no = 0x%p\n", no);

    *no = 10;

    printf("my_fun: *no = %d\n", *no);
    printf("my_fun: no = 0x%p\n", no);
}