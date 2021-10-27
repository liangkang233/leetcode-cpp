#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
/* 
iostream处理控制台IO；
fstream处理命名文件IO；
stringstream完成内存string的IO。
类fstream和stringstream都是继承在类iostream的。
输入类都继承自istream，输出类都继承自ostream。
string流：sstream头文件定义了三个类型来支持内存IO，
这些类型可以向string写入数据，从string读取数据，就像string是一个IO流一样。 
将所有行数据打印出：

vector<string> res;
vector<vector<string>> result;
while (getline(myfile, temp)) {		//默认停止符\n
	stringstream slice(temp);
	string slices;
	while (slice >> slices) {		// 类似cin输入，将每行排除不可显字符 空格等字符输入容器，直到接收回车为止
		res.push_back(slices);
	}
	result.push_back(res);
	res.clear();
}
for (int i = 0; i < result.size(); i++) {	// 打印测试
	for (int j = 0; j < result[i].size(); j++) {
		cout << result[i][j]<<"\t";
		if (j == result[i].size() - 1) cout << endl;
	}
}
*/

// 自己写的跟官方的思路差不多，官方答案不用先找到最大临界值再二分 直接进行判断二分 
// 下面为官方答案，注意 边界 等于 问题
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) 
            return -1;
        else if (n == 1) 
            return nums[0] == target ? 0 : -1;

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;    // target判断是否为mid
            if (nums[0] <= nums[mid]) {             // 说明0到mid是升序
                if (nums[0] <= target && target < nums[mid])  // target在该升序中
                    r = mid - 1;
                else 
                    l = mid + 1;
            } 
            else {                                  // 说明mid到n-1是升序
                if (nums[mid] < target && target <= nums[n - 1])  // target在该升序中
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
        }
        return -1;
    }
};

// 导入文本至容器测试，将每一行的数据以空格为间隔输入一个字符容器，将所有行的数据输入
int main() 
{
    string temp;
	ifstream myfile("./date.txt");
    if( !myfile ) {
        cout << "open file fail!" << endl;
        return -1;
    }

	vector<vector<int>> ress;
	vector<int> res;
	vector<int> targets;
	while (getline(myfile, temp)) {		//默认停止符\n
		stringstream slices(temp);
		string slice;
		while (slices >> slice) {		// 类似cin输入，将每行排除不可显字符 空格等字符输入容器，直到接收回车为止
			res.push_back(stoi(slice));
			// stoi(int), stol(long), stof(float), stod(double) 
		}
		getline(myfile, temp);
		targets.push_back(stoi(temp));
		// for( auto rio : res)
		// 	cout << rio << endl;
		ress.push_back(res);
		res.clear();
	}
	myfile.close();

	Solution su;
	for (int i = 0; i < ress.size(); i++) {
		int ans = su.search(ress[i], targets[i]);
		cout << targets[i] << ' ' << ans <<endl;
	}
	
    return 0;
}
