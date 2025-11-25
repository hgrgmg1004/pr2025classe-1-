#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define ARRAY_SIZE 100
#define SUBSET_SIZE 10
#define MIN_RANGE 1
#define MAX_RANGE 100
#define END_COND 1112
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
    return;
}
unsigned int GenRandNum(unsigned int nRange)
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}
void InitArrayWithRandom(int arr[], int nSize, int nMin, int nMax)
{
    int nRange = nMax - nMin + 1;
    for (int i = 0; i < nSize; i++)
    {
        arr[i] = nMin + GenRandNum(nRange);
    }
}
void CalcStatistics(const int* pStartPtr, int nCount)
{
    double dSum = 0.0;
    double dMean = 0.0;
    double dVariance = 0.0;
    double dStdDev = 0.0;
    for (int i = 0; i < nCount; i++)
    {
        dSum += *(pStartPtr + i);
    }
    dMean = dSum / nCount;
    double dSquaredDiffSum = 0.0;
    for (int i = 0; i < nCount; i++)
    {
        double dDiff = *(pStartPtr + i) - dMean;
        dSquaredDiffSum += dDiff * dDiff;
    }
    dVariance = dSquaredDiffSum / nCount;
    dStdDev = sqrt(dVariance);
    printf("\n=== 통계 결과 ===\n");
    printf("요소 개수: %d\n", nCount);
    printf("총합: %.0f\n", dSum);
    printf("평균: %.4f\n", dMean);
    printf("분산: %.4f\n", dVariance);
    printf("표준편차: %.4f\n", dStdDev);
    printf("=================\n");
}
int main(void)
{
    GenRandSeed();
    int nNumbers[ARRAY_SIZE];
    int nStartIdx = 0;
    InitArrayWithRandom(nNumbers, ARRAY_SIZE, MIN_RANGE, MAX_RANGE);
    printf("생성된 100개의 정수 (일부):\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", nNumbers[i]);
    }
    printf("... [생략]\n");
    while (1)
    {
        printf("\n통계를 계산할 시작 인덱스를 입력하세요 (0 ~ %d, 종료: %d): ",
            ARRAY_SIZE - SUBSET_SIZE, END_COND);
        if (scanf_s("%d", &nStartIdx) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        if (nStartIdx == END_COND)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        if (nStartIdx < 0 || nStartIdx > ARRAY_SIZE - SUBSET_SIZE)
        {
            printf("오류: 인덱스 범위가 올바르지 않습니다. 다시 입력해주세요.\n");
            continue;
        }
        printf("선택된 10개의 정수 (인덱스 %d부터):\n", nStartIdx);
        for (int i = 0; i < SUBSET_SIZE; i++)
        {
            printf("%d ", nNumbers[nStartIdx + i]);
        }
        printf("\n");
        CalcStatistics(&nNumbers[nStartIdx], SUBSET_SIZE);
    }
    return 0;
}