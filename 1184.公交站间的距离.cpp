/*
 * @lc app=leetcode.cn id=1184 lang=cpp
 *
 * [1184] 公交站间的距离
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        // if(start == destination) return 0;
        int R = 0, L = 0, n = distance.size();
        for (int i = start; i % n != destination; i++) {
            R += distance[i % n];
        }
        for (int i = destination; i % n != start; i++) {
            L += distance[i % n];
        }
        return min(L, R);
    }
};
// @lc code=end
// [1,2,3,4]\n0\n1\n[1,2,3,4]\n0\n2\n[1,2,3,4]\n0\n3
// [7,10,1,12,11,14,5,0]\n7\n2