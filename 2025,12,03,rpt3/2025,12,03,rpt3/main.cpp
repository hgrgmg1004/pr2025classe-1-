#include <stdio.h>
int main(void)
{
	int A[5];
	int B[3][4];
	int C[2][3][4];
	A[2] = 10;
	*(A + 2) = 9;
	B[1][2] = 7;
	*(*(B + 1) + 2) = 7;
	C[1][1][2] = 9;
	*(*(*(C + 1) + 1) + 2) = 5;
	printf("확인용 출력: %d %d %d", A[2], B[1][2], C[1][1][2]);
	return 0;
}