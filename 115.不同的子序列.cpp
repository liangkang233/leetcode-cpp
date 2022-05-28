/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

// 与1143题很像 它是求两个字串最大匹配数目
// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int sl = s.size(), tl = t.size();
        if(sl < tl)
            return 0;
        vector<vector<int>> dp(sl+1, vector<int>(tl+1, 0));
        for (int i = 0; i <= sl; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= sl; i++) {
            for (int j = 1; j <= tl; j++) {
                dp[i][j] = dp[i-1][j]; // 删除下标 i-1 的匹配数
                if(s[i-1] == t[j-1] && (long long)dp[i][j] + dp[i-1][j-1] <= INT_MAX) // 排除越界的答案
                    dp[i][j] += dp[i-1][j-1]; // 同时删除 s t 尾字符的匹配数
            }
        }
        return dp[sl][tl];
    }
};
// @lc code=end
// "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo"\n"rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys"

// 官方解法是反过来的 dp[i][j] 代表 s字符串 i下标到尾部 t字符串 j下标到尾部
class Solution {
public:
    int numDistinct(string s, string t) {
        int sl = s.size(), tl = t.size();
        if(sl < tl)
            return 0;
        vector<vector<int>> dp(sl+1, vector<int>(tl+1, 0));
        for (int i = 0; i <= sl; i++)
            dp[i][tl] = 1;
        for (int i = sl-1; i >= 0; i--) {
            for (int j = tl-1; j >= 0; j--) {
                dp[i][j] = dp[i+1][j]; // 删除s首字符 下标i 的匹配数
                if(s[i] == t[j])
                    dp[i][j] += dp[i+1][j+1]; // 同时删除 s t 首字符的匹配数
            }
        }
        return dp[0][0];
    }
};

// 记忆化 去重 dfs 效果不错
class Solution {
private:
    unordered_map<int, int> mp; // 映射 x*10000 + y  记录s起点为x t起点为y t是s的子序列数个数
public:
    int dfs(const string& s, const string& t, const int& xy){
        if (mp.find(xy) != mp.end()) 
            return mp[xy];
        int x = xy / 10000 , y = xy % 10000;
        if (s.size() - x < t.size() - y)
            return 0;
        if (y == t.size())
            return 1;
        if (x == s.size()) 
            return 0;
        int res = dfs(s, t, xy + 10000); // x+1
        if (s[x] == t[y]) 
            res += dfs(s, t, xy + 10001); // x+1 y+1
        mp[xy] = res;
        return res; 
    }

    int numDistinct(string s, string t) {
        return dfs(s, t, 0);
    }
};

// 压缩到一维
class Solution {
public:
    int numDistinct(string s, string t) {
        int sl = s.size(), tl = t.size();
        if(sl < tl)
            return 0;
        vector<int> dp(tl+1, 0); 
        dp[0] = 1;
        for (int i = 1; i <= sl; i++) {
            vector<int> temp(dp); // temp
            for (int j = 1; j <= tl; j++) {
                if(s[i-1] == t[j-1] && (long long)temp[j] + dp[j-1] <= INT_MAX)
                    temp[j] += dp[j-1];
            }
            swap(temp, dp);
        }
        return dp[tl];
    }
};