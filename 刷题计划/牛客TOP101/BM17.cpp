// https://www.nowcoder.com/practice/d3df40bd23594118b57554129cadf47b?tpId=295&tqId=663&ru=%2Fpractice%2Fc087914fae584da886a0091e877f2c79&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
		while (l < r) {
			mid = (l + r) / 2;
			if(nums[mid] < target)
				l = mid+1;
			else 
				r = mid;
		}
		return (l == nums.size() || nums[l] > target) ? -1 : l;
    }
};