// https://www.nowcoder.com/practice/4edf6e6d01554870a12f218c94e8a299?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
        priority_queue<int, vector<int>, greater<int>> que; // 小根堆
        int ans = 0;
        sort(startEnd.begin(), startEnd.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        for (int i = 0; i < n; i++) {
            que.push(startEnd[i][1]);
            while (!que.empty() && que.top() <= startEnd[i][0]) { // end 可以等于 start 离谱 要注意是否为空
                que.pop(); // 该活动已经结束
            }
            ans = max((int)que.size(), ans);
        }
        return ans;
    }
};