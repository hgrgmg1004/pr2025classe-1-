#include <stdio.h>
#define VEC 3
int main(void)
{
    double A[VEC];
    double B[VEC];
    double dDot = 0.0;
    double C[VEC];
    int i = 0;
    printf("백터 A (3 numbers):\n");
    scanf_s("%lf %lf %lf", &A[0], &A[1], &A[2]);
    printf("백터 B (3 numbers):\n");
    scanf_s("%lf %lf %lf", &B[0], &B[1], &B[2]);
    for (i = 0; i < VEC; i++)
    {
        dDot += A[i] * B[i];
    }
    C[0] = A[1] * B[2] - A[2] * B[1];
    C[1] = A[2] * B[0] - A[0] * B[2];
    C[2] = A[0] * B[1] - A[1] * B[0];
    printf("내적 = %.3lf\n", dDot);
    printf("외적 = (%.3lf, %.3lf, %.3lf)\n", C[0], C[1], C[2]);
    return 0;
}
