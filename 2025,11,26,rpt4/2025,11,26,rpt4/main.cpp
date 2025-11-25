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
    int i = 0;
    int j = 0;
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
        (void)scanf_s("%d", &nUser[i]);
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
    printf("\n");
    if (nSame == 6)
        printf("Result: 1st Prize (6 matches)\n");
    else if (nSame == 5)
        printf("Result: 2nd Prize (5 matches)\n");
    else if (nSame == 4)
        printf("Result: 3rd Prize (4 matches)\n");
    else if (nSame == 3)
        printf("Result: 4th Prize (3 matches)\n");
    else if (nSame == 2)
        printf("Result: 5th Prize (2 matches)\n");
    else
        printf("Result: No Prize (%d matches)\n", nSame);
    return 0;
}