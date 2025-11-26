#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define ASCENDING 1
#define DESCENDING 0
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}
void CreateRandomArray(int* arr, int nSize)
{
    GenRandSeed();
    for (int i = 0; i < nSize; i++)
    {
        *(arr + i) = rand() % 201 - 100;
    }
}
void CalcSortArray(int* arr, int nSize, int nOption)
{
    int temp;
    for (int i = 0; i < nSize - 1; i++)
    {
        for (int j = 0; j < nSize - 1 - i; j++)
        {
            int current = *(arr + j);
            int next = *(arr + j + 1);
            if (nOption == ASCENDING && current > next)
            {
                temp = current;
                *(arr + j) = next;
                *(arr + j + 1) = temp;
            }
            else if (nOption == DESCENDING && current < next)
            {
                temp = current;
                *(arr + j) = next;
                *(arr + j + 1) = temp;
            }
        }
    }
}
void PrintArray(int* arr, int nSize)
{
    printf("[");
    for (int i = 0; i < nSize; i++)
    {
        printf("%d", *(arr + i));
        if (i < nSize - 1)
            printf(", ");
    }
    printf("]\n");
}
int main(void)
{
    int arr[SIZE];
    CreateRandomArray(arr, SIZE);
    printf("초기 상태: ");
    PrintArray(arr, SIZE);
    CalcSortArray(arr, SIZE, ASCENDING);
    printf("오름차순: ");
    PrintArray(arr, SIZE);
    CalcSortArray(arr, SIZE, DESCENDING);
    printf("내림차순: ");
    PrintArray(arr, SIZE);

    return 0;
}