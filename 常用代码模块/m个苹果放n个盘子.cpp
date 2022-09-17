// https://blog.csdn.net/u013074465/article/details/45505279

/* 题目描述
放苹果问题：把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
（注：5,1,1和1,1,5是同一种分法）
解题分析：
设f(m,n) 为m个苹果，n个盘子的放法数目，则先对n作讨论，
当n>m：必定有n-m个盘子永远空着，去掉它们对摆放苹果方法数目不产生影响。即if(n>m) f(m,n) = f(m,m)　　当n<=m：不同的放法可以分成两类：
    1、有至少一个盘子空着，即相当于f(m,n) = f(m,n-1);
    2、所有盘子都有苹果，相当于可以从每个盘子中拿掉一个苹果，不影响不同放法的数目，即f(m,n) = f(m-n,n).而总的放苹果的放法数目等于两者的和，即 f(m,n) =f(m,n-1)+f(m-n,n) 

递归出口条件说明：

    当n=1时，所有苹果都必须放在一个盘子里，所以返回１；
    当m==0(没有苹果可放)时，定义为１种放法； */


#include <iostream>
#include <vector>
using namespace std;

// 递归法
int fun(int m,int n)    // m个苹果放在n个盘子中共有几种方法
{
    if(m==0||n==1)      // 因为我们总是让m>=n来求解的，所以m-n>=0,所以让m=0时候结束，如果改为m=1，
        return 1;       // 则可能出现m-n=0的情况从而不能得到正确解    
    if(n>m)
        return fun(m,m);
    else
        return fun(m,n-1)+fun(m-n,n);
}

int main() {
	int apple, plate;
	cin >> apple >> plate;
	if (apple < 0 || apple > 10 || plate < 1 || plate > 10) {
		cout << -1 << endl;
		return -1;
	}
	vector<vector<int> > ivec(11, vector<int>(11, 0));
	for (int i = 0; i < 11; i++) {
		ivec[0][i] = 1;
		ivec[i][1] = 1;
	}
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			if (j <= i)
				ivec[i][j] = ivec[i][j - 1] + ivec[i - j][j];
			else
				ivec[i][j] = ivec[i][i];
		}
	}
 
 
	cout << ivec[apple][plate] << endl;
	return 0;
}