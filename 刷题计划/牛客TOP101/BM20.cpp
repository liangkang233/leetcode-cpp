// https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=295&tqId=23260&ru=%2Fpractice%2Ffcf87540c4f347bcb4cf720b5b350c76&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 求 逆序数

// 法1 树状数组
class Solution {
    void add(vector<int>& record, int index, int val) {
        for (; index < record.size(); index += (index & -index)) {
            record[index] += val;
        }
    }
    int find(vector<int>& record, int index) {
        int sum = 0;
        for (; index > 0; index -= (index & -index)) {
            sum += record[index];
        }
        return sum;
    }
public:
    int InversePairs(vector<int> data) {
        int ans = 0;
        vector<int> record(1000002, 0); // 无语。牛客的测试案例 数据范围在 [0,10000000] 是题目的十倍，这里范围也要加个0
        for (int i = 0; i < data.size(); i++) {
            add(record, data[i] + 1, 1);
            // i+1 为当前个数,  find(record, data[i] + 1) 找出当前小于等于他的个数  相减即为逆序数
            ans = (ans + (i+1) - find(record, data[i] + 1)) % 1000000007;
        }
        return ans;
    }
};

// 法2 分治法
class Solution {
private:
    const int kmod = 1000000007;
public:
    int InversePairs(vector<int> data) {
        int ret = 0;
        merge_sort__(data, 0, data.size() - 1, ret);
        return ret;
    }


    void merge_sort__(vector<int> &arr, int l, int r, int &ret) {
        if (l >= r) {
            return;
        }

        int mid = l + ((r - l) >> 1);
        merge_sort__(arr, l, mid, ret);
        merge_sort__(arr, mid + 1, r, ret);
        merge__(arr, l, mid, r, ret);
    }

    void merge__(vector<int> &arr, int l, int mid, int r, int &ret) {
        vector<int> tmp(r - l + 1);
        int i = l, j = mid + 1, k = 0;

        // 如果两个区间为[4, 3] 和[1, 2] 那么逆序数为(4,1),(4,2),(3,1),(3,2)，
        // 同样的如果区间变为有序，比如[3,4] 和 [1,2]的结果是一样的，也就是说区间有序和无序结果是一样的。
        // 但是如果区间有序会有什么好处吗？当然，如果区间有序，比如[3,4] 和 [1,2]
        // 如果3 > 1, 显然3后面的所有数都是大于1， 这里为 4 > 1, 明白其中的奥秘了吧。所以我们可以在合并的时候利用这个规则。
        while (i <= mid && j <= r) {
            if (arr[i] > arr[j]) {
                tmp[k++] = arr[j++];
                ret += (mid - i + 1); // 奥妙之处
                ret %= kmod;
            }
            else {
                tmp[k++] = arr[i++];
            }
        }

        while (i <= mid) {
            tmp[k++] = arr[i++];
        }
        while (j <= r) {
            tmp[k++] = arr[j++];
        }

        for (k = 0, i = l; i <= r; ++i, ++k) {
            arr[i] = tmp[k];
        }
    }
};