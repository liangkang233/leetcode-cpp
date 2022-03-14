#include <stdio.h>
#include <stdlib.h>
// 转换字符串 C
// atof, atoi, atol, atoll 
// 或者 strtod, strtof, strtol, strtol, strtoll, strtold strtoul, strtoull可以指定结束字符 (非浮点数还可设定转换进制)
// a代表char* 为c中字符串 其他的  注意这里的 f 转出来为double类型
// itoa ltoa  其他情况可以用 sprintf 或 snprintf 转字符串

int main () {
    char mytest[] = "0Xff mytest";
    char *ptr;
    int i = strtol(mytest, &ptr, 16);
    printf("%d, str:%s", i, ptr);
    return 0;
}