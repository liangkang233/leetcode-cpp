/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        for (int i = 0, j = 0; i < firstList.size() && j < secondList.size(); ) {
            if(firstList[i][0] > secondList[j][1])
                j++;
            else if(firstList[i][1] < secondList[j][0])
                i++;
            else { //有交集 删去使用部分后 继续遍历
                int a = max(firstList[i][0], secondList[j][0]), b = min(firstList[i][1], secondList[j][1]);
                ans.push_back(vector<int>{a, b});
                if(firstList[i][1] == b) { // first区间消除, second区间减少
                    i++;
                    secondList[j][0] = b; // 不必减一,因为first下一区间头必当大于b 不会出现重复的b
                }
                else {
                    j++;
                    firstList[i][0] = b;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

// [[1,10]]\n[[2,3],[4,5]]\n
// []\n[[2,3],[4,5]]\n
// [[1,7]]\n[[3,10]]\n

/* 
class Solution {
  public int[][] intervalIntersection(int[][] A, int[][] B) {
    List<int[]> ans = new ArrayList();
    int i = 0, j = 0;

    while (i < A.length && j < B.length) {
      // Let's check if A[i] intersects B[j].
      // lo - the startpoint of the intersection
      // hi - the endpoint of the intersection
      int lo = Math.max(A[i][0], B[j][0]);
      int hi = Math.min(A[i][1], B[j][1]);
      if (lo <= hi)
        ans.add(new int[]{lo, hi});

      // Remove the interval with the smallest endpoint
      if (A[i][1] < B[j][1])
        i++;
      else
        j++;
    }

    return ans.toArray(new int[ans.size()][]);
  }
} 
*/