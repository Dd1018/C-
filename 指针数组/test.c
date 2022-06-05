#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
    char* lines[5] = {
        "COSC1283/1284",
        "Programming",
        "Techniques",
        "is",
        "great fun"
    };
    char* str1 = lines[1];
    char* str2 = *(lines + 3);
    char c1 = *(*(lines + 4) + 6);
    char c2 = (*lines + 5)[5];
    char c3 = *lines[0] + 2;
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("  c1 = %c\n", c1);
    printf("  c2 = %c\n", c2);
    printf("  c3 = %c\n", c3);
    return EXIT_SUCCESS;
}