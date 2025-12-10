#include <stdio.h>
// 1. 구조체(struct): 모든 멤버가 독립적인 공간을 가집니다. (int4+double8+padding≈16)
struct S_Data 
{
    int i;
    double d;
};
// 2. 공용체(union): 가장 큰 멤버의 크기를 공유 합니다. (double 크기=8)
union U_Data 
{
    int i;
    double d;
};
int main(void)
{
    struct S_Data s;
    union U_Data u;
    // 1. 크기 비교 (메모리 할당 방식 차이)
    printf("--- 메모리 크기 비교 ---\n");
    printf("구조체 크기: %zu bytes\n", sizeof(s)); // 모든 멤버 합 + 패딩
    printf("공용체 크기: %zu bytes\n", sizeof(u)); // 가장 큰 멤버의 크기
    printf("\n");
    
    // 2. 공용체의 데이터를 공유및 확인합니다.
    printf("--- 공용체 데이터 공유 확인 ---\n");
    // 2-1. 공용체에 정수(i) 할당 합니다.
    u.i = 123456;
    printf("[할당: u.i = 123456]\n");
    printf("u.i (int)   : %d\n", u.i);
    printf("u.d (double): %lf (손상된 값)\n", u.d); // u.i가 할당되면서 u.d의 메모리가 덮어쓰입니다.
    printf("\n");
    // 2-2. 공용체에 실수(d) 할당
    u.d = 3.3333;
    printf("[할당: u.d = 3.3333]\n");
    printf("u.d (double): %lf\n", u.d);
    printf("u.i (int):%d (손상된 값)\n", u.i); // u.d가 할당되면서 u.i의 메모리가 덮어쓰입니다.
    printf("\n");

    // 3. 구조체의 데이터 독립성을 확인 합니다.
    printf("--- 구조체 데이터 독립성 확인 ---\n");
    s.i = 100;
    s.d = 5;
    // s.i와 s.d는 독립적인 공간에 저장되므로 모두 온전하게 저장됩니다.
    printf("s.i (int):%d\n", s.i);
    printf("s.d (double): %lf\n", s.d);
    return 0;
}