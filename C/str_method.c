#include <stdio.h>
#include <string.h>

void printstr(char *str)
{
    printf("文字列: \"%s\", 長さ: %lu\n", str, strlen(str));
}
// strlenの返り値はunsigned long
// 文字列のフォーマットは%s

int main()
{
    printstr("+");
    printstr(">=");

    // ポインタのサイズは8
    char *str1 = "+";
    char *str2 = ">=";
    // [2]を省略するとサイズが8となってしまう
    char *str_list[2] = {
        "a",
        "abc",
    };
    printf("%d\n", (int)sizeof(str1));
    printf("%d\n", (int)sizeof(str2));
    printf("%d\n", (int)sizeof(str_list));
    return 0;
}
