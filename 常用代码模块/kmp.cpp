#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 参考 https://leetcode-cn.com/problems/subtree-of-another-tree/solution/ling-yi-ge-shu-de-zi-shu-by-leetcode-solution/
// 和编程之法的思路一样 不过此处 next[i] 记录的是字符头部与当前包含i的尾部 相同字符数n-1  (i!=0)
// 编程之法 是 next[i] 记录的是字符头部与当前不包含i的尾部 数目 n                       (i!=0)
// 推荐用这个
class Solution {
public:
    int kmp(string a, string b) {
        vector<int> next(b.size(), -1);
        for (int i = -1, j = 1; j < int(b.size()); j++) {
            while (i!=-1 && b[i+1]!=b[j]) // 优化后续的查找
                i = next[i];
            if(b[j] == b[i+1])
                i++;
            next[j] = i;
        }
        for (int i = -1, j = 0; j < int(a.size()); j++) {
            while (i!=-1 && b[i+1]!=a[j])
                i = next[i];
            if(a[j] == b[i+1])
                i++;
            if(i == b.size() - 1)
                return j - i;
        }
        // for (auto &&i : next) // 查看 next 数组
        //     cout << i << " ";
        // cout << endl;
        return -1;
    }
};


int main ()
{
    string a = "asdhgkjhjghjkasdfaggajsdkljg";
    string b = "asdfagg";
    // string b = "aaadfhasd";
    Solution().kmp(a, b);
    return 0;
}