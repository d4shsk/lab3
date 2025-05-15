#include <stdio.h>

typedef struct {
    unsigned int day   : 5; 
    unsigned int month : 4; 
    unsigned int year  : 12;
} birth_day;

int main() {
    birth_day bd = { .day = 12, .month = 9, .year = 2006 };
    printf("Date: %u.%u.%u\n", bd.day, bd.month, bd.year);
    return 0;
}