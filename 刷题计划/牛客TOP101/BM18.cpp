// https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=295&tqId=23256&ru=%2Fpractice%2Fd3df40bd23594118b57554129cadf47b&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i = 0, j = array[0].size() - 1;
        while (i < array.size() && j >= 0) {
            if(array[i][j] == target) {
                return true;
            } else if(array[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};