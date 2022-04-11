/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// @lc code=start
// 两点之间确定一条直线 确定斜率 统计并记录到map中
// typedef pair<int, int> point;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        unordered_map<int, unordered_map<float, int>> mymap;
        // 二维哈希表 first为斜率(设斜率正负无穷为 FLT_MAX ) second 为一个哈希表
        // 第二层哈希的 first代表直线与y轴的交点  second为该直线上的个数
        for (int i = 1; i < points.size(); i++) {
            unordered_set<float> myset; // 记录 k 排除重复的直线
            for(int j = 0; j < i; j++) { // 遍历计算 当前点 与有记录的y轴交点 斜率
                float k = FLT_MAX;
                int y = points[i][1];
                if (points[i][0] != points[j][0]) // 计算 斜率k 若为平行y轴，k设为FLT_MAX y记录为x轴交点
                    k = (float)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                if(k != 0) // 计算直线与y轴交点
                    y = points[i][0] - points[i][1] / k;
                else if(k == FLT_MAX) 
                    y = points[i][0];
                if(myset.find(k) != myset.end())
                    continue;
                myset.insert(k);

                if(mymap.find(y) != mymap.end()) {
                    if(mymap[y].find(k) != mymap[y].end()) {
                        mymap[y][k]++;
                    }
                    else
                        mymap[y].insert(make_pair(k, 2));
                }
                else {
                    unordered_map<float, int> temp;
                    temp.insert(make_pair(k, 2));
                    mymap.insert(make_pair(y, temp));
                }
                ans = max(ans, mymap[y][k]);
            }
        }
        // for (auto &&i : mymap) {
        //     cout << i.first << " : ";
        //     for (auto &&j : i.second)
        //         cout << j.first << " " << j.second << endl;
        // }
        return ans;
    }
};
// @lc code=end
// [[1,1]]\n
// [[1,1],[1,2]]\n
// [[-6,-1],[3,1],[12,3]]\n
// [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]\n
// [[7,3],[19,19],[-16,3],[13,17],[-18,1],[-18,-17],[13,-3],[3,7],[-11,12],[7,19],[19,-12],[20,-18],[-16,-15],[-10,-15],[-16,-18],[-14,-1],[18,10],[-13,8],[7,-5],[-4,-9],[-11,2],[-9,-9],[-5,-16],[10,14],[-3,4],[1,-20],[2,16],[0,14],[-14,5],[15,-11],[3,11],[11,-10],[-1,-7],[16,7],[1,-11],[-8,-3],[1,-6],[19,7],[3,6],[-1,-2],[7,-3],[-6,-8],[7,1],[-15,12],[-17,9],[19,-9],[1,0],[9,-10],[6,20],[-12,-4],[-16,-17],[14,3],[0,-1],[-18,9],[-15,15],[-3,-15],[-5,20],[15,-14],[9,-17],[10,-14],[-7,-11],[14,9],[1,-1],[15,12],[-5,-1],[-17,-5],[15,-2],[-12,11],[19,-18],[8,7],[-5,-3],[-17,-1],[-18,13],[15,-3],[4,18],[-14,-15],[15,8],[-18,-12],[-15,19],[-9,16]]\n


// 官方题解
// 我们可以考虑枚举所有的点，假设直线经过该点时，该直线所能经过的最多的点数。
// 假设我们当前枚举到点 i，如果直线同时经过另外两个不同的点 j 和 k，那么可以发现点 i 和点 j 所连直线的斜率恰等于点 i 和点 k 所连直线的斜率。
// 于是我们可以统计其他所有点与点 i 所连直线的斜率，出现次数最多的斜率即为经过点数最多的直线的斜率，其经过的点数为该斜率出现的次数加一（点 i 自身也要被统计）。

// 用单个 32 位整型变量来表示这两个整数 形成的斜率
// 链接：https://leetcode-cn.com/problems/max-points-on-a-line/solution/zhi-xian-shang-zui-duo-de-dian-shu-by-le-tq8f/
// 在点的总数量小于等于 2 的情况下，我们总可以用一条直线将所有点串联，此时我们直接返回点的总数量即可；
// 当我们枚举到点 i 时，我们只需要考虑编号大于 i 的点到点 i 的斜率，因为如果直线同时经过编号小于点 i 的点 j，那么当我们枚举到 j 时就已经考虑过该直线了；
// 当我们找到一条直线经过了图中超过半数的点时，我们即可以确定该直线即为经过最多点的直线；
// 当我们枚举到点 i（假设编号从 0 开始）时，我们至多只能找到 n−i 个点共线。假设此前找到的共线的点的数量的最大值为 k，如果有 k ≥ n−i，
// 那么此时我们即可停止枚举，因为不可能再找到更大的答案了。
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (ret >= n - i || ret > n / 2) {
                break;
            }
            unordered_map<int, int> mp;
            for (int j = i + 1; j < n; j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0) {
                    y = 1;
                } else if (y == 0) {
                    x = 1;
                } else {
                    if (y < 0) {
                        x = -x;
                        y = -y;
                    }
                    int gcdXY = gcd(abs(x), abs(y));
                    x /= gcdXY, y /= gcdXY;
                }
                mp[y + x * 20001]++;
            }
            int maxn = 0;
            for (auto& [_, num] : mp) {
                maxn = max(maxn, num + 1);
            }
            ret = max(ret, maxn);
        }
        return ret;
    }
};
