#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// 이 함수는 표준 입력 버퍼에 남아있는 모든 문자(개행 문자 포함)를 
// EOF(파일 끝)를 만나거나 개행 문자('\n')를 만날 때까지 읽어서 비우는 역할을 합니다.
// 주로 이전 입력 함수가 입력 버퍼에 남긴 개행 문자를 제거하여
// 이후의 입력 함수(특히 fgets)가 예상대로 작동하도록 보장하는 데 사용합니다.
void clear_input_buffer(void)
{
    int c;
    while (((c = getchar()) != '\n') && (c != EOF))
    {
        ; // 문자를 읽고 버립니다.
    }
}

int main(void)
{
    // 변수 선언
    char str1[100];
    char str2[100];
    char copy[100];
    char sentence[200];
    char temp[200];

    char* pos;
    char ch;

    char* p_str1 = str1;
    char* p_str2 = str2;
    char* p_copy = copy;
    char* p_sentence = sentence;
    char* p_temp = temp;

    // 문자열 입력
    printf("Enter first string (no spaces): ");
    scanf("%99s", p_str1);

    printf("Enter second string (no spaces): ");
    scanf("%99s", p_str2);

    // clear_input_buffer() 함수 사용 이유
    
    // scanf("%99s", ...) 호출 후, Enter 키를 눌러 입력된 개행 문자('\n')가 
    // 입력 버퍼에 남아있게 됩니다.
    // 이 개행 문자를 제거하지 않으면, 다음 fgets() 호출 시 개행 문자가 바로 읽혀져서
    // 사용자로부터 원하는 문장을 입력받지 못하고 넘어가는 문제가 발생합니다.
    // clear_input_buffer() 함수를 호출하여 버퍼를 비워주면 이 문제를 해결할 수 있습니다.
    clear_input_buffer();

    printf("\n--- Printed strings (using puts) ---\n");
    puts(p_str1);
    puts(p_str2);

    // 문장 입력
    printf("\nEnter one sentence (can include spaces): ");
    fgets(p_sentence, sizeof(sentence), stdin);
    printf("\nYou entered (sentence) = ");
    puts(p_sentence);

    // --- 문자열 함수 실습 시작 ---

    // strlen practice
    printf("\n--- strlen practice ---\n");
    printf("Length of str1: %zu\n", strlen(p_str1));
    printf("Length of str2: %zu\n", strlen(p_str2));
    // 이 부분은 **문자열의 길이를 구하는** 부분입니다. 
    // strlen 함수는 문자열의 끝을 나타내는 널 문자('\0')를 제외한 문자열의 길이를 반환합니다.

    // Practice #1: strcpy
    printf("\n--- Practice #1: strcpy ---\n");
    strcpy(p_copy, p_str1);
    printf("copy = ");
    puts(p_copy);
    // 이 부분은 **문자열을 복사하는** 부분입니다. 
    // strcpy 함수는 두 번째 인자의 문자열을 첫 번째 인자의 문자열로 복사합니다.

    // Practice #2: strcat
    printf("\n--- Practice #2: strcat ---\n");
    if ((strlen(p_str1) + strlen(p_str2)) < sizeof(str1)) 
    {
        strcat(p_str1, p_str2);
        printf("After concatenation, str1 = ");
        puts(p_str1);
    }
    else 
    {
        printf("str1 buffer is too small; cannot perform strcat!\n");
    }
    // 이 부분은 **문자열을 이어 붙이는(연결하는)** 부분입니다.
    // strcat 함수는 두 번째 인자의 문자열을 첫 번째 인자의 문자열 끝에 연결합니다.
    // 연결하기 전에 버퍼 크기가 충분한지 확인하는 안전 코드가 포함되어 있습니다.

    // Practice #3: strcmp
    printf("\n--- Practice #3: strcmp ---\n");
    int cmp = strcmp(p_str1, p_str2);
    if (cmp == 0) 
    {
        printf("str1 and str2 are equal.\n");
    }
    else if (cmp < 0) 
    {
        printf("In lexicographical order, str1 comes before str2.\n");
    }
    else 
    { // cmp > 0
        printf("In lexicographical order, str1 comes after str2.\n");
    }
    // 이 부분은 **문자열을 비교하는** 부분입니다.
    // strcmp 함수는 두 문자열을 사전식(lexicographical)으로 비교하여, 
    // 같으면 0, str1이 str2보다 앞서면 음수, str1이 str2보다 뒤서면 양수를 반환합니다.

    // Practice #4: strchr
    printf("\n--- Practice #4: strchr ---\n");
    printf("\nEnter a character to search for: ");
    scanf(" %c", &ch); // %c 앞에 공백을 넣어 이전 입력의 잔여 개행 문자 등을 무시합니다.

    pos = strchr(p_str1, ch);

    if (pos != NULL) 
    {
        printf("'%c' is at index %ld (0-based) in str1.\n",
            ch, (long)(pos - p_str1));
    }
    else 
    {
        printf("'%c' is not found in str1.\n", ch);
    }
    // 이 부분은 **문자열 내에서 특정 문자를 찾는** 부분입니다.
    // strchr 함수는 문자열 p_str1에서 문자 ch가 처음 나타나는 위치를 가리키는 포인터를 반환합니다.

    // Practice #5: strstr
    printf("\n--- Practice #5: strstr ---\n");
    pos = strstr(p_sentence, p_str2);

    if (pos != NULL) 
    {
        printf("Found \"%s\" inside sentence.\n", p_str2);
        printf("Substring starting from the found position: ");
        puts(pos);
    }
    else 
    {
        printf("Could not find \"%s\" in sentence.\n", p_str2);
    }
    // 이 부분은 **문자열 내에서 특정 부분 문자열을 찾는** 부분입니다.
    // strstr 함수는 문자열 p_sentence에서 문자열 p_str2가 처음 나타나는 위치를 가리키는 포인터를 반환합니다.

    // Practice #6: strtok
    printf("\n--- Practice #6: strtok ---\n");
    printf("\n--- strtok practice: split sentence by spaces ---\n");

    // 왜 이 실습에서는 temp에 문자열을 복사하는가?
    // strtok 함수는 문자열을 분리하는 과정에서 원본 문자열(p_sentence) 내의 구분자(공백)를
    // 널 문자('\0')로 덮어써야 합니다. 즉, **원본 문자열을 파괴적으로 변경**합니다.
    // 원본 문장(p_sentence)을 보존해야 하는 경우, strtok를 호출하기 전에 
    // 사본(p_temp)에 복사하여 사본에 대해 작업을 수행해야 합니다.

    strcpy(p_temp, p_sentence);
    char* token = strtok(p_temp, " ");
    int i = 1;
    while (token != NULL) 
    {
        printf("Token %d: ", i++);
        puts(token);
        token = strtok(NULL, " ");
    }
    // 이 부분은 **문자열을 지정된 구분자(여기서는 공백)로 나누는(토큰화하는)** 부분입니다.
    // strtok 함수는 문자열을 토큰 단위로 분리하며, 분리된 토큰의 시작 주소를 반환합니다.
    // 첫 번째 호출에서 문자열을 전달하고, 이후에는 NULL을 전달하여 이전 문자열의 계속을 지시합니다.

    printf("\nProgram finished.\n");
    return 0;
}


