/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution {
public:
    // 找规律 只要出1必定为10 11, 0只能为0 一个数组确定唯一一个编码方式
    bool isOneBitCharacter(vector<int>& bits) {
        bool flag = true;
        for (int i = 0; i < bits.size(); i++) {
            if(bits[i]==1) {
                i++;
                flag = false;
            }
            else
                flag = true;
        }
        return flag;
    }
};
// @lc code=end

// [1,0,0]\n
// [1,1,1,0]\n

// 逆序遍历有时可以不用全部遍历
// 我们可以找到 bits 的倒数第二个 0 的位置，记作 i（不存在时定义为 -1），
// 那么 bits[i+1] 一定是一个字符的开头，且从 bits[i+1] 到 bits[n−2] 
// 的这 n-2-i 个比特均为 1，判断其奇偶性
    bool isOneBitCharacter(vector<int> &bits) {
        int n = bits.size(), i = n - 2;
        while (i >= 0 and bits[i]) {
            --i;
        }
        return (n - i) % 2 == 0;
    }