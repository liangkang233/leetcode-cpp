/*
 * @lc app=leetcode.cn id=1353 lang=cpp
 *
 * [1353] 最多可以参加的会议数目
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;


// 贪心的思想，对于第 i 天，如果有若干的会议都可以在这一天开，
// 那么我们肯定是让 endDayendDay 小的会议先在这一天开才会使答案最优，
// 因为 endDayendDay 大的会议可选择的空间是比 endDayendDay 小的多的，
// 所以在满足条件的会议需要让 endDayendDay 小的先开。


// @lc code=start
class Solution {
public:
    // 使用优先队列找出endday最小的，一天天的叠加遍历测试是否可以处理会议。 思路和官方的题目一样
    struct date {
        int start, end;
        date(int i, int j):start(i),end(j){}
        bool operator> (const date& a) const {
            return end > a.end;
        }
    };
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<date, vector<date>, greater<date>> myqueue;
        auto com = [](const vector<int>& a, const vector<int>& b)->bool{return a[0] < b[0];} ;
        sort(events.begin(), events.end(), com);
        int ans = 0, day = 1, num = 0;
        while (num < events.size() || !myqueue.empty() ){          //判断会议是否全部处理过
            while (num < events.size() && events[num][0] <= day) { //队列中添加今天可以参加的会议
                myqueue.push(date(events[num][0], events[num][1]));
                num++;
            }
            while (!myqueue.empty() && myqueue.top().end < day) //删除已经无法参加的会议
                myqueue.pop();
            if (!myqueue.empty()) { //取出队列头，即截止日期最小的参加该会议
                ans++;
                myqueue.pop();
            }
            day++;
        }
        return ans;
    }
};
// @lc code=end

// 官方的遍历法 使用有序set multiset
// https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/solution/zui-duo-ke-yi-can-jia-de-hui-yi-shu-mu-by-leetcode/
class Solution0 {
public:
    #define N 100010
    #define MP make_pair
    multiset<pair<int,int> >S;  // 存放当前时间下可以开的会议，pair(endDay,i)  默认是endDay小的在multiset前面
    vector<int>in[N],out[N];    //in[i]表示第i天开始的会议，out[i]表示在第i天会议结束 
    int maxEvents(vector<vector<int>>& events) {
        int mx=0,cnt=0;
        for (auto x:events){        //相当于对events的时间进行了排序
            int l=x[0],r=x[1];
            mx=max(mx,r);
            in[l].push_back(cnt);
            out[r+1].push_back(cnt);
            cnt++;
        }
        int ans=0;
        for (int i=1;i<=mx;++i){
            for (auto x:in[i]) S.insert(MP(events[x][1],x));
            for (auto x:out[i]){
                auto it=S.find(MP(events[x][1],x));
                if (it!=S.end()) S.erase(it);
            }
            if (!S.empty()){
                S.erase(S.begin());
                ans++;
            }
        }
        return ans;
    }
};


// 理解错题意了，题中给的是范围而不是给的会议可用日期
class Solution1 {
public:
    int maxn; //最大会议数
    int dfs(vector<vector<int>>& events, unordered_set<int> myset, int level, int ans) { 
        //set不能传引用，使用引用会改变实参无法回溯
        int temp = ans;
        if(level == maxn)
            return ans;
        for (auto &&i : events[level]) {
            if (myset.find(i) == myset.end()) { //没有重复值才继续下去
                myset.insert(i);           
                temp = max(dfs(events, myset, level+1, ans+1), temp);
                myset.erase(i);
                // cout << temp << endl;
            }
        }
        //如果这次会议全部无效，跳过这次会议
        if (temp==ans)
            temp=dfs(events, myset, level+1, ans);
        
        return temp;
    }

    int maxEvents(vector<vector<int>>& events) {
        maxn = events.size();
        unordered_set<int> myset;
        return dfs(events, myset, 0, 0);
    }
};

