#include <stdio.h>
#include <string.h>

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
    experiment_strncomp();
    return 0;
}
