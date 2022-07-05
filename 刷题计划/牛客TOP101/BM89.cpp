// https://www.nowcoder.com/practice/69f4e5b7ad284a478777cb2a17fb5e6a?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            if(a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });
        if(!intervals.empty()) ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start <= ans.back().end) {
                ans.back().end = max(ans.back().end, intervals[i].end);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};