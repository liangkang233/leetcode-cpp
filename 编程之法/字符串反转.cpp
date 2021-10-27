// 输入一串句子单词内字符顺序不变，只以空格间隔(标点等价字符)反转输出
// 用cpp的cin很容易做到 此处用c试试三步法

#include <cstdio>
#include <cstring>

// std::reverse 的实现
void swap(char* temp, int start, int end)
{
    char a;
    while (start < end) {
        a = temp[start];
        temp[start++] = temp[end];
        temp[end--] = a; 
    }    
}

int main()
{
    int flag[1000]={0};
    char temp[1000] = {0};
    scanf("%[^\n]", temp);
    int j = 0, k = 0;

    for (int i = 0; i < strlen(temp); i++) {
        if (temp[i] == ' ') {
            flag[j++] = i;
        }
    }

    j = 0;
    while (flag[j] != 0) {
        swap(temp, k, flag[j] - 1);
        k = flag[j++] + 1;
    }
    swap(temp, k, strlen(temp) - 1);
    swap(temp, 0, strlen(temp) - 1);
    
    printf("%s\n", temp);
    return 0;
}