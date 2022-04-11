/*
 * meituan-014. 小团的 AB 队
 *
 * https://leetcode-cn.com/problems/LMkFuT/
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 这题出的可以， 没有 不清晰的题意 和 傻X的io说明
// 数学公式推导 结论为 https://leetcode-cn.com/problems/LMkFuT/solution/onlogngong-shi-fen-xi-by-boille-fmoo/
// x==y 时 综合实力为定值 输出最小字典序 AAA...BBB...
// x>y 时 A队的取值越小越好

typedef pair<int, int> pi;
int main () 
{
    int x, y;
    cin >> x >> y;
    vector<pi> nums(x+y);
    for (int i = 0; i < x+y; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }
    string ans(x+y, 'A'); // 如果存在多种答案，则输出字典序最小的字符串。 即优先A 再B
    if(x==y) {
        for (int i = x; i < 2*x; i++)
            ans[i] = 'B';
    }
    else {
        sort(nums.begin(), nums.end(), [](const pi&a, const pi&b){return a.first < b.first;});
        // for(auto && i : nums) 
        //     cout << i.second << " ";
        // cout << endl;
        char temp = 'A', temp1 = 'B'; // 默认认为 X > Y 先排x个A y个B 否则先排y个B x个A
        if(x < y) {
            temp = 'B', temp1 = 'A';
            swap(x, y);
        }
        for (int i = 0; i < x; i++)
            ans[nums[i].second] = temp;
        for (int i = x; i < x+y; i++)
            ans[nums[i].second] = temp1;
    }
    cout << ans;
    return 0;
}


/* 输入：
- 输入第一行包含两个正整数x，y，分别表示 AB 队的人数。
- 输入第二行包含 x+y 个正整数，中间用空格隔开，第i个数字表示第i个人的实力值，
- 每个人的实力值不会超过20000，保证任意两个人都不会有相同的实力值。 1 <= x, y <= 20000
    
输出：
- 输出包含一个长度为 x+y 的字符串，每个字符是 'A'或 'B'，表示某人应该被分在 A 或 B 队。
- 如果存在多种答案，则输出字典序最小的字符串。

输入：
4 4
5 6 4 2 3 8 1 7
输出：AAAABBBB */