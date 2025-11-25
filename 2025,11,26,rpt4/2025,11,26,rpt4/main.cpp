#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LOTTO_SIZE 6
#define MAX_NUMBER 45
#define MIN_NUMBER 1
#define NOT_WIN 0
#define END_COND 999
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
int CheckDuplicate(const int* pArr, int nSize, int nCheckNum)
{
    for (int i = 0; i < nSize; i++)
    {
        if (*(pArr + i) == nCheckNum)
        {
            return 1;
        }
    }
    return 0;
}
void GenLottoNumbers(int* pWinningNum, int* pBonusNum)
{
    int nTempNum;
    int i = 0;
    while (i < LOTTO_SIZE)
    {
        nTempNum = MIN_NUMBER + GenRandNum(MAX_NUMBER - MIN_NUMBER + 1);

        if (!CheckDuplicate(pWinningNum, i, nTempNum))
        {
            *(pWinningNum + i) = nTempNum;
            i++;
        }
    }
    while (1)
    {
        nTempNum = MIN_NUMBER + GenRandNum(MAX_NUMBER - MIN_NUMBER + 1);

        if (!CheckDuplicate(pWinningNum, LOTTO_SIZE, nTempNum))
        {
            *pBonusNum = nTempNum;
            break;
        }
    }
}
void InputUserNumbers(int* pUserNum)
{
    int nInput;
    printf("\n1~45 범위 내에서 로또 번호 6개를 입력하세요 (중복 불가):\n");
    for (int i = 0; i < LOTTO_SIZE; i++)
    {
        while (1)
        {
            printf("%d번째 번호: ", i + 1);
            if (scanf_s("%d", &nInput) != 1)
            {
                printf("오류: 잘못된 입력 형식입니다.\n");
                while (getchar() != '\n');
                continue;
            }
            if (nInput < MIN_NUMBER || nInput > MAX_NUMBER)
            {
                printf("오류: 번호는 1부터 45 사이여야 합니다.\n");
                continue;
            }
            if (CheckDuplicate(pUserNum, i, nInput))
            {
                printf("오류: 이미 입력된 번호입니다.\n");
                continue;
            }
            *(pUserNum + i) = nInput;
            break;
        }
    }
}
int CheckLottoResult(const int* pWinningNum, const int* pUserNum, int nBonus)
{
    int nMatchCount = 0;
    int nBonusMatch = 0;
    for (int i = 0; i < LOTTO_SIZE; i++)
    {
        for (int j = 0; j < LOTTO_SIZE; j++)
        {
            if (*(pWinningNum + i) == *(pUserNum + j))
            {
                nMatchCount++;
                break;
            }
        }
    }
    for (int i = 0; i < LOTTO_SIZE; i++)
    {
        if (*(pUserNum + i) == nBonus)
        {
            nBonusMatch = 1;
            break;
        }
    }
    switch (nMatchCount)
    {
    case 6: return 1;
    case 5:
        if (nBonusMatch == 1) return 2;
        else return 3;
    case 4: return 4;
    case 3: return 5;
    default: return NOT_WIN;
    }
}
int main(void)
{
    GenRandSeed();
    int nWinningNumbers[LOTTO_SIZE];
    int nBonusNumber;
    int nUserNumbers[LOTTO_SIZE];
    int nRank = NOT_WIN;
    printf("=== 로또 645 당첨 프로그램 ===\n");
    GenLottoNumbers(nWinningNumbers, &nBonusNumber);
    InputUserNumbers(nUserNumbers);
    nRank = CheckLottoResult(nWinningNumbers, nUserNumbers, nBonusNumber);
    printf("\n==============================\n");
    printf("당첨 번호: ");
    for (int i = 0; i < LOTTO_SIZE; i++)
    {
        printf("%d ", nWinningNumbers[i]);
    }
    printf("\n보너스 번호: %d\n", nBonusNumber);

    printf("사용자 번호: ");
    for (int i = 0; i < LOTTO_SIZE; i++)
    {
        printf("%d ", nUserNumbers[i]);
    }
    printf("\n--- 결과 ---\n");
    if (nRank > NOT_WIN)
    {
        printf("🎉 축하합니다! %d등에 당첨되었습니다. 🎉\n", nRank);
    }
    else
    {
        printf("아쉽지만, 낙첨되었습니다.\n");
    }
    printf("==============================\n");
    return 0;
}