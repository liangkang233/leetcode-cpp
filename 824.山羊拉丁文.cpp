/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans;
        int count = 0;
        char tag[127] = {0};
        tag['a']=1, tag['e']=1, tag['i']=1, tag['o']=1, tag['u']=1, tag['A']=1, tag['E']=1, tag['I']=1, tag['O']=1, tag['U']=1;
        for (int i = 0, j = 0; i <= sentence.size(); i++) {
            if(i < sentence.size() && sentence[i] != ' ')
                continue;
            count++;
            string temp = sentence.substr(j, i - j);
            // cout << temp << " size is " << temp.size() << endl;
            if(!tag[temp.front()]) {
                temp.push_back(temp.front());
                temp.erase(temp.begin());
            }
            ans += temp + "ma" + string(count, 'a') + ' ';
            j = i + 1;
        }
        ans.pop_back();
        return ans;
    }
};
// @lc code=end
// "The quick brown fox jumped over the lazy dog"\n