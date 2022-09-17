/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int index = 0;
        while(index < words.size()) {
            int count = 0, N = 0;
            string s(maxWidth, ' ');
            while(index < words.size() && count <= maxWidth) {
                N++;
                count += words[index++].size();
                if(N > 1) count++; // 这里的count包含字符间必须的间隔
            }
            int size, space = 1, L = 0; // L 代表需要多添加空格的节点数量
            if(count > maxWidth) {      // 删去会溢出的index 并计算空格
                N--;
                index--;
                count -= words[index].size() + 1;
                size = maxWidth - count + N-1; // 空格数量
                if(N > 1) {
                    space = size / (N-1);
                    L = size % (N-1); 
                }
            } else {} // index到达尾部 说明所有数据间隔只能为1  这里不做处理即可
            // cout << size << " " << space << " " << L << endl;
            for(int i = index - N, j = 0; i < index; i++) {
                copy(words[i].begin(), words[i].end(), s.begin()+j);
                j += words[i].size() + space;
                if(i - (index - N) < L)
                    j++;
            }
            ans.push_back(s);
        }
        return ans;
    }
};
// @lc code=end