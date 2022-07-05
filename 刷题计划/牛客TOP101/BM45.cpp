// https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

// 单调栈 的变形 这里用双端队列做 方便删除无效的头
// 思路即为 当前节点 node 大于等于 单调栈尾部 不断删减小于它的值， 没必要记录这些小于它的值
// 滑动窗口遍历将删除该 node 之前 一定也会删除这些 栈底被删的元素 不影响最后结果
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& nums, int size) {
        vector<int> ans;
        deque<int> q; // 单调递减栈
        int i = 0, j = 0;
        for (; j < size; j++) { // 初始化队列
            while (!q.empty() && q.back() < nums[j]) {
                q.pop_back();
            } q.push_back(nums[j]);
        } ans.push_back(q.front());
        for (; j < nums.size(); i++, j++) {
            if(q.front() == nums[i])
                q.pop_front();
            while (!q.empty() && q.back() < nums[j]) {
                q.pop_back();
            } q.push_back(nums[j]);
            ans.push_back(q.front());
        }
        return ans;
    }
};