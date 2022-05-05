/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */

#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class NestedInteger {
    public:
    // Constructor initializes an empty nested list.
    NestedInteger();
    // Constructor initializes a single integer.
    NestedInteger(int value);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.front() != '[')
            return NestedInteger(stoi(s));
        stack<int> st; // 记录 [ 下标的栈
        NestedInteger ans = NestedInteger();
        int i = 1, j = 1; // 遍历时忽略 第一个 [
        for (; i < s.size() - 1; i++) {
            if(s[i] == ',') { // 普通元素直接通过
                // cout << j << " case1 " << i << " " << s.substr(j, i-j) << endl;
                int temp = stoi(s.substr(j, i-j));
                ans.add(NestedInteger(temp));
                j = i + 1;
            }
            if(s[i] == '[') { // 嵌套元素 递归 构建
                st.push(i); // 这个栈用的有点多此一举了
                while (!st.empty() && i < s.size()) {
                    i++;
                    j = st.top();
                    if(s[i] == '[')
                        st.push(i);
                    if(s[i] == ']')
                        st.pop();
                }
                // cout << j << " case2 " << i << " " << s.substr(j, i-j+1) << endl;
                ans.add(deserialize(s.substr(j, i-j+1)));
                if(i+1 < s.size()-1 && s[i+1]==',') // 删除一个嵌套元素后的 ','
                    ++i;
                j = i + 1;
            }
        }
        if(j < i) { // j不指向最后一个']'时 需要填充最后一个元素
            // cout << j << " case3 " << i << " " << s.substr(j, i-j-1) << endl;
            ans.add(NestedInteger(stoi(s.substr(j, i-j))));
        }
        return ans;
    }
};
// @lc code=end
// "[3]"\n
// "324"\n
// "[324]"\n
// "[324,32]"\n
// "[324,[23],3456]"\n
// "[123,[456,[789]]]"\n
// "[123,[456,[789],345]]"\n


// 一次遍历的栈  牛的
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger> st;
        int num = 0;
        bool negative = false;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '-') {
                negative = true;
            } else if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (c == '[') {
                st.emplace(NestedInteger());
            } else if (c == ',' || c == ']') {
                if (isdigit(s[i - 1])) {
                    if (negative) {
                        num *= -1;
                    }
                    st.top().add(NestedInteger(num));
                }
                num = 0;
                negative = false;
                if (c == ']' && st.size() > 1) {
                    NestedInteger ni = st.top();
                    st.pop();
                    st.top().add(ni);
                }
            }
        }
        return st.top();
    }
};
