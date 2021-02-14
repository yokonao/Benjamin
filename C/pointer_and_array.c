#include <stdio.h>

int main()
{
    char *s_pointer = "hoge";
    char s_array[] = "hoge";

    printf("sizeof: %d\n", (int)sizeof(s_pointer)); // 8
    printf("sizeof: %d\n", (int)sizeof(s_array));   // 5 charのサイズ(1)×要素数(5)

    printf("%c\n", *s_pointer); // h
    s_pointer++;
    printf("%c\n", *s_pointer); // o
    s_pointer += 2;
    printf("%c\n", *s_pointer); // e

    printf("%c\n", s_array[0]); // h
    printf("%c\n", s_pointer[3]); // e
    return 0;
}
