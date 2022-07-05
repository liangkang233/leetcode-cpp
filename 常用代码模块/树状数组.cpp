// t数组为维护的树状数组
// lowbit function :  a & -a
int t[maxn];

void add(int x, int k)
{
    for(; x <= n; x += (x&-x) ) {
        t[x] += k;
    }
}

int ask(int x) 
{
    int ans;
    for (; i > 0; x -= (x&-x)) {
        ans += t[x]; 
    }
    return ans;
}

// 单点修改、单点查询
add(x, k);
ask(x) - ask(x-1);

// 单点修改，区间查询 
add(x, k);
ask(r) - ask(l-1);      // 区间[l,r]内

// 需要两个树状数组维护
// t1[]维护b[i]前缀和,t2[]维护i*b[i]前缀和
int t1[maxn], t2[maxn]];

void add1(int x, int k) {
    for(; x <= n; x += (x&-x) ) {
        t1[x] += k;
    }
}
int ask1(int x) {
    int ans;
    for (; i > 0; x -= (x&-x)) {
        ans += t1[x]; 
    }
    return ans;
}

void add2(int x, int k) {
    for(; x <= n; x += (x&-x) ) {
        t2[x] += k;
    }
}
int ask2(int x) {
    int ans;
    for (; i > 0; x -= (x&-x)) {
        ans += t2[x]; 
    }
    return ans;
}
// 区间修改，区间查询
// 在区间[l, r]修改
add1(l, d);     add1(r+1, -d);
add2(l, l*d);   add2(r+1, -(r+1)*d);

sum[r] - sum[l-1];   //即为下式
(r+1)*ask1[r] - ask2[r] + (l-1+1)*ask1[l-1] - ask2[l-1];


/* 问题描述
n 个小朋友站成一排。现在要把他们按身高从低到高的顺序排列，但是每次只能交换位置相邻的两个小朋友。
每个小朋友都有一个不高兴的程度。开始的时候，所有小朋友的不高兴程度都是0。
如果某个小朋友第一次被要求交换，则他的不高兴程度增加1，如果第二次要求他交换，则他的不高兴程度增加2（即不高兴程度为3），
依次类推。当要求某个小朋友第k次交换时，他的不高兴程度增加k。
请问，要让所有小朋友按从低到高排队，他们的不高兴程度之和最小是多少。
如果有两个小朋友身高一样，则他们谁站在谁前面是没有关系的。

输入格式
　　输入的第一行包含一个整数n，表示小朋友的个数。
　　第二行包含 n 个整数 H1 H2 … Hn，分别表示每个小朋友的身高。
输出格式
　　输出一行，包含一个整数，表示小朋友的不高兴程度和的最小值。
    样例输入
        3
        3 2 1
    样例输出
        9
样例说明
　　首先交换身高为3和2的小朋友，再交换身高为3和1的小朋友，再交换身高为2和1的小朋友，每个小朋友的不高兴程度都是3，总和为9。
数据规模和约定
　　对于10%的数据， 1<=n<=10；
　　对于30%的数据， 1<=n<=1000；
　　对于50%的数据， 1<=n<=10000；
　　对于100%的数据，1<=n<=100000，0<=Hi<=1000000。 */

// 用求逆序数的思想去做，定义前面的数大于当前数的个数为逆序数，
// 后面的数小于当前数的个数为逆序数2号，
// 小朋友的不高兴值 = 逆序数1 等差和 + 逆序数2 等差和
// 逆序数定义可知，一个数的逆序数是往前挪几次，相应的逆序数2号就是被后面的数挪动的次数，
// 如果是求交换次数，只需要求逆序数1 或 2 的累加即可
// 其实 左右遍历 逆序数和 一定是相同的，
// 只不过这里要累计的是不高兴值 是一个等差数列的n项和 所以只能逆序数的两个方向分开来求
// 使用树状数组来做 以 身高+1 为树状数组下标 这样遍历下去就只会统计到身高比它小的值
// https://www.lagou.com/lgeduarticle/508.html

#include <iostream>
#include <cstring>
using namespace std;

// 小朋友身高居然可以为0
// 由于树状数组结构设计无法向tree[0]存储值所以存树状值下标为身高值加1
// 堆空间申请返回的是单个元素的指针，切不可使用memset(tree, 0, sizeof(tree));
// 而是 memset(tree, 0, maxn * sizeof(int)); 同理传参也是如此

#define maxn 1000002

void add(int i, int k, int* tree)
{
    for (; i < maxn; i += (i & -i)) {
        tree[i] += k;
    }
}
int sum (int i, int *tree)
{
    int sum = 0;
    for (; i > 0; i -= (i & -i)) {
        sum += tree[i];
    }
    return sum;
}

int main()
{
    int N; 
    long long count = 0; 
    int* tree = new int[maxn];
    int* temp = new int[maxn]; 
    long long* num = new long long[maxn]; 
    memset(temp, 0, maxn * sizeof(int));
    memset(num, 0, maxn * sizeof(long long));
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> temp[i];
    
    // 从左往右 记录左边比它高的
    memset(tree, 0, maxn * sizeof(int));
    for (int j = 0; j < N; j++) {
        add(temp[j]+1 , 1, tree);
        num[j] = j+1 - sum(temp[j]+1, tree);
    }

    // 从右往左 记录右边比他矮的   
    memset(tree, 0, maxn * sizeof(int));
    for (int j = N-1; j >= 0; j--) {
        add(temp[j]+1, 1, tree);
        num[j] += sum(temp[j], tree);
    }
    
    for (int i = 0; i < N; i++) {
        count += num[i] * (num[i]+1) / 2;
    }
    
    delete[] tree;
    delete[] temp; 
    delete[] num;
    return 0;
}