#include <stdio.h>
#include <string.h>

void printstr(char *str)
{
    printf("文字列: \"%s\", 長さ: %lu\n", str, strlen(str));
}
// strlenの返り値はunsigned long
// 文字列のフォーマットは%s

void print_int(int d)
{
    printf("%d\n", d);
}

void experiment_strncomp()
{
    // 注意！strncmpは等しい（true）だと0が返ってくる
    print_int(strncmp("abc", "a", 1));  // 0
    print_int(strncmp("abc", "a", 2));  // 1
    print_int(strncmp("abc", "ab", 2)); // 0
    print_int(strncmp(">=", ">=", 2));  // 0

    // charのポインタをわたせば、その位置からn（第3引数）文字を探索してくれる
    char *p = "1>=0";
    print_int(strncmp(p, "1", 1));
    p++;
    print_int(strncmp(p, ">", 1));
    print_int(strncmp(p, ">=", 2));
    p += 2;
    print_int(strncmp(p, "0", 1));
}

int main()
{
    printstr("+");
    printstr(">=");
    experiment_strncomp();

    // ポインタのサイズは8
    char *str1 = "+";
    char *str2 = ">=";
    // [2]を省略するとサイズが8となってしまう
    char *str_list[2] = {
        "a",
        "abc",
    };
    print_int(sizeof(str1));     // 8
    print_int(sizeof(str2));     // 8
    print_int(sizeof(str_list)); // 16

    return 0;
}
