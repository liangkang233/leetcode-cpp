/*
 * meituan-011. 搭配出售
 *
 * https://leetcode-cn.com/problems/0JzXQB/
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


typedef pair<int, int> pi;
int main () 
{
    int a, b, c, d, e, f, g;
    long long ans = 0;
    // 翻译翻译 共d个选择, 选 a b c 分别赚 e f g 求赚取方案的最大值
    // 注意 long long 溢出
    cin >> a >> b >> c >> d >> e >> f >> g;
    vector<pi> nums{pi{e, a}, pi{f, b}, pi{g, c}};
    sort(nums.begin(), nums.end(), [](pi& l, pi& r){return l.first > r.first;});
    for (int i = 0; i < 3; i++) {
        if(nums[i].second < d) {
            ans += (long long) nums[i].first * nums[i].second;
            d -= nums[i].second;
        }
        else {
            ans += (long long) nums[i].first * d;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}