#include <stdio.h>

int main() {
    printf("=== Char / String & Escapes ===\n");
    printf("Char : %c, code : %d\n", 'A', 65);
    printf("Message :\n");
    printf("%s\n\t%s\n", "First line","Indented second line");
    printf("%s\n", "Third line");
    printf("Quotes:%s\n", "\"double quotes\" and 'single quotes'");
    printf("%s\n", "Backslash : \\");
    printf("Average : [%8.2f]\n", 87.35f);

    return 0;
}