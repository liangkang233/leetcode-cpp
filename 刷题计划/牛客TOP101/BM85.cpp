// https://www.nowcoder.com/practice/55fb3c68d08d46119f76ae2df7566880?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

// 这种傻口题有啥意义

class Solution {
public:
    /**
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */
    vector<string> split(string& IP, char k) {
        vector<string> v;
        int r = 0, l = 0;
        for (; r < IP.size(); r++) {
            if(IP[r] == k) {
                v.push_back(IP.substr(l, r-l));
                l = r+1;
            }
        } 
        if(l != 0 ) v.push_back(IP.substr(l, r-l));
         return v;
    }
    bool isipv4(string& IP) {
        vector<string> v = split(IP, '.');
        if(v.size() != 4) return false;
        for (int i = 0; i < 4; i++) {
            // cout << v[i] << endl;
            for(int j = 0; j < v[i].size(); j++) {
                if(!isdigit(v[i][j])) return false;
            }
            if(v[i].empty() || v[i].size() > 3)
                return false;
            if(v[i].size() == 2 && v[i][0]=='0')
                return false;
            if(v[i].size() == 3 && (v[i][0]=='0' || stoi(v[i]) >= 256))
                return false;
        }
        return true;
    }
    bool isipv6(string& IP) {
        vector<string> v = split(IP, ':');
        if(v.size() != 8) return false;
        for (int i = 0; i < 8; i++) {
            // cout << v[i] << endl;
            if(v[i] == "0") continue;
            if(v[i].size() != 4) return false;
            for (int j = 0; j < 4; j++) {
                if(v[i][j] > 'f' || (v[i][j] > 'F' && v[i][j] <= 'Z'))
                    return false;
            }
        }
        return true;
    }
    string solve(string IP) {        
        if(isipv6(IP)) return "IPv6";
        if(isipv4(IP)) return "IPv4";
        return "Neither";
    }
};