#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define NUM_DATA 100
#define END_COND 999
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
    return;
}
unsigned int GenRandNum(unsigned int nRange)
{
    unsigned int nNum = rand();
    unsigned int nRes = (unsigned int)(nNum % nRange);
    return nRes;
}
int main(void)
{
    GenRandSeed();
    int nArr[NUM_DATA];
    int i = 0;
    for (i = 0; i < NUM_DATA; i++)
    {
        nArr[i] = GenRandNum(1000);
    }
    int nStart = 0;
    int nEnd = 0;
    while (1)
    {
        printf("Input start and end index (0~99)\n");
        printf("To end, input: 999 999\n");
        scanf_s("%d %d", &nStart, &nEnd);

        if (nStart == END_COND || nEnd == END_COND)
        {
            printf("Program end...\n");
            break;
        }
        if (nStart < 0 || nEnd >= NUM_DATA || nStart > nEnd)
        {
            printf("Check your input...\n\n");
            continue;
        }
        double dSum = 0.0;
        int nCnt = nEnd - nStart + 1;
        for (i = nStart; i <= nEnd; i++)
        {
            dSum += nArr[i];
        }
        double dMean = dSum / nCnt;
        double dVar = 0.0;
        for (i = nStart; i <= nEnd; i++)
        {
            double dTemp = nArr[i] - dMean;
            dVar += dTemp * dTemp;
        }
        dVar = dVar / nCnt;
        double dStd = sqrt(dVar);
        printf("Sum = %.3lf\n", dSum);
        printf("Mean = %.3lf\n", dMean);
        printf("Variance = %.3lf\n", dVar);
        printf("Std = %.3lf\n\n", dStd);
    }

    return 0;
}
