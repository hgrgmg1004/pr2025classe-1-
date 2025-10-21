#include <stdio.h>

int main(void)
{
	for (unsigned int i = 2; i <= 25; i++)
	{
		for (unsigned int j = 1; j <= 9; j++)
		{
			printf("%u * %u = %u\n", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}