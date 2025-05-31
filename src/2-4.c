#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
} DataType;

typedef union {
    int    i; 
    float  f;
    char* s;
} DataValue;


typedef struct {
    DataType   type;
    DataValue  data;
} TaggedData;

int main() {
    size_t n;
    printf("Enter amount of elements ");
    if (scanf("%zu", &n) != 1) return 1;

    TaggedData* arr = malloc(n * sizeof * arr);
    if (!arr) {
        perror("malloc");
        return 1;
    }

    for (size_t idx = 0; idx < n; idx++) {
        switch (idx % 3) {
        case 0:
            arr[idx].type = TYPE_INT;
            arr[idx].data.i = (int)(idx * 10);
            break;
        case 1:
            arr[idx].type = TYPE_FLOAT;
            arr[idx].data.f = (float)(idx) / 2.0f;
            break;
        case 2:
            arr[idx].type = TYPE_STRING;
            {
                char buf[32];
                snprintf(buf, sizeof buf, "str_%zu", idx);
                arr[idx].data.s = strdup(buf);
            }
            break;
        }
    }

    for (size_t idx = 0; idx < n; idx++) {
        printf("[%zu] ", idx);
        switch (arr[idx].type) {
        case TYPE_INT:
            printf("INT    = %d\n", arr[idx].data.i);
            break;
        case TYPE_FLOAT:
            printf("FLOAT  = %.2f\n", arr[idx].data.f);
            break;
        case TYPE_STRING:
            printf("STRING = \"%s\"\n", arr[idx].data.s);
            break;
        }
    }

    for (size_t idx = 0; idx < n; idx++) {
        if (arr[idx].type == TYPE_STRING) {
            free(arr[idx].data.s);
        }
    }
    free(arr);

    return 0;
}