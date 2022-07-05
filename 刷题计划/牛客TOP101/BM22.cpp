// https://www.nowcoder.com/practice/2b317e02f14247a49ffdbdba315459e7?tpId=295&tqId=1024572&ru=%2Fpractice%2F9f3231a991af4f55b95579b44b7a01ba&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串 
     * @param version2 string字符串 
     * @return int整型
     */
    int compare(string version1, string version2) {
        int i = 0, j = 0, a = 0, b = 0;
        while (a == b) {
            if(i >= version1.size() && j >= version2.size())
                return 0;
            a = 0; b = 0;
            for (; i < version1.size() && version1[i] != '.'; i++) {
                a = a * 10 + version1[i] - '0';
            } i++;
            for (; j < version2.size() && version2[j] != '.'; j++) {
                b = b * 10 + version2[j] - '0';
            } j++;
        }
        return a > b ? 1 : -1;
    }
};