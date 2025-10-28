#include <stdio.h>
int max_val() 
{
    if (7 > 12) 
    {
        return 7; 
    }
    else 
    {
        return 12; 
    }
}
int main(void) 
{
    printf("두 수 중 큰 값은 %d 입니다.\n", max_val());
    return 0;
}