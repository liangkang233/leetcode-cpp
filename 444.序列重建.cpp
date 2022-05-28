/*
 * @lc app=leetcode.cn id=444 lang=cpp
 *
 * [444] 序列重建 https://leetcode.cn/problems/sequence-reconstruction/
 * 
 * 剑指 Offer II 115. 重建序列 https://leetcode.cn/problems/ur2n8P/
 */

#include <iostream>
#include <vector>
using namespace std;

// plus题
// 题目意思真的操蛋 案例也是
// 翻译一下就是 子序列是相对元素位置不变的 整合后 进行拓扑排序结果存在 且唯一为 org 返回 true
// 写起来有点繁琐 直接参考其他人写的
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {      
        int n=org.size();
        if(seqs.empty()) return false;
        // mp 是字典记录每个 1~n 在 org 中的下标，表示字典 mp[1~n]=0~n-1
        // 若 mp 唯一存在 必定 seqs 所有相邻节点都存在 以此来判断唯一
        vector<int>  mp(n+1,0),book(n,0);  
        for(int i=0;i<n;++i)mp[org[i]]=i;   // 这是一个字典下标，记录了org的字典序
        for(auto vec : seqs){
            if(vec[0]>n||vec[0]<1)return false;     // seqs超出org的范围的直接返回false
            for(int i=1;i<vec.size();++i){
                int a=vec[i-1],b=vec[i];
                if(b>n||b<1)return false;           // seqs超出org的范围的直接返回false
                if(mp[a]>=mp[b]) return false;      // seqs的顺序与字典序相反的直接返回false
                if(mp[a]==mp[b]+1){                 // 相邻序一定存在，记录在org中相邻的序
                    book[mp[a]]=1;
                }else if(mp[a]==mp[b]-1){
                    book[mp[b]]=1;
                }
                // 不是在map中相邻的不做book记录
            } 
        }
        for(int i=1;i<n;++i){                       // 检测字典序是否全部出现
            if(book[i])continue;
            return false;
        }
        return true;
    }
};