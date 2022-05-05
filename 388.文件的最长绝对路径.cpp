/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

#include <stack>
#include <iostream>
using namespace std;

// @lc code=start
// 路径中包含 . 代表是文件   等待二刷
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        stack<int> st;

        while (pos < n) {
            /* 检测当前文件的深度 */
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                pos++;
                depth++;
            }
            /* 统计当前文件名的长度 */   
            int len = 0; 
            bool isFile = false;     
            while (pos < n && input[pos] != '\n') {
                if (input[pos] == '.')
                    isFile = true;
                len++;
                pos++;
            }
            /* 跳过换行符 */
            pos++;
            while (st.size() >= depth)
                st.pop();
            if (!st.empty())
                len += st.top() + 1;
            if (isFile)
                ans = max(ans, len);
            else {
                st.emplace(len);
            }
        }
        return ans;
    }
};
// @lc code=end
// "dir"\n
// "dir\n\tsubdir123\n\tsubdir2\n\t\tfile.ext"  // subdir123 为空文件夹
// "dir\n\tsubdir123\n\tsubdir2"  // 全是空文件夹
// "file\nlongfile.txt\n\tfile2\n\t\ttest.txt"
// "file1.txt\nfile2.txt\nlongfile.txt\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"



// 题目逻辑整错了 可以只是空文件名 而不是文件
typedef pair<string, int> pi;
class Solution {
public:
    int lengthLongestPath(string input) {
        int ans = 0, len = input.size(), i = 0, j = 0;
        stack <pi> st; // st 存储当前遍历字符串 及总路径长度
        while (i < len && input[i++] != '\n');
        string temp = input.substr(0, i-1); // 当不存在子路径时，st存储的根路径会少一个
        st.push(make_pair(temp, temp.size())); // 只有初始文件夹 长度不计入 ans
        for (; i < len; i++) { // 进入循环时 imput[i] 在 '\n' 右侧
            if(input[i] != '\t') { // 为根目录 下文件 其长度即为 文件名长度 不计入栈中
                j = i;
                for (; i < len && input[i] != '\n'; i++); // 取出路径名 注意到字串到结尾 i指向\n或结尾
                ans = max(ans, i-j);
            }
            else {
                int count = 0; // 记录 /t 个数
                for (; input[i] == '\t'; i++)
                    count++;
                j = i;
                for (; i < len && input[i] != '\n'; i++); // 取出路径名 注意到字串到结尾 i指向\n或结尾
                while (st.size() > count) st.pop();
                temp = input.substr(j, i-j);
                st.push(make_pair(temp, temp.size() + 1 + st.top().second));
                ans = max(st.top().second, ans);
            }
        }
        return ans;
    }
};