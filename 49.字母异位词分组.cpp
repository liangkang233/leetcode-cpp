/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> mymap; // 记录同一字母异位字符的 数组下标
        int index = 0;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(mymap.find(temp) != mymap.end()) {
                ans[mymap[temp]].push_back(strs[i]);
            }
            else {
                mymap.insert(make_pair(temp, index++));
                ans.push_back(vector<string>{strs[i]});
            }
        }
        return ans;
    }
};
// @lc code=end
// [""]
// ["adf","asa","asda","aased","ghha","aasdf","asfgs","aertt","a","aasdg","fga","ga","asdfa","ada","qwea","astga","dfga","daa","aewt","adfg","adfdg","asdf"]

// 官方的优化 将每个出现次数大于 0 的字母和出现次数按顺序拼接成一个带空格间隔的字符串，
// 作为哈希表的键

// 大佬的思路
// 利用hash的思想,将每个子串使用质数乘法进行hash,
// 只要两个字符串包含的字符与对应数量一致,hash结果则一致： 
// 例如: 'abc' = 2*3*4 'acb' = 2*4*3 然后通过哈希表Map将我们的答案保存。
// 复杂度分析： 时间复杂度O(mn) m为字符串平均长度,n为strs.length 空间复杂度O(mn) 
// 因为需要将结果保存到map中 代码

/*  js代码
var groupAnagrams = function (strs) {
    const n = strs.length;
    const ans = new Map();
    const prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103];
    const mod = 1e9 + 7;
    for (let i = 0; i < n; i++) {
        let hash = 1;
        for (let j = 0; j < strs[i].length; j++) {
            let num = strs[i].charCodeAt(j) - 97;
            hash = ((hash % mod) * (prime[num] % mod)) % mod;
        }
        if (!ans.get(hash)) ans.set(hash, []);
        ans.get(hash).push(strs[i]);
    }
    return [...ans.values()];
};
 */

// 二刷 感觉效果 不如 sort 字符串
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> mymap; // key为转换过来的键值 ans为对应下标
        auto toKey = [](const string& a) -> string {
            string key;
            int count[26] = {0};
            for(int i = 0; i < a.size(); i++)
                count[a[i]-'a']++;
            for (int i = 0; i < 26; i++) {
                if(count[i] > 0) {
                    key.push_back(i+'a');
                    key += to_string(count[i]);
                }
            }
            return key;
        };
        for (int i = 0; i < strs.size(); i++) {
            string key = toKey(strs[i]);
            if(mymap.find(key) == mymap.end()) {
                ans.push_back(vector<string>{strs[i]});
                mymap[key] = ans.size() - 1;
            }else {
                ans[mymap[key]].push_back(strs[i]);
            }
        }
        return ans;
    }
};