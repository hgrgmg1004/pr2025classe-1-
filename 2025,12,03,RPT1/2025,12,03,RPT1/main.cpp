#include <stdio.h>
for (i = 0; i < 3; i++) 
{
	for (j = 0; j < 3; j++) 
	{
		A[i][j] = rand() % 10;
		B[i][j] = rand() % 10;
	}
}
k = rand() % 5 + 1;
for (i = 0; i < 3; i++) 
{
	for (j = 0; j < 3; j++) 
	{
		C[i][j] = A[i][j] + B[i][j];
		D[i][j] = A[i][j] - B[i][j];
		E[i][j] = k * A[i][j];
	}
}
for (i = 0; i < 3; i++) 
{
	for (j = 0; j < 3; j++) 
	{
		F[i][j] = 0;
		for (x = 0; x < 3; x++) 
		{
			F[i][j] += A[i][x] * B[x][j];
		}
	}
}
int det = det3(A);
{
 printf("A:"); 
 print_m(A);
 printf("B:");
 printf("A + B:");
 print_m(C);
 printf("A - B:");
 print_m(D);
 printf("k * A (k=%d):"); 
 print_m(E);
 printf("A × B:");
 print_m(F);
 printf("det(A) = %d", det);
 if (det == 0) 
 {
 printf("역행렬 없음 (det=0)");
 }
 else 
 {
 printf("역행렬 계산 가능 (보고서에 과정 설명)");
 }
 return 0;
}