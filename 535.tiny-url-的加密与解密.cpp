/*
 * @lc app=leetcode.cn id=535 lang=cpp
 *
 * [535] TinyURL 的加密与解密
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end


// 题目的意思是要将 长串编码记录map
class Solution {
private:
    unordered_map<int, string> dataBase;
    int id;
public:
    Solution() {
        id = 0;
    }

    string encode(string longUrl) {
        id++;
        dataBase[id] = longUrl;
        return string("http://tinyurl.com/") + to_string(id);
    }

    string decode(string shortUrl) {
        int p = shortUrl.rfind('/') + 1;
        int key = stoi(shortUrl.substr(p, int(shortUrl.size()) - p));
        return dataBase[key];
    }
};