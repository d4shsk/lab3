#include <stdio.h>
#include <stdlib.h>

typedef union {
    unsigned long    value;
    unsigned char    bytes[sizeof(unsigned long)];
} ULongBytes;

int main() {
    ULongBytes ub;
    unsigned long v;

    printf("Enter unsigned long: ");
    scanf("%lu", &v);
    ub.value = v;

    printf("Value: %lu\n", ub.value);
    printf("Byte-by-byte representation (%zu bytes):", sizeof(unsigned long));
    for (size_t i = 0; i < sizeof(unsigned long); i++) {
        printf(" %02X", ub.bytes[i]);
    }
    printf("\n");

    return 0;
}