#include <stdio.h>

#define COURSE "C Programming (v1, 2025)"

int main(void) {
    const double PI = 3.141592653589793;
    
    const char title_char = 'A';

    printf("=== Constants & Formats ===\n");

    printf("Course: %s\n", COURSE);

    printf("Title : C \"printf\" demo\n");

    printf("PI default : %.6f\n", PI);

   printf("PI 2 digits : %.2f\n", PI);

    printf("Width demo : [%8d]\n", 123);


    printf("Char sample : %c\n", title_char);

    return 0;
}