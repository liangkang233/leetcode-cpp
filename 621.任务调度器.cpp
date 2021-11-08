/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mymap['Z'+1] = {0};
        vector<int> nums;
        for(auto && i : tasks)
            mymap[i]++;
        for (auto && i : mymap) {
            if (i != 0)
                nums.push_back(i);
        }
        // if ( nums.size() > n)
        //     return tasks.size();
        sort(nums.begin(), nums.end(), greater<int>());
        int num = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[0])
                num++;
            else 
                break;
        }
        // cout << int(tasks.size()) << " " << (n+1)*(nums[0]-1)+num << endl;
        return max(int(tasks.size()), (n+1)*(nums[0]-1)+num);
    }
};
// @lc code=end

// 看看其他人的优秀解法 https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
    // 最后发现问题，没做下去
    int leastInterval(vector<char>& tasks, int n) {
        // 用map做记录，这里试试用数组是不是快些
        int mymap['Z'] = {0}, res = tasks.size();
        vector<int> nums;
        for(auto && i : tasks)
            mymap[i]++;
        for (auto && i : mymap) {
            if (i != 0)
                nums.push_back(i);
        }
        if ( nums.size() > n)
            return res;
        sort(nums.begin(), nums.end());

    }
