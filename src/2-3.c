#include <stdio.h>

typedef enum {
    MONDAY,    // 0
    TUESDAY,   // 1
    WEDNESDAY, // 2
    THURSDAY,  // 3
    FRIDAY,    // 4
    SATURDAY,  // 5
    SUNDAY     // 6
} DayOfWeek;

int main() {
    for (DayOfWeek i = MONDAY; i <= SUNDAY; i++) {
        printf("%d\n", i);
    }
    return 0;
}