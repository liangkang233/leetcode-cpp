// https://www.nowcoder.com/practice/89865d4375634fc484f3a24b7fe65665?tpId=295&tqId=658&ru=%2Fpractice%2Fc3120c1c1bc44ad986259c0cf0f0b80e&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for (int i = m-1, j = n-1, index = m+n-1; index >= 0; index--) {
            int a1 = i >= 0 ? A[i] : INT_MIN, a2 = j >= 0 ? B[j] : INT_MIN;
            if(a1 >= a2) {
                A[index] = a1;
                i--;
            } else {
                A[index] = a2;
                j--;
            }
        }
    }
};