/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */
#include <iostream>
#include <string>
#include <list>
using namespace std;

// @lc code=start
class Solution {
public:
    // 首先找出一串未判断方向的骨牌
    // 若骨牌同向 此区间全为该方向
    // 若骨牌反向 此区间向中间倒
    // 若骨牌背向 此区间不变
    string pushDominoes(string dominoes) {
        int start = -1, end = -1;
        for (int i = 0; i < dominoes.size(); i++) {
            if(dominoes[i] == '.'){
                start = i;
                for (; i < dominoes.size() && dominoes[i] == '.'; i++)
                    end = i;
                // 找到一串 . 区间为 start 到 end
                cout << start << end << endl;
                char flag_l = start == 0 ? 'L' : dominoes[start-1];
                char flag_r = end == dominoes.size()-1 ? 'R' : dominoes[end+1];
                cout << flag_l << flag_r << endl;
                if(flag_l == flag_r) {
                    for (int j = start; j <= end; j++)
                        dominoes[j] = flag_l;
                }
                else if(flag_l == 'R' && flag_r=='L') {
                    while (start < end) {
                        dominoes[start++] = 'R';
                        dominoes[end--] = 'L';
                    }
                }
            }
        }
        return dominoes;
    }
};
// @lc code=end
// "RR.L"\n
// ".L.R...LR..L.."\n


/*  这样做会重复，例如"RR.L"不可 需要找出一串R的最右 和一串L的最左 写入初始的record
    // 找出所有有"动力"的骨牌序列链表头 遍历的对骨牌序列头做推动1格直到推动结束
    string pushDominoes(string dominoes) {
        vector<int> record;
        for (int i = 0; i < dominoes.size(); i++) {
            if(dominoes[i] != '.')
                record.push_back(i);
        }
        int len = record.size(); //for删除元素 会出错 维护len
        while (len > 0) {
            for (int i = 0; i < record.size(); i++) {
                if(record[i] == -1)
                    continue;
                if(dominoes[record[i]] == 'L') {
                    if(record[i]==0) {//向左到头了，删除该元素
                        record[i] = -1;
                        len--;
                    }
                    else if(dominoes[record[i]-1]=='R') {//遇到该牌向右，两边都删
                        record[i] = -1;
                        record[i-1] = -1;
                        len-=2;
                    }
                    else{
                        dominoes[record[i]-1] = 'L';
                        record[i]--;
                    }
                }
                else{
                    if(record[i]==dominoes.size()) {//向右到头了，删除该元素
                        record[i] = -1;
                        len--;
                    }
                    else if(dominoes[record[i]+1]=='L') {//遇到该牌向左，两边都删
                        record[i] = -1;
                        record[i+1] = -1;
                        len-=2;
                    }
                    else{
                        dominoes[record[i]+1] = 'R';
                        record[i]++;
                    }
                }
            }
        }
        return dominoes;
    } */