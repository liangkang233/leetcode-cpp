#include <iostream>     // std::cout
#include <algorithm>    // std::upper_bound
#include <vector>       // std::vector
using namespace std;

//以普通函数的方式定义查找规则 等价operator
bool mycomp(int i, int j) { return i > j; }
auto mycomp1 = [](int i, int j)->bool { return i > j; };

class mycomp2 {
public:
    bool operator()(const int& i, const int& j) {
        return i<j;
    }
};

int main() {
	int x = 1;
    int a[5] = { 1,2,3,4,5 };
    // 找不到对应值时会返回 vector.end() 若是输入指针则返回-1的地址
    int *p = upper_bound(a, a + 5, x);
    cout << "*p = " << *p << endl;
    p = lower_bound(a, a + 5, x);
    cout << "*p = " << *p << endl;

    // 以函数对象的形式定义查找规则 j为容器遍历值 i为输入的查找值
    // low是找出大于等于指定值，即找出i>=j才停 i是遍历值 函数内不成立跳出循环
	vector<int> myvector{ 1,2,3,4,5 };
    vector<int>::iterator iter = upper_bound(myvector.begin(), myvector.end(), x, mycomp2());
    if(iter==myvector.end())
    	cout << "error"<<endl;
    else
    	cout << "*iter = " << *iter;


    // uper找出大于指定值，即找出j>i才停 j是遍历值 函数内成立跳出循环
    // 以函数对象的形式定义查找规则 i为容器遍历值 j为输入的查找值
    vector<int>::iterator iter = upper_bound(myvector.begin(), myvector.end(), x, mycomp2());
    if(iter==myvector.end())
    	cout << "error"<<endl;
    else
    	cout << "*iter = " << *iter;
    return 0;
}

// 二维容器的 二分实现
// vector<vector<int>> myvector{{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
// auto row = [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];}; //第二个形参不设const会报错
// vector<vector<int>>::iterator iter = lower_bound(myvector.begin(), myvector.end(), vector<int>(1, x), row);//目标值一定要与遍历元素类型相同，此处转为一维容器



// lower_bound 自实现

// 这个标准二分的改版 等价求出 lower_bound
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

// 推荐做法
// 衍生 std::lower_bound 的类似实现 寻找大于等于指定num的第一个下标
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