# 文字列
## 目的
次の2つの共通点と違いを理解する
```
char *s_pointer = "hoge";
char s_array[] = "hoge";
```

## 文字列リテラルと配列の初期化

文字列リテラルは配列の初期化と同義である。
```
char s_array[] = "hoge";
```
は次と同値
```
char s_array[5] = {'h', 'o', 'g', 'e', '\0'}; // \0は終端を表す
```
つまり`s_array`は配列
## ポインタに配列を代入する

ポインターへの配列の代入は`先頭要素のポインタ代入`を意味する。
```
char[] array;
char *p;
p = array; // p = &array[0]と同義
```

`ポインタ=配列`と`ポインタ=&配列[0]`は全く一緒という意味になる。
つまり`s_pointer`はあくまでポインタである。

## 共通点
`ポインタ[i]`はi個先のポインタを返し、`配列[i]`はi+1番目の要素のポインタを返す。
すなわちポインタが配列の先頭要素を指しているとき、`ポインタ[i]`と`配列[i]`は全く同じ結果となる。

## 違い
ポインタはポインタ、配列は配列なので`sizeof`の結果は異なる。
```
char *s_pointer = "hoge";
char s_array[] = "hoge";

printf("sizeof: %d\n", sizeof(s_pointer)); // 8
printf("sizeof: %d\n", sizeof(s_array)); // 5 charのサイズ(1)×要素数(5)
```

また`s_pointer`はポインタであり、インクリメントによって指す対象を変更できる
```
printf("%c\n", *s_pointer); // h
s_pointer++;
printf("%c\n", *s_pointer); // o
s_pointer += 2;
printf("%c\n", *s_pointer); // e
```
`s_array`は配列であり、このような扱いは不可能
```
s_array++ // コンパイルエラー
```
