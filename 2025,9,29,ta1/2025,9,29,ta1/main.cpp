#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
	int nAge = 0;
	float fHeight = 0.0f;
	double dWeight = 0.0;
	char chTemp = ' ';
	char chString[100] = "";

	printf("Input your alphabet and word (e.g., A Apple):\n");
	int nReScanf = scanf_s(" %c%s", &chTemp, chString, (unsigned int)sizeof(chString));

	printf("--- Output ---\n");
	printf("Read items: %d\n", nReScanf);
	printf("(Alphabet:%c)(Word:%s)\n", chTemp, chString);

	return 0;
}