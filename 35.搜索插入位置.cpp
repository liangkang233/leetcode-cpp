/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        if (target <= nums[0])
            return 0;
        while (start < end) {
            int mid = (start+end) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                start = mid+1;
            else
                end = mid;
        }
        return nums[start]<target ? start+1 : start;
    }
};
// @lc code=end


// 这个标准二分的改版 有效求出插入位置 范围为 0-size 会超出下标范围 
// 效果和 lower_bound 一样
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] < target)
                l = mid+1;
            else 
                r = mid-1;
        }
        return l;
    }
};


// 衍生 std::lower_bound 的类似实现 寻找第一个大于等于指定num的下标 不会超出下标范围

// last 初始值 = size时 就和 lower_bound 一样 超出范围会返回 end下标
int mylower_bound(int* array ,int size,int key){
	int first = 0, middle ,last = size-1;
	while(first<last){
		middle = (first+last) >> 1;
		if(array[middle] <key ) //当middle小于要找的位置 ， first +1 也不会超过key的位置，最多相同
			 first = middle + 1;
 		else
			last = middle ; //middle有可能等于要找的位置 ， last = middle ， 用first不断逼近
		
	}
	return first;
}

int myupper_bound(int* array ,int size,int key){
	int first = 0, middle ,last = size-1;
	while(first<last){
		middle = (first+last) >> 1;
		if(array[middle] >key ) //此时的middle一定大于要找的位置。用first不断逼近
			last = middle ;
		else
			first = middle +1; //当middle等于要找的位置， 我们记录first = middle+1
		
	}
	return first;
}

// 二刷
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            if(nums[mid] < target) {
                L = mid + 1;
            } else {
                R = mid;
            }
        }
        return L;
        // return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    }
};