#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 
#define SIZE 3
#define TOLERANCE 1e-6 
void print_m_int(int M[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++) 
    {
        for (j = 0; j < SIZE; j++) 
        {
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
}
void print_m_float(float M[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++) 
    {
        for (j = 0; j < SIZE; j++) 
        {
            printf("%8.4f", M[i][j]);
        }
        printf("\n");
    }
}
int det3(int A[SIZE][SIZE])
{
    int d;
    d = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
        - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
        + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    return d;
}
int inverse_m(int A_int[SIZE][SIZE], float A_inv[SIZE][SIZE])
{
    float A[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            A[i][j] = (float)A_int[i][j];
        }
    }
    float det_float = 
          A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
        - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
        + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    if (fabs(det_float) < TOLERANCE) 
    {
        printf(" *** 역행렬 계산 불가능 (행렬식 %.4f). ***\n", det_float);
        return 0;
    }
    printf(" *** 역행렬 계산 가능 (행렬식 %.4f). ***\n", det_float);
    float inv_det = 1.0f / det_float;
    A_inv[0][0] = (A[1][1] * A[2][2] - A[1][2] * A[2][1]) * inv_det;
    A_inv[0][1] = (A[0][2] * A[2][1] - A[0][1] * A[2][2]) * inv_det;
    A_inv[0][2] = (A[0][1] * A[1][2] - A[0][2] * A[1][1]) * inv_det;

    A_inv[1][0] = (A[1][2] * A[2][0] - A[1][0] * A[2][2]) * inv_det;
    A_inv[1][1] = (A[0][0] * A[2][2] - A[0][2] * A[2][0]) * inv_det;
    A_inv[1][2] = (A[0][2] * A[1][0] - A[0][0] * A[1][2]) * inv_det;

    A_inv[2][0] = (A[1][0] * A[2][1] - A[1][1] * A[2][0]) * inv_det;
    A_inv[2][1] = (A[0][1] * A[2][0] - A[0][0] * A[2][1]) * inv_det;
    A_inv[2][2] = (A[0][0] * A[1][1] - A[0][1] * A[1][0]) * inv_det;
    return 1;
}
int main(void)
{
    int A[SIZE][SIZE], B[SIZE][SIZE];
    int C[SIZE][SIZE], D[SIZE][SIZE], E[SIZE][SIZE], F[SIZE][SIZE];
    float A_inv[SIZE][SIZE];
    int k;
    int i, j, x;
    srand((unsigned int)time(NULL));
    for (i = 0; i < SIZE; i++) 
    {
        for (j = 0; j < SIZE; j++) 
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
    k = rand() % 5 + 1;
    for (i = 0; i < SIZE; i++) 
    {
        for (j = 0; j < SIZE; j++) 
        {
            C[i][j] = A[i][j] + B[i][j];
            D[i][j] = A[i][j] - B[i][j];
            E[i][j] = k * A[i][j];
        }
    }
    for (i = 0; i < SIZE; i++) 
    {
        for (j = 0; j < SIZE; j++) 
        {
            F[i][j] = 0;
            for (x = 0; x < SIZE; x++) 
            {
                F[i][j] += A[i][x] * B[x][j];
            }
        }
    }
    int det = det3(A);
    printf("======================================\n");
    printf("1. 무작위 생성 행렬 및 스칼라!\n");
    printf("A:\n"); print_m_int(A);
    printf("B:\n"); print_m_int(B);
    printf("스칼라 k: %d\n", k);
    printf("--------------------------------------\n");
    printf("2. 행렬 연산 결과\n");
    printf("A + B:\n"); print_m_int(C);
    printf("A - B:\n"); print_m_int(D);
    printf("k * A (k=%d):\n", k); print_m_int(E);
    printf("A × B:\n"); print_m_int(F);
    printf("--------------------------------------\n");
    printf("3. 역행렬 계산 (A)\n");
    printf("행렬 A의 행렬식 (정수): %d\n", det);
    if (inverse_m(A, A_inv)) 
    {
        printf("역행렬 A^-1 (실수):\n");
        print_m_float(A_inv);
    }
    printf("======================================\n");
    return 0;
}