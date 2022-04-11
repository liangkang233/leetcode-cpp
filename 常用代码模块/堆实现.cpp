// 堆排序
// 父节点: i,   子节点: 2i+1 2i+2
// 子节点: i,   父节点: (i-1)/2
// 对一个节点做heapify的时候，必须保证它的所有子树都已经是堆。  
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}
void max_heapify(int arr[], int start, int end) {
    // 建立父節點指標和子節點指標
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 若子節點指標在範圍內才做比較
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(int arr[], int len) {
    int i;
    // 初始化建堆，i從最後一個父節點開始調整
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 先將第一個元素和已排好元素前一位做交換，再重新調整，直到排序完畢
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}





#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// 自实现大根堆 父节点i 左子节点 2i+1 右子节点 2i+2
void maxtoheap(vector<int>& nums, int i, int len) {
    while (2*i+1 < len) {
        int son = 2*i+1;
        if(2*i+2 < len && nums[2*i+2] > nums[2*i+1])
            son++;
        if(nums[son] > nums[i]) {
            swap(nums[son], nums[i]);
            i = son;
        }
        else
            break;
    }
}

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() <= 2)
            return -1;
        int len = nums.size();
        for (int i = nums.size()/2-1; i >= 0; i--)
            maxtoheap(nums, i, len);
        for (int i = nums.size()-1; i > 0; i--) {
            swap(nums[0], nums[i]);
            maxtoheap(nums, 0, i);
        }
        for (auto &&i : nums)
            cout << i << " ";
        cout << endl; 
    }
};

int main () {
    vector<int> test{1,23,5,67523,23,574,2,3358,6554,687,1,6776,8,654};
    Solution().majorityElement(test);
    return 0;
}