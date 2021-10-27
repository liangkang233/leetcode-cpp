#include <iostream>
#include <iterator>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ʹ�������±�����¼
    int lengthOfLongestSubstring(string s) {
        int head = 0, maxnum = 0, num = 0, len = s.size();
        char myset[127] = { 0 };
        for (int i = 0; i < len; i++) {
            if (myset[s[i]]) { // ����ʧ�ܣ�˵�����ظ�ֵ
                // ������ڼ�¼���ֵ����¡����£���ɾ������ͷ����
                if (num > maxnum)
                    maxnum = num;
                while (s[head] != s[i])
                    myset[s[head++]]--;
                num = i - head;
                head++;
            }
            else {
                num++;
                myset[s[i]]++;
            }
        }
        return num > maxnum ? num : maxnum; //��ֹmax��Ĭ��ֵ,����û����
    }
};


int main()
{
    Solution sol;
    string a = "pwwkew", b = ".*abc";
    //vector<int> nums = { 4,5,6,7,0,1,2 };
    vector<int> nums = { 8,9,2,3,4 };
    int ans = sol.lengthOfLongestSubstring(a);
    cout << ans;

    return 0;
}