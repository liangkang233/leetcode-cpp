/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// KMP 应用
// 应该结合题中 所有子串长度相等的条件
// 直接用单个字符的kmp会超时 需要优化为 以子串长度为最小单位进行kmp
// @lc code=start

// 此为滑动窗口做法
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty()||words.empty())return {};
        vector<int> result;
        //单词数组中的单词的大小，个数，以及总长度
        int one_word = words[0].size(), word_num = words.size(), all_len = one_word*word_num;
        if(all_len > s.size()) return {};
        unordered_map<string,int> m1; //建立单词->单词个数的映射
        for(const auto& w:words)    m1[w]++;
        
        for(int i = 0; i < one_word ; ++i) {    // 左界初始值只要 one_word 就足够
            int left=i, right=i, count=0;       //left和rigth表示窗口的左右边界，count用来统计匹配的单词个数
            unordered_map<string,int>m2;
            while(right + one_word<=s.size()) {  //开始滑动窗口
                string w = s.substr(right,one_word);
                right += one_word;
                if(m1.count(w)==0){ //此单词不在words中，表示匹配不成功,然后重置单词个数、窗口边界、以及m2
                    count=0;
                    left=right;
                    m2.clear();
                } else{             //该单词匹配成功，添加到m2中
                    m2[w]++;
                    count++;    
                    while(m2.at(w)>m1.at(w)) { // 同一单词匹配次数过多，需要缩小窗口，也就是left右移
                        string t_w=s.substr(left,one_word);
                        count--;
                        m2[t_w]--;
                        left+=one_word;
                    }
                    if(count==word_num) result.push_back(left);
                }
            }
        }
        return result;
    }
};
// @lc code=end
// "barfoofoobarthefoobarman"\n["bar","foo","the"]\n
// "abvbabvbabvbbahbvhbahgbabsjhdvbhabjhvbhabvhdbvajhbvjhabjhvb"\n["a","v","b"]\n
// "aaaaaaaaaaaaaa"\n["aa","aa"]\n
// "abababab"\n["a","b", "a"]\n
// "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel"\n["dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"]\n

// 双指针最简洁写法 效果一般
vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> res;
	unordered_map<string, int> keyMapCount, keyMapCountTemp;
	int len = words[0].size(), totalLen = len * words.size();
	for (auto it : words) keyMapCount[it]++;
	for (int i = 0; i < s.size() - totalLen + 1; i++) {
		int j = i;
		keyMapCountTemp = keyMapCount;
		for (; j < i + totalLen; j += len) {
			string temp = s.substr(j, len);
			if (keyMapCountTemp[temp] == 0) break;
			keyMapCountTemp[temp]--;
		}
		if (j == i + totalLen) res.push_back(i);
	}
	return res;
}

// 会超时 放弃!
/*
class Solution {
public:
    // 标准kmp改写
    void kmp(const string& s, const string& temp, vector<int>& ans) {
        vector<int> next(temp.size(), -1);
        for (int i = -1, j = 1; j < temp.size(); j++) {
            while (i!=-1 && temp[i+1]!=temp[j])
                i = next[i];
            if(temp[i+1]==temp[j])
                i++;
            next[j] = i;
        }
        for (int i = -1, j = 0; j < s.size(); j++) {
            while (i!=-1 && temp[i+1]!=s[j])
                i = next[i];
            if(temp[i+1]==s[j])
                i++;
            if(i == temp.size()-1) {
                ans.push_back(j-i);
                cout << j-i << " " << i << " ";
                // 匹配成功后继续遍历 让i变为next映射值  KMP关键修改处！
                i = next[i];
                cout << "new i is " << i << endl;
            }
        }
    }
    void mydfs(vector<string>& words, unordered_set<string>& ms, int index, string temp) { // 递归出所有字符串组合
        if(index == words.size()) {
            ms.insert(temp);
        } else {
            for (int j = index; j < words.size(); j++) {
                swap(words[j], words[index]);
                mydfs(words, ms, index + 1, temp + words[index]);
                swap(words[j], words[index]);
            }
        }
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_set<string> ms;
        mydfs(words, ms, 0, "");
        for (const string& i : ms) {
            cout << i << endl;
            kmp(s, i, ans);
        }
        return ans;
    }
}; 
*/

// 二刷 滑动窗口
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> mp, temp;
        int n = words[0].size(), L = words.size();
        auto myfun = [& temp]() {
            for(auto && i : temp) {
                if(i.second > 0)
                    return false;
            }
            return true;
        };
        if(s.size() < L*n) return ans;
        for (int i = 0; i < L; i++) mp[words[i]]++;
        for (int i = 0; i < n; i++) { // i 代表初始索引
            int l = i, r = i;
            temp = mp;
            while (r <= s.size()-n){
                string now = s.substr(r, n);
                temp[now]--;
                while (temp[now] < 0) { // 缩短左界
                    string ss = s.substr(l, n);
                    temp[ss]++;
                    l += n;
                }
                r += n;
                if(myfun())
                    ans.push_back(l);
            }
        }
        return ans;
    }
};