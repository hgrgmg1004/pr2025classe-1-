#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LOTTO 6
#define MAXNUM 45
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
    return;
}
unsigned int GenRandNum(unsigned int nRange)
{
    unsigned int nNum = rand();
    unsigned int nRes = (nNum % nRange) + 1;
    return nRes;
}
int main(void)
{
    GenRandSeed();
    int nCom[LOTTO];
    int nUser[LOTTO];
    int i = 0, j = 0;
    int nSame = 0;
    for (i = 0; i < LOTTO; i++)
    {
        nCom[i] = GenRandNum(MAXNUM);
        for (j = 0; j < i; j++)
        {
            if (nCom[i] == nCom[j])
            {
                i--; 
                break;
            }
        }
    }
    printf("Input your 6 lotto numbers (1~45):\n");
    for (i = 0; i < LOTTO; i++)
    {
        scanf_s("%d", &nUser[i]);
    }
    for (i = 0; i < LOTTO; i++)
    {
        for (j = 0; j < LOTTO; j++)
        {
            if (nUser[i] == nCom[j])
            {
                nSame++;
            }
        }
    }
    printf("Computer numbers: ");
    for (i = 0; i < LOTTO; i++)
    {
        printf("%d ", nCom[i]);
    }
    printf("\nMatched count = %d\n", nSame);
    return 0;
}
