#include <stdio.h>

typedef union {
    int   i;   
    float f;
    char* s;
} Data;

int main() {
    Data dat;
    Data *pdat = &dat; 

    pdat->i = 13;
    printf("int: %d\n", pdat->i);

    pdat->f = 8.76f;
    printf("float: %.2f\n", pdat->f);

    pdat->s = "Hello";
    printf("string: %s\n", pdat->s);

    return 0;
}