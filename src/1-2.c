#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    char name[20];
    double x;
    double y;
    double z;
} Vector;

double dot_product(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector cross_product(Vector a, Vector b) {
    Vector result;
    strncpy(result.name, "cross_result", sizeof(result.name));
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

double vector_length(Vector v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

void print_vector(Vector v) {
    printf("%s: (%.2f, %.2f, %.2f)\n", v.name, v.x, v.y, v.z);
}

int main() {
    Vector a = {"A", 1.0, 2.0, 3.0};
    Vector b = {"B", 4.0, 5.0, 6.0};

    double scalar = dot_product(a, b);
    Vector cross = cross_product(a, b);
    double len_a = vector_length(a);
    double len_b = vector_length(b);
    
    printf("\nVectors:\n");
    print_vector(a);
    print_vector(b);
    
    printf("\nScalar: %.2f\n", scalar);
    printf("\nCross:\n");
    print_vector(cross);
    
    printf("\nModules:\n");
    printf("|%s| = %.2f\n", a.name, len_a);
    printf("|%s| = %.2f\n", b.name, len_b);
    
    return 0;
}