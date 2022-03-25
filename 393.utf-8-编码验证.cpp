/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

#include <iostream>
#include <vector>
using namespace std;

// utf-8 易知
// 1字节 0 -> 7  位                0 -> 7F
// 2字节 8 -> 5+6=11 位            80 -> 7FF
// 3字节 12 -> 4+6+6=16 位         800 -> FFFF  
// 4字节 17 -> 3+6+6+6=21 位       10000 -> 10FFFF  注意不是1FFFFF 设计上限制

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        // int flag = 0, temp = 0; //表示该utf8 首字节后的字节长度 temp 表示累计临时值
        // int temp = 0; // temp 表示累计临时值
        for (int i = 0; i < data.size(); i++) {
            int flag = 0;
            if(data[i] < 0X80)
                continue;
            else if (data[i]>>3 == 0X1E)
                flag = 3;
            else if (data[i]>>4 == 0XE)
                flag = 2;
            else if (data[i]>>5 == 0X6)
                flag = 1;
            else
                return false;
            int temp = data[i] & 0X3F>>flag;
            int flag1 = flag;
            while (flag1 > 0) {
                flag1--;
                if(++i>=data.size() || (data[i]>>6 != 0X2))
                    return false;
                temp = (temp << 6) + (data[i] & 0X3F);
            }
            // 验算 unicode 码是否正常
            if(flag == 1 && temp < 0X80)
                return false;
            else if(flag == 2 && temp < 0x800)
                return false;
            else if(flag == 3 && (temp > 0X10FFFF || temp < 0X10000))
                return false;
        }
        return true;
    }
};
// @lc code=end

// [235, 140, 4]\n
// [240, 162, 138, 147]\n
// [194,155,231,184,185,246,176,131,161,222,174,227,162,134,241,154,168,185,218,178,229,187,139,246,178,187,139,204,146,225,148,179,245,139,172,134,193,156,233,131,154,240,166,188,190,216,150,230,145,144,240,167,140,163,221,190,238,168,139,241,154,159,164,199,170,224,173,140,244,182,143,134,206,181,227,172,141,241,146,159,170,202,134,230,142,163,244,172,140,191]\n

// 官方答案是错的 没有验算部分的内容
// 题例给的参数有误 例如 [192, 128] 0B11000000 10000000 其换算的unicode码不在二字节utf8编码范围内
class Solution {
public:
    static const int MASK1 = 1 << 7;
    static const int MASK2 = (1 << 7) + (1 << 6);

    bool isValid(int num) {
        return (num & MASK2) == MASK1;
    }

    int getBytes(int num) {
        if ((num & MASK1) == 0) {
            return 1;
        }
        int n = 0;
        int mask = MASK1;
        while ((num & mask) != 0) {
            n++;
            if (n > 4) {
                return -1;
            }
            mask >>= 1;
        }
        return n >= 2 ? n : -1;
    }

    bool validUtf8(vector<int>& data) {
        int m = data.size();
        int index = 0;
        while (index < m) {
            int num = data[index];
            int n = getBytes(num);
            if (n < 0 || index + n > m) {
                return false;
            }
            for (int i = 1; i < n; i++) {
                if (!isValid(data[index + i])) {
                    return false;
                }
            }
            index += n;
        }
        return true;
    }
};

// go utf8 库调用
// func validUtf8(data []int) bool {
// 	b := make([]byte, len(data))
// 	for i, v := range data {
// 		b[i] = byte(v)
// 	}
// 	return utf8.Valid(b)
// }