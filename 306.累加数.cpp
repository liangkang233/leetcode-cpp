/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start

class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<long double>tmp;
        return dfs(num,tmp);
    }
    bool dfs(string num,vector<long double> tmp){
        int n = tmp.size();
        if(n>=3 && tmp[n-1] != tmp[n-2]+tmp[n-3]) 
            return false;
        if(num.size()==0 && n>=3) 
            return true;
        for(int i = 0;i<num.size();++i){
            string cur = num.substr(0,i+1);
            if(cur[0]=='0' && cur.size()!=1)
                continue;
            tmp.push_back(stold(cur)); 
            // stold：解析str，将其内容解释为浮点数，该浮点数作为long double
            if(dfs(num.substr(i+1),tmp)) 
                return true;
            tmp.pop_back();
        }
        return false;
    }
};
// @lc code=end

class Solution {
public:
    string num;
    bool mydfs(int start, long long n1, long long n2) {
        if (start >= num.size())
            return true;
        if(n1 < 0 || n2 < 0) { //设定初始n1 n2 进行递归回溯
            if(num[start] == '0') // 首字为0 该数必是0
                return n1 < 0 ? mydfs(start+1, 0, n2) : mydfs(start+1, n1, 0);
            long long temp = 0;
            int maxn = n1 < 0 ? num.size()-2 : num.size()-1;
            for (int i = start; i < min(maxn, start+17); i++){
                temp = 10 * temp + num[i] - '0';
                if(n1 < 0) {
                    if(mydfs(i+1, temp, n2))
                        return true;                    
                }
                else {
                    if(mydfs(i+1, n1, temp))
                        return true;
                }
            }
        }
        else if(num[start] == '0') //递归确定n3时 首字为0 该数必是0
            return n1+n2 > 0 ? false : mydfs(start+1, 0, 0);
        else { //递归temp3 n1 n2确定 之后数据应唯一 无需回溯
            long long temp3 = 0;
            for (int i = start; i < num.size(); i++) {
                temp3 = 10 * temp3 + num[i] - '0';
                if(temp3 < n1 + n2)
                    continue;
                else if(temp3 > n1 + n2)
                    break;
                return mydfs(i+1, n2, temp3); //进入下一次递归
            }
        }
        return false;
    }
    // 如何处理输入过大的整数 先用long试试 题目中num.size[1,35]
    // 所以某个数最大位数为17 小于LLONG_MAX (9223372036854775807 i64 19位数)
    // 注意点 后面累加的数不能出现首位0 不代表不能为0 例如 "011" "000" "0000000" 合法且正确
    // 输入数字个数居然可以为1 没注意到
    bool isAdditiveNumber(string num) {
        if(num.size() < 3)
            return false;
        this->num = num;
        return mydfs(0, -1, -1);
    }
};

